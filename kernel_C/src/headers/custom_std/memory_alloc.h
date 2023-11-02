#pragma once

extern char heap_start;
extern char heap_end;

// pour plus tard
typedef struct node_malloc {
    char size;
    int free;
    char* addr;
    struct node_malloc * next;
} node_malloc;

/// @brief remplis une plage d'adresse avec des zéros
/// @param start_addr 
/// @param end_addr 
void fillwithzero(char *start_addr, char *end_addr)
{
    for (char* i = start_addr; i <= end_addr; i++)
    {
        *i = '\0';
    }
    
}

/// @brief remplis une plage d'adresse avec le char défini
/// @param start_addr 
/// @param end_addr 
/// @param fillchar 
void fillwith(char *start_addr, char *end_addr, char fillchar)
{

    for (char* i = start_addr; i <= end_addr; i++)
    {
        *i = fillchar;
    }
    
}

/// @brief compte le nombre de blocks disponibles entre l'adresse définie jusqu'à la fin du .bss
/// @param start_addr 
/// @return 
unsigned count_freespace(const char * start_addr)
{
    char checker = '\0';
    unsigned counter = 0;

    while (checker == '\0')
    {
        checker = *(start_addr + counter++);

        if ((start_addr + counter) == &heap_end)
        {
            return counter;
        }
    }

    return counter;
}

/// @brief alloue de la mémoire dynamique
/// @param size_in_byte 
/// @return rien si bss est plein, une adresse si un espace a été trouvé
void *k_malloc(unsigned size_in_byte)
{

    for (char* i = &heap_start; i <= &heap_end; i++)
    {
        char* current_addr = (heap_start + i);
        unsigned free_space = count_freespace(current_addr);

        // si emplacement trouvé
        if (*current_addr == '\0' && free_space >= size_in_byte)
        {
            fillwith(current_addr, current_addr + size_in_byte - 1, ' ');
            return current_addr;
        }
    }

    // si rien trouvé on retourne rien
    return NULL;
    
}

/// @brief à utiliser après chaque utilisation de malloc() pour vider la mémoire utilisé afin qu'elle puisse être réutilisée
/// @param ptr 
void k_free(char* ptr)
{
    unsigned free_space = count_freespace(ptr);
    fillwithzero(ptr, (ptr + free_space));
}