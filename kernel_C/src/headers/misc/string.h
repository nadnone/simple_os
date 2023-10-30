#pragma once
// string must be same lenght !
char* k_strcpy(char* in, char* out)
{
    unsigned counter = 0;

    while (in[counter] != '\0')
    {
        out[counter++] = in[counter];
    }
    
}

void reverse_string(char* number)
{
    unsigned counter = 0;
    unsigned strlen = sizeof(number) / sizeof(char) - 1;
    char* strclone = "000";

    k_strcpy(number, strclone);

    while (number[counter] != '\0')
    {
        number[counter++] = strclone[strlen - 1 - counter];
    }
    
}