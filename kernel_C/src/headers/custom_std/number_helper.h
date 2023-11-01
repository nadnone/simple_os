#pragma once

unsigned get_bits_length(unsigned object);

// conversion en hexadécimales
char get_hex_nibble(unsigned char digit)
{

    if (digit < 10)
    {
        return '0' + digit;
    }
    else
    {
        return 'A' + digit;
    }
            
}

/// @brief multiplication par exposant 
/// @param value 
/// @param power 
/// @return le produit
uint32_t k_pow(unsigned value, unsigned power)
{
    uint32_t rslt = 1;

    for (unsigned i = 0; i < power; i++)
    {
        rslt *= value;    
    }
    
    return rslt;
}


/// @brief inverse l'ordre des bits
/// @param bits 
/// @return l'inverse de ce qui a été donné
uint32_t reverse_bits(uint32_t bits)
{
    uint32_t rev_bits = 0;

    while (bits > 0)
    {
        rev_bits |= bits & 0b1; // reverse = reverse OR bit

        rev_bits <<= 1; // on décale pour ajouter le prochain bit
        bits >>= 1; // on décale pour prendre le prochain bit
    }

    return rev_bits;
}

/// @brief donne le nombre de digit d'un nombre
/// @param object 
/// @return nombre de digits
unsigned get_digits_length(uint32_t object)
{
    unsigned counter = 0;
    uint32_t tmp = object;

    while (tmp != 0)
    {
        tmp /= 10;
        counter++;
    }

    return counter;
    
}

/// @brief compte le nombre de bit utilisé dans l'argument
/// @param object 
/// @return nombre de bits utilisés
unsigned get_bits_length(unsigned object)
{
    unsigned bits = object;
    unsigned counter = 0;

    while (bits != 0)
    {
        bits >>= 1;
        counter++;
    }

    return counter;

}