#include "constants.h"
#include "kernel_display.h"
#include "pong_game.h"
#include "keyboard/keyboard.h"
#include "misc/number_helper.h"
#include "misc/memory_alloc.h"
#include "misc/converter.h"
#include "misc/string.h"

void panic()
{

    k_printf("/!\\ Kernel Panic !\n\n[!] Reboot please.");

    while (1)
    {
        // on panique on fait rien
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

    // program

    char* test = (char*) malloc(sizeof(char) * 5);
    
    if (test == NULL)
    {
        k_printf("ERROR");
    }

    fillwith(test, (test + (sizeof(char) * 4)), '#');

    char ok = sizeof(test) / sizeof(char);
    char* str = malloc(sizeof(char) * 10);

    if (str == NULL)
    {
        k_printf("ERROR");
    }

    convert_nb_to_ascii((unsigned int) 1234, str);

    k_printf(str);


    //print_hex(143);
    free(str);
    free(test);

    while (1)
    {  
    
    }
        

   return;
    
}