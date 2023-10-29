#pragma once
#include "constants.h"
#include "kernel_display.h"

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