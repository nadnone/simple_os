#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#include "constants.h"
#include "custom_std/memory_alloc.h"
#include "custom_std/number_helper.h"
#include "misc/converter.h"
#include "custom_std/string.h"
#include "kernel_display.h"
#include "keyboard/keyboard.h"
#include "custom_std/time.h"

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

    while (true)
    {
        increament_global_timestamp();
        
        k_printf("test");

        sleep(5000);

        k_printf("test ok");

        sleep(5000);
        
        k_clear_screen();


    }
    
    



}

