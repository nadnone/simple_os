#pragma once
#include "keyboard/keyboard_scancodes_QWERTZ.h"

/// @brief récuperer les scancodes du clavier
/// @return le scancode
unsigned char get_scancode()
{
    unsigned char ret; // retour de la commande assembleur

    // lecture "in" à l'adresse du clavier des scancodes
    asm volatile("in %%dx, %%al" : "=a"(ret) : "d"(KEYBOARD_MEM_ADDR) : "memory"); 

    return ret;

}

/// @brief pour récuperer les touches du clavier en format ASCII
/// @return string ASCII du caractère
char* get_keyboard_keys()
{
    unsigned char scancode = get_scancode();
    unsigned i = 0;

    while (KEYMAP_KEYBOARD.ascii[i++] != "")
    {
        if (scancode == KEYMAP_KEYBOARD.numbers[i])
        {
            return KEYMAP_KEYBOARD.ascii[i];
        }
        
    }    


}
