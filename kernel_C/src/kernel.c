#define GREEN_TXT 0x2
#define BLUE_TXT 0x1
#define WHITE_TXT 0xf
#define VGA_MEM_ADDR 0xb8000

#define DISPLAY_WIDTH 80
#define DISPLAY_HEIGHT 25
#define DISPLAY_VGA_MAX DISPLAY_HEIGHT * DISPLAY_WIDTH

void k_clear_screen();
unsigned k_printf(char * text);
unsigned put_pixel(unsigned px, unsigned py);


void panic()
{

    k_printf("/!\\ Kernel Panic !\n\n[!] Reboot please.");

    while (1)
    {
        // on panique on fait rien
    }
    
}


unsigned drawplayer1(unsigned y)
{
    for (unsigned i = 0; i < 2; i++)
    {
        for (unsigned j = y-3; j < y+3; j++)
        {
            put_pixel(i, j);
        }
        
    }
}

unsigned drawplayer2(unsigned y)
{
    for (unsigned i = DISPLAY_WIDTH-2; i < DISPLAY_WIDTH; i++)
    {
        for (unsigned j = y-3; j < y+3; j++)
        {
            put_pixel(i, j);
        }
        
    }
}

void k_main()
{


    k_clear_screen();

    char* message = "Bienvenue sur mon kernel 32bit :)";


    if (k_printf(message))
    {
            k_clear_screen();
            
            // program
            k_printf("Let's play !");

            drawplayer1(25/2);
            drawplayer2(25/2);

        while (1)
        {

        }
    }

   return;
    
}

unsigned put_pixel(unsigned px, unsigned py)
{
    char* vga_buffer = (char *) VGA_MEM_ADDR;

    unsigned loc = (px + py * DISPLAY_WIDTH) * 2;

    vga_buffer[loc + 0] = 'x';
    vga_buffer[loc + 1] = WHITE_TXT;

}

void k_clear_screen()
{
    char* vga_buffer = (char *) VGA_MEM_ADDR;

    for (unsigned i = 0; i < DISPLAY_VGA_MAX * 2; i += 2)
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

    unsigned line = 0;

    while (text[i] != '\0') // jusqu'à la fin du text
    {   
        if (text[i] == '\n')
        {
            line++;

            while (j < line * DISPLAY_WIDTH)
            {   
                vga_buffer[j++ + 0] = ' ';
                vga_buffer[j++ + 1] = GREEN_TXT;
            }
            i++;            
        }
        else
        {
            vga_buffer[j++ + 0] = text[i++];
            vga_buffer[j++ + 1] = GREEN_TXT;
        }
        
    }
    
    vga_buffer[j++] = '\0'; // fin de text

    return 1;
    
}