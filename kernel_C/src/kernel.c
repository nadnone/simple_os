#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#include "custom_std/memory_alloc.h"
#include "custom_std/number_helper.h"
#include "misc/converter.h"
#include "custom_std/string.h"
#include "custom_std/time.h"
#include "keyboard/keyboard_driver.h"

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
    while (true)
    { 
        // impératif pour gérer le temps
        increament_global_timestamp();
        
        k_clear_screen();


        char* scancode = get_keyboard_keys();
        k_printf(scancode);


        // pour voir les touches passer
        sleep(60);
    }
    
    



}

