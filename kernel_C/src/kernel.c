#include "constants.h"
#include "kernel_display.h"
#include "pong_game.h"
#include "keyboard/keyboard.h"
#include "misc/number_helper.h"

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


char convert_nb_to_ascii(unsigned number, char* string, unsigned number_char)
{
    unsigned nb_tmp = number;

    char ascii_reverse[number_char];
    unsigned rev_counter = 0;

    while (nb_tmp != 0)
    {
        char last_digit = nb_tmp % 10;
        nb_tmp /= 10;

        ascii_reverse[rev_counter++] = last_digit + '0';
    }

    unsigned counter = 0;
    while (rev_counter != 0)
    {
        string[counter++] = ascii_reverse[rev_counter--];
    }

    
}

unsigned get_timestamp()
{
    unsigned a_register;
    // =a = registre A
    asm volatile("RDTSC" : "=a"(a_register));

    return (a_register);
}


void k_main()
{

    // refresh
    k_clear_screen();

    while (1)
    {   

        // program

        //k_printf("Let's play !");
        
        char* ascii_test = "0000"; // TODO : Créer une function malloc et free

        convert_nb_to_ascii(112, ascii_test, 3);
        k_printf(ascii_test);

        //char* key = get_keyboard_keys();
        //k_printf(key);
        

        //drawplayer1(25/2);
        //drawplayer2(25/2);


    }
        

   return;
    
}