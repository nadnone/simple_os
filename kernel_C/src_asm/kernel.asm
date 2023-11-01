bits 32

section .text

    align 4
    dd 0x1BADB002                       ; nombre magic pour identifier l'en-tête
    dd 0x00                             ; flags non utilisés, donc 0
    dd - (0x1BADB002 + 0x00)            ; checksum: le total de magic+flags+checksum doit faire 0

global start
extern k_main ; la fonction de départ dans kernel.c

start:

    cli                                 ; on block les interrupts
    mov     esp, stack_space            ; on initialize le pointeur du stack
    call    k_main                      ; on appel la fonction principale de kernel.c
    hlt                                 ; on arrête le CPU


section .bss                            ; "Block Started by Symbol" section
bss_start:                              ; adresse de départ de bss
resb    1024*16                         ; allocation de mémoire non initialisé 16kbit pour le stack
bss_end:                                ; adresse de fin de bss
stack_space:                            ; adresse de l'espace stack utilisé plus haut

global bss_start
global bss_end