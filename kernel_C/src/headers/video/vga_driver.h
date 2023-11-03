#pragma once
#include "custom_std/io_manager.h"

// tailles du display initial
#define DISPLAY_WIDTH 80
#define DISPLAY_HEIGHT 25
#define DISPLAY_VGA_MAX DISPLAY_HEIGHT * DISPLAY_WIDTH

// quelque couleurs
#define GREEN_TXT 0x2
#define BLUE_TXT 0x1
#define WHITE_TXT 0xf

#define VGA_MEM_ADDR 0xb8000 // adresse d'ecriture VGA

// Quelque constances spécifiques au VGA
#define VGA_CTRL_REGISTER 0x3d4 // à activer pour changer la position du curseur
#define VGA_DATA_REGISTER 0x3d5 // adresse de départ pour écrire et lire dans le DATA register

/*  La position du curseur est en 16bit, chaque byte correspond à deux paramètres différents
*   Si la valeur VGA_OFFSET_LOW et fixé à VGA_CTRL_REGISTER alors alors le DATA_REGISTER va garder la valeur LOW (premier byte à partir de la droite)
    inversement si VGA_OFFSET_HIGH est fixé VGA_CTRL_REGISTER alors le data register prendra la valeur HIGH (second byte à partir de la droite)
*/
#define VGA_OFFSET_LOW 0x0f
#define VGA_OFFSET_HIGH 0x0e


// variable car le display pourra éventuellement changer de résolution
char VGA_WIDTH = DISPLAY_WIDTH;
char VGA_HEIGHT = DISPLAY_HEIGHT;




/// @brief défini la position du curseur
/// @param x 
/// @param y 
void set_cursor(int x, int y)
{
    uint16_t offset = x / 2 + y * VGA_WIDTH / 2; // divisé par deux car le VGA à deux bytes par cell
    
    port_byte_write(VGA_CTRL_REGISTER, VGA_OFFSET_LOW); // on prépare pour écrire sur le low byte
    port_byte_write(VGA_DATA_REGISTER, offset & 0xff); // on écrit le low

    port_byte_write(VGA_CTRL_REGISTER, VGA_OFFSET_HIGH); // on prépare pour set le high byte
    port_byte_write(VGA_DATA_REGISTER, (offset >> 8) & 0xff); // on écrit le high

}



/// @brief retourne l'index 1D du curseur sur le tableau VGA
/// @return index
int get_cursor()
{
    port_byte_write(VGA_CTRL_REGISTER, VGA_OFFSET_HIGH); // on prépare pour lire le high byte
    int index_vga = port_byte_read(VGA_DATA_REGISTER) << 8; // on prend le high byte et on le décale à la partie haute

    port_byte_write(VGA_CTRL_REGISTER, VGA_OFFSET_LOW); // on prépare pour lire le low byte
    index_vga |= port_byte_read(VGA_DATA_REGISTER); // on lit la partie basse (low) et on l'ajoute à la position

    return index_vga * 2; // position 1D (x2 car le VGA à deux bytes par cell)
}



/// @brief nettoie l'écran
void k_clear_screen()
{
    char* vga_buffer = (char *) VGA_MEM_ADDR;

    for (unsigned i = 0; i < DISPLAY_VGA_MAX * 2; i += 2)
    {
        vga_buffer[i + 0] = ' ';
        vga_buffer[i + 1]= GREEN_TXT;
    }
}




/// @brief écrit la lettre à l'écran
/// @param letter 
/// @param position 
void k_printchar(char letter, unsigned position)
{
    char* vga_buffer = (char *) VGA_MEM_ADDR;
    vga_buffer[position + 0] = letter + '\0'; 
    vga_buffer[position + 1] = GREEN_TXT;
}



/// @brief un équivalent printf rudimentaire
/// @param text 
/// @return 1 = success, nothing = error
unsigned k_printf(char* text)
{
    char* vga_buffer = (char *) VGA_MEM_ADDR;

    unsigned txt_index = 0;
    unsigned vga_index = 0;
    unsigned line = 0;

    while (text[txt_index] != '\0') // jusqu'à la fin du text
    {   
        if (text[txt_index] == '\n')
        {
            line++;

            while (vga_index < line * VGA_WIDTH)
            {   
                vga_buffer[vga_index++ + 0] = '\0';
                vga_buffer[vga_index++ + 1] = '\0';
            }
            txt_index++;
        }
        else
        {
            vga_buffer[vga_index++ + 0] = text[txt_index++];
            vga_buffer[vga_index++ + 1] = GREEN_TXT;

        }
        
    }

    vga_buffer[vga_index++] = '\0'; // fin de text

    return 1;
    
}




/// @brief print number in hex
/// @param number 
void print_hex(int number)
{
    unsigned nb_tmp = (unsigned) number;

    unsigned length = get_digits_length(number) + 1;

    char * hex_str = k_malloc(sizeof(char) * length);

    for (unsigned i = 0; i < length; i++)
    {
        const char hex = (char)(nb_tmp & 0x0f);
        nb_tmp /= 16;

        if (hex < 10)
        {
            hex_str[i] = hex + '0';
        }
        else
        {
            hex_str[i] = hex + 'a' - 10;
        }
    }

    hex_str[length - 2] = 'x';
    hex_str[length - 1] = '0';
    hex_str[length] = '\0';

    reverse_string(hex_str);
    
    k_printf(hex_str);

    k_free(hex_str);
    
}

