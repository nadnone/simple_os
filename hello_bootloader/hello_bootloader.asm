ORG 0x7c00                           ; addresse de départ pour boot, on se déplace à cette addresse (instruction NASM)
BITS 16                              ; asssemblage en 16 bit uniquement (instruction NASM)

main: 
    jmp start                        ; on saute à start 


printstr:
    mov         ah, 13h              ; on utilise la fonction 0x13 de l'interrupt 0x10 du BIOS https://www.gladir.com/LEXIQUE/INTR/int10f13.htm
    mov         al, 01h              ; on indique le mode de sortie 01h qui permet l'utilisation du registre BL et actualise le curseur
    mov         bl, 02h              ; couleurs
    mov         cx, 103              ; caractères à écrire
    mov         dh, 1                ; ligne
    mov         dl, 0                ; colonne
    mov         bh, 0                ; page 0, on n'utilise pas cette fonctionnalité
    mov         bp, texte            ; on indique l'addresse de départ du string au registre BP

    int         10h                  ; on appel l'interrupt 0x10 du BIOS pour afficher le message

    jmp         $                    ; boucle infinie, on bouge plus et on attend



start: 
    mov         ah, 00h              ; on active le mode graphique https://www.gladir.com/LEXIQUE/INTR/INT10F00.HTM
    mov         al, 00h              ; mode 320x200
    int         10h                  ; on appel l'interrupt BIOS 0x10


    jmp         printstr             ; on saute à printstr pour afficher le message



texte db "Hello, I'm your computer and I'm angry, go away !", 0x0d , 0x0a, 0x0d , 0x0a, "Wait.. no.. I'm hungry ! Give me some bits !", 0x0a 
; texte = addresse de départ de l'écriture mémoire du string
; db = data byte => chaque caractère fait 8bit
; 0x0d = retour charriot
; 0x0a = fin de ligne




times 510-($ - $$) db 0              ; times = pseudo-instruction de l'assembleur NASM qui répète une instruction un nombre de fois définis
                                     ; $$ = l'adresse du début de la section actuelle
                                     ; $ = l'adresse actuelle de l'état
                                     ; 510 - ($ - $$) = soustraction de 510B - la taille des instructions car la taille doit être à 512 bytes
                                     ; db = data byte, insère des données en bytes
                                     ; en résumé, la ligne demande à remplir les bytes restant à 0, pour obtenir 512 bytes d'espace total



dw 0xAA55                            ; signature de boot, ordre inversé (nombre magique)
                                     ; l'instruction dw est de 2 bytes donc le seuil de 512 bytes est atteint et le programme peut démarrer