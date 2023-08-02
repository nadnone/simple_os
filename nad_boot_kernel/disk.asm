disk_load: 
    mov         ah, 2                       ; lecture du secteur disque https://www.gladir.com/LEXIQUE/INTR/int13f02.htm
    mov         al, 1                       ; nombre de secteurs à lire
    mov         ch, 0                       ; cylindre
    mov         cl, 2                       ; secteur
    mov         dh, 0                       ; numéero de tête de lecture/écriture
    mov         dl, 80h                     ; unité du disque 0 (pour un CDROM ou un disque dur)
    mov         bx, KERNEL_LOCATION         ; 0x7c00 + 512 (addresse du kernel)

    int         13h                         ; Drive read interrupt

    cmp         ah, 0                       ; on compare
    je          on_success                  ; si égal on saute à on_success

on_error:
    mov         ah, 00h                     ; on active le mode graphique https://www.gladir.com/LEXIQUE/INTR/INT10F00.HTM
    mov         al, 00h                     ; mode 320x200
    int         10h                         ; on appel l'interrupt BIOS 0x10

    mov         ah, 13h                     ; on utilise la fonction 0x13 de l'interrupt 0x10 du BIOS https://www.gladir.com/LEXIQUE/INTR/int10f13.htm
    mov         al, 01h                     ; on indique le mode de sortie 01h qui permet l'utilisation du registre BL et actualise le curseur
    mov         bl, 02h                     ; couleurs
    mov         cx, 11                      ; caractères à écrire
    mov         dh, 1                       ; ligne
    mov         dl, 0                       ; colonne
    mov         bh, 0                       ; page 0, on n'utilise pas cette fonctionnalité
    mov         bp, text_error              ; sinon on affiche ERROR
    int         10h

    jmp         $                           ; on attend ici

on_success:
    ret

text_error db   "DISK ERROR!", 0x0a
text_success db "LOAD OK!   ", 0x0a
