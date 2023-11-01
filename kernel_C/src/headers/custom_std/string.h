#pragma once

unsigned strlen(char * str);


/// string must be same lenght !
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

unsigned strlen(char * str)
{
    return sizeof(str) / sizeof(char) + 1;
}

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