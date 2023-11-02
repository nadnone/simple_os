#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#include "custom_std/memory_alloc.h"
#include "custom_std/number_helper.h"
#include "misc/converter.h"
#include "custom_std/string.h"
#include "keyboard/keyboard.h"
#include "custom_std/time.h"

#include "video/vga_driver.h"


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


    k_printf("TEST");
    
    /// TODO: debugger le positionnement du curseur
    set_cursor(0,0);

    while (true)
    { 
        increament_global_timestamp();

    }
    
    



}

