#pragma once

#define MAX_MALLOC 30

extern char bss_start;
extern char bss_end;

typedef struct node_malloc {
    char size;
    int free;
    char* addr;
    struct node_malloc * next;
} node_malloc;


void fillwithzero(char *start_addr, char *end_addr)
{
    for (char* i = start_addr; i <= end_addr; i++)
    {
        *i = '\0';
    }
    
}

void fillwith(char *start_addr, char *end_addr, char fillchar)
{

    for (char* i = start_addr; i <= end_addr; i++)
    {
        *i = fillchar;
    }
    
}

unsigned count_freespace(const char * start_addr)
{
    char checker = '\0';
    unsigned counter = 0;

    while (checker == '\0')
    {
        checker = *(start_addr + counter++);

        if ((start_addr + counter) == &bss_end)
        return counter;
    }

    return counter;
}

void *malloc(unsigned size_in_byte)
{

    for (char* i = &bss_start; i <= &bss_end; i++)
    {
        char* current_addr = (bss_start + i);
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

void free(char* ptr)
{
    unsigned free_space = count_freespace(ptr);
    fillwithzero(ptr, (ptr + free_space));
}