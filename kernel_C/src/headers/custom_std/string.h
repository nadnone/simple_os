#pragma once

unsigned strlen(char * str);


/// @brief copy un string dans un autre de même taille
/// @param in 
/// @param out 
/// @return false si les string n'ont pas la même longueur, true si succès
bool k_strcpy(char* in, char* out)
{
    if (strlen(in) != strlen(out))
    {
        return false;
    }

    unsigned counter = 0;

    while (strlen(in) + 1 != counter)
    {
        out[counter++] = in[counter];
    }
    out[counter] = '\0';

    return true;
}

/// @brief compte le nombre de char dans un string
/// @param str 
/// @return nombre de char + le caractère de fin
unsigned strlen(char * str)
{
    return sizeof(str) / sizeof(char) + 1;
}

/// @brief inverse l'ordre des char dans un string
/// @param str 
/// @return string inversé
bool reverse_string(char* str)
{
    unsigned counter = 0;
    unsigned len = strlen(str) + 1;
 
    char* strclone = k_malloc(sizeof(char) * (len));

    if (strclone == NULL)
    {
        k_free(strclone);
        return true;
    }

    k_strcpy(str, strclone);

    while (len != counter)
    {
        str[counter++] = strclone[len - 1 - counter];
    }
    str[counter] = '\0';

    k_free(strclone);
    return false;
}