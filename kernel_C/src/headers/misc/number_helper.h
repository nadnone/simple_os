#pragma once

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

unsigned get_digits_length(unsigned object)
{
    char counter = 0;
    unsigned tmp = object;

    while (tmp != 0)
    {
        tmp /= 10;
        counter++;
    }

    return counter;
    
}

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