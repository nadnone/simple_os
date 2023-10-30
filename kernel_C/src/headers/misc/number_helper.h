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


void reverse_uinteger(unsigned number)
{

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

void print_hex(int number)
{
    unsigned nb_tmp = (unsigned) number;

    unsigned length = get_bits_length(number);

}