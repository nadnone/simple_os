ORG 0x7c00                                  ; addresse de départ pour boot, on se déplace à cette addresse (instruction NASM)
BITS 16                                     ; asssemblage en 16 bit uniquement (instruction NASM)

main: 
    jmp         start                       ; on saute à start 




start: 
    mov         ah, 00h                     ; on active le mode graphique https://www.gladir.com/LEXIQUE/INTR/INT10F00.HTM
    mov         al, 00h                     ; mode 320x200
    int         10h                         ; on appel l'interrupt BIOS 0x10
    jmp         drive_load                  ; on saute à printstr pour afficher le message



drive_load: 
    mov         ah, 2                       ; lecture du secteur disque https://www.gladir.com/LEXIQUE/INTR/int13f02.htm
    mov         al, 1                       ; nombre de secteurs à lire
    mov         ch, 0                       ; cylindre
    mov         cl, 2                       ; secteur
    mov         dh, 0                       ; numéero de tête de lecture/écriture
    mov         dl, 80h                     ; unité du disque 0 (pour un CDROM ou un disque dur)
    mov         bx, 0x7e00                  ; 0x7c00 + 512 (addresse du kernel)

    int         13h                         ; Drive read interrupt

    jmp         print_string                ; on va imprimer le résultat




print_string:
    mov         ah, 13h                     ; on utilise la fonction 0x13 de l'interrupt 0x10 du BIOS https://www.gladir.com/LEXIQUE/INTR/int10f13.htm
    mov         al, 01h                     ; on indique le mode de sortie 01h qui permet l'utilisation du registre BL et actualise le curseur
    mov         bl, 02h                     ; couleurs
    mov         cx, 7                       ; caractères à écrire
    mov         dh, 1                       ; ligne
    mov         dl, 0                       ; colonne
    mov         bh, 0                       ; page 0, on n'utilise pas cette fonctionnalité

    cmp         ah, 0                       ; on compare si il y a erreur avec le flag ah de INT_13H section drve_check
    jne         n_eqal                      ; si pas égal on saute à n_eqal

    mov         bp, text_success            ; sinon on écrit success
    jmp         print                       

n_eqal:
    mov         bp, text_error              

; on print à l'écran
print:
    int         10h                         ; on appel l'interrupt 0x10 du BIOS pour afficher le message
    jmp         $                           ; boucle infinie, on bouge plus et on attend



; quelques variables
text_error db "ERROR  ", 0x0a
text_success db "SUCCESS", 0x0a
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