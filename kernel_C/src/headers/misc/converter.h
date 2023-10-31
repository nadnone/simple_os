#pragma once

void convert_nb_to_ascii(uint32 number, char* string)
{
    uint32 nb_tmp = number;

    unsigned rev_counter = 0;

    // on compte le nombre de digits
    unsigned length_digits = get_digits_length(nb_tmp);
    
    char* reverse_array = (char*) malloc(sizeof(char) * (length_digits + 1));
    nb_tmp = number;

    // on converti
    string[length_digits] = '\0'; // on prend soin de mettre la fin de string

    while (length_digits != 0)
    {
        char last_digit = (char)(nb_tmp % 10);
        nb_tmp /= 10;

        string[--length_digits] = last_digit + '0';
    }


    k_free(reverse_array);
}
