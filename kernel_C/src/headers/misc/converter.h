#pragma once
#include "misc/string.h"

void convert_nb_to_ascii(unsigned number, char* string)
{
    unsigned nb_tmp = number;

    unsigned rev_counter = 0;
    unsigned length_digits = 0;

    // on compte le nombre de digits
    while (nb_tmp != 0)
    {
        nb_tmp /= 10;
        length_digits++;
    }
    
    char* reverse_array = (char *) malloc(sizeof(char) * (length_digits + 1));
    nb_tmp = number;


    // on converti
    string[length_digits] = '\0'; // on prend soin de mettre la fin de string

    while (length_digits != 0)
    {
        char last_digit = (char)(nb_tmp % 10);
        nb_tmp /= 10;

        string[--length_digits] = last_digit + '0';
    }

    free(reverse_array);
}
