struct KEYMAP_KEYBOARD
{
    unsigned char numbers[45];
    char* ascii[46];

} KEYMAP_KEYBOARD = {
    {
        0x0B, 0x02, // 0, 1
        0x03, 0x04, // 2, 3
        0x05, 0x06, // 4, 5 
        0x07, 0x08, // 6, 7
        0x09, 0x0a, // 8, 9

        0x10, 0x11, // Q, W
        0x12, 0x13, // E, R
        0x14, 0x15, // T, Z 
        0x16, 0x17, // U, I 
        0x18, 0x19, // O, P

        0x1E, 0x1F, // A, S
        0x20, 0x21, // D, F
        0x22, 0x23, // G, H
        0x24, 0x25, // J, K
        0x26, // L

        0x2C, 0x2D, // Y, X
        0x2E, 0x2F, // C, V
        0x30, 0x31, // B, N
        0x32, // M

        0x33, // , (virgule)
        0x34, // . (point)
        0x35, // - (tiret)

        0x39, // Space
        0x1D, // CTRL Left
        0x2A, // left shift
        0x36, // right shift

        0x1c, // Enter

    },
    {
        "0", "1",
        "2", "3",
        "4", "5",
        "6", "7",
        "8", "9",

        "Q", "W",
        "E", "R",
        "T", "Z",
        "U", "I",
        "O", "P",

        "A", "S",
        "D", "F",
        "G", "H",
        "J", "K",
        "L",

        "Y", "X",
        "C", "V",
        "B", "N",
        "M", 

        ",", ".",
        "-",

        "SPACE", 
        "L-CTRL",
        "L-SHIFT",
        "R-SHIFT",

        "ENTER",

        "" // fin du tableau
    }
};

struct KEYMAP_E0 {

    unsigned char numbers[2];
    char* ascii[3];

} KEYMAP_E0 = {
    {
        0x1d,
        0x35,
    },
    {
        "R_CTRL",
        "DIVIDE",
        "" // fin du tableau
    }
    /// TODO: continuer d'ajouter les scancodes
};