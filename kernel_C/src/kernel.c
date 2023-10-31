#include <stdlib.h>
#include <stdbool.h>

#include "constants.h"
#include "misc/types.h"
#include "misc/memory_alloc.h"
#include "misc/number_helper.h"
#include "misc/converter.h"
#include "misc/string.h"
#include "kernel_display.h"
#include "keyboard/keyboard.h"

void panic()
{

    k_printf("/!\\ Kernel Panic !\n\n[!] Reboot please.");

    while (1)
    {
        // on panique on fait rien
    }
    
}


void k_main()
{

    // refresh
    k_clear_screen();
    k_printf("Fonctionne mais ne fait rien..");

    while (true)
    {  

    }

    
}