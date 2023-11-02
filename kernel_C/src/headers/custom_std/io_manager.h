#pragma once

/// @brief lis les données à une addresse mémoire
/// @param port adresse pour le registre DX
/// @return la valeur à l'adresse demandée
unsigned char port_byte_read(uint16_t port)
{
    uint16_t rslt;
    asm volatile("in %%dx, %%al"  // in car on lis donc ca rentre
        : "=a" (rslt) // on lis
        : "d" (port) // on écrit
        );
    return rslt;
}

/// @brief écrit à une adresse mémoire
/// @param port addresse pour le registre DX
/// @param data valeur pour le registre AL qui sera envoyé à DX
void port_byte_write(uint16_t port, unsigned char data)
{
    asm volatile("out %%al, %%dx" // out car on écrit donc sa sort
        : // on lis rien
        : "a" (data), "d" (port) // on écrit
    );
}