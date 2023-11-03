#pragma once
#include "keyboard/keyboard_scancodes_QWERTZ.h"
#include "custom_std/io_manager.h"

/// Adresse pour lire les scancodes 
#define KEYBOARD_MEM_ADDR 0x60 


/// @brief récuperer les scancodes du clavier
/// @return le scancode
uint8_t get_scancode()
{
    uint8_t ret; // retour de la commande assembleur

    // lecture l'adresse du clavier des scancodes
    ret = port_byte_read(KEYBOARD_MEM_ADDR);

    return ret;

}

/// @brief pour récuperer les touches du clavier en format ASCII
/// @return string ASCII du caractère
char* get_keyboard_keys()
{
    uint8_t scancode = get_scancode();
    uint8_t scancode_bis = get_scancode();
    
    unsigned i = 0;
    
    if (scancode_bis == scancode)
    {
        i = 0;

        while (KEYMAP_KEYBOARD.ascii[i++] != "")
        {
            if (scancode == KEYMAP_KEYBOARD.numbers[i])
            {
                return KEYMAP_KEYBOARD.ascii[i];
            }
            
        }  
    }
    // pour les combo d'opcodes
    else if (scancode != scancode_bis)
    {

        switch (scancode)
        {
            case 0xe0: // pour les combos qui commencent par 0xE0

                i = 0;

                while (KEYMAP_E0.ascii[i++] != "")
                {
                    if (scancode_bis == KEYMAP_E0.numbers[i])
                    {
                        return KEYMAP_E0.ascii[i];
                    }
                    
                }  

                break;

            
            default:
                break;
        }



    }
}