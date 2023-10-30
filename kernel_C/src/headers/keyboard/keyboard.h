#pragma once
#include "constants.h"
#include "keyboard_scancodes.h"


// récuperer les scancodes du clavier
unsigned char get_scancode()
{
    unsigned char ret; // retour de la commande assembleur

    // lecture "in" à l'adresse du clavier des scancodes
    asm volatile("in %%dx, %%al" : "=a"(ret) : "d"(KEYBOARD_MEM_ADDR) : "memory"); 

    return ret;

}

// pour récuperer les touches du clavier en format ASCII
char* get_keyboard_keys()
{
    unsigned char scancode = get_scancode();

    for (unsigned i = 0; KEYMAP_KEYBOARD.ascii[i] != ""; i++)
    {
        if (scancode == KEYMAP_KEYBOARD.numbers[i])
        {
            return KEYMAP_KEYBOARD.ascii[i];
        }
        
    }

}
