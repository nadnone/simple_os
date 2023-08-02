ORG 0x7c00                                  ; addresse de départ pour boot, on se déplace à cette addresse (instruction NASM)
BITS 16                                     ; asssemblage en 16 bit uniquement (instruction NASM)

main:
    call        disk_load
    call        enter_protected_mode

    jmp         $

enter_protected_mode:
    cli                             ; on désactive tout les interrupts
    lgdt        [gdt_descriptor]    ; on charge le GDT

    mov     eax, cr0                ; on change le dernier bit de CR0 à 1
    or      eax, 1b
    mov     cr0, eax                ; on applique les changements; on passe en 32Bits !


[BITS 32]
goto_kernel:

    mov     dword[0xb8000], 0x07690748

    jmp     $

    jmp     KERNEL_LOCATION


%include "disk.asm"
%include "global_descriptor_table.asm"



; on passe ne mode protégé pour pouvoir sauter au kernel
; plus d'info ici => https://youtu.be/Wh5nPn2U_1w?list=PLm3B56ql_akNcvH8vvJRYOc7TbYhRs19M


; quelques variables
KERNEL_LOCATION equ 0x7e00 ; l'endroit ou sera chargé le kernel dans la RAM

flag_check db 0
; db = data byte => chaque caractère fait 8bit
; 0x0a = fin de ligne




times 510-($ - $$) db 0    ; times = pseudo-instruction de l'assembleur NASM qui répète une instruction un nombre de fois définis
                                     ; $$ = l'adresse du début de la section actuelle
                                     ; $ = l'adresse actuelle de l'état
                                     ; 510 - ($ - $$) = soustraction à la taille des instructions car la taille doit être à 512 bytes
                                     ; db = data byte, insère des données en bytes
                                     ; en résumé, la ligne demande à remplir les bytes restant à 0, pour obtenir 512 bytes d'espace total



dw 0xAA55                            ; signature de boot, ordre inversé (nombre magique)
                                     ; l'instruction dw est de 2 bytes donc le seuil de 512 bytes est atteint et le programme peut démarrer