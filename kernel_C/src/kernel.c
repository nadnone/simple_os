#include <stdlib.h>
#include <stdbool.h>

#include "constants.h"
#include "misc/types.h"
#include "misc/memory_alloc.h"
#include "kernel_display.h"
#include "keyboard/keyboard.h"
#include "misc/number_helper.h"
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



uint32 get_timestamp(bool part)
{
    uint32 low, high;
    // =a = registre A; =b = registre B
    asm volatile("RDTSC" : "=a"(low), "=b"(high));

    if (!part)
    {
        return low;
    }
    else
    {
        return high;
    }
    
}


void k_main()
{

    char* str_l = malloc(sizeof(char) * 11);

    if (str_l == NULL)
    {
        k_printf("ERROR str");
    }
    // refresh
    k_clear_screen();

    unsigned counter = 0;

    while (true)
    {  
        uint32 t0 = get_timestamp(false);




        char *key = get_keyboard_keys();

        if (key == "Q")
        {
            k_free(str_l);
            return;
        }

        uint32 t1 = get_timestamp(false);

        convert_nb_to_ascii(counter++, str_l);
        k_printf(str_l);

    }

    
}