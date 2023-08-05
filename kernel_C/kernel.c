#define GREEN_TXT 0x2
#define VGA_MEM_ADDR 0xb8000


void k_clear_screen();
unsigned k_printf(char * text);


void k_main()
{
    k_clear_screen();

    char* message = "Bienvenue sur mon kernel 32bit :)";

    if (k_printf(message))
    {
        while (1)
        {
            // on attend        
        }
    }

   return;
    
}

void k_clear_screen()
{
    char* vga_buffer = (char *) VGA_MEM_ADDR;

    for (unsigned i = 0; i < 80*25*2; i += 2)
    {
        vga_buffer[i + 0] = ' ';
        vga_buffer[i + 1]= GREEN_TXT;
    }

}

unsigned k_printf(char* text)
{
    char* vga_buffer = (char *) VGA_MEM_ADDR;

    unsigned i = 0;
    unsigned j = 0;

    while (text[i] != '\0') // jusqu'à la fin du text
    {   
        vga_buffer[j++ + 0] = text[i++];
        vga_buffer[j++ + 1] = GREEN_TXT;

    }
    
    vga_buffer[j++ + 1] = '\0'; // fin de text

    return 1;
    
}