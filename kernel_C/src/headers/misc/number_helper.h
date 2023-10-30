
// conversion en hexadécimales
char get_hex_nibble(unsigned char digit)
{

    if (digit < 10)
    {
        return '0' + digit;
    }
    else
    {
        return 'A' + digit;
    }
            
}
