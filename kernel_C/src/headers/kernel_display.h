#pragma once

/// @brief (commande un peux inutile), ajoute un x à une position (x,y)
/// @param px 
/// @param py 
/// @return 
void put_pixel(unsigned px, unsigned py)
{
    char* vga_buffer = (char *) VGA_MEM_ADDR;

    unsigned loc = (px + py * DISPLAY_WIDTH) * 2;

    vga_buffer[loc + 0] = 'x';
    vga_buffer[loc + 1] = WHITE_TXT;

}

/// @brief nettoye l'écran
void k_clear_screen()
{
    char* vga_buffer = (char *) VGA_MEM_ADDR;

    for (unsigned i = 0; i < DISPLAY_VGA_MAX * 2; i += 2)
    {
        vga_buffer[i + 0] = ' ';
        vga_buffer[i + 1]= GREEN_TXT;
    }


}

void k_printchar(char letter, unsigned position)
{
    char* vga_buffer = (char *) VGA_MEM_ADDR;
    vga_buffer[position + 0] = letter; 
    vga_buffer[position + 1] = GREEN_TXT;
    vga_buffer[position + 2] = '\0'; 
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

            while (vga_index < line * DISPLAY_WIDTH)
            {   
                vga_buffer[vga_index++ + 0] = ' ';
                vga_buffer[vga_index++ + 1] = GREEN_TXT;
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

