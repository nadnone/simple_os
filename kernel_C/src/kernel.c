#include "headers/constants.h"
#include "headers/kernel_display.h"
#include "headers/pong_game.h"
#include "headers/keyboard_scancodes.h"

void k_clear_screen();
unsigned k_printf(char * text);
unsigned put_pixel(unsigned px, unsigned py);


void panic()
{

    k_printf("/!\\ Kernel Panic !\n\n[!] Reboot please.");

    while (1)
    {
        // on panique on fait rien
    }
    
}

char get_hex_nibble(unsigned char digit)
{

    if (digit < 10)
    {
        return '0' + digit;
    }
    else
    {
        return 'A' + digit;
    }
            
}

unsigned char get_scancode()
{
    volatile unsigned char *keybd_register = (unsigned char*) KEYBOARD_MEM_ADDR;
    return *keybd_register;
}

void get_keyboard_keys()
{
    unsigned char scancode = get_scancode();

    char* hex = "  ";

    hex[0] = get_hex_nibble((scancode >> 4) & 0x0f);    
    hex[1] = get_hex_nibble((scancode) & 0x0f);
    hex[2] = '\0';

    k_printf(hex);

    // TODO comprendre comment intereter ce 
}


void k_main()
{

    // refresh
    k_clear_screen();

    while (1)
    {   

        // program

        //k_printf("Let's play !");

        get_keyboard_keys();
        //drawplayer1(25/2);
        //drawplayer2(25/2);


    }
        

   return;
    
}