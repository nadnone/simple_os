ORG 0x7c00                           ; addresse de départ pour boot, on se déplace à cette addresse (instruction NASM)
BITS 16                              ; asssemblage en 16 bit uniquement (instruction NASM)


start: 
    mov         ah, 00h              ; on active le mode graphique
    mov         al, 13h              ; mode 13h https://en.wikipedia.org/wiki/Mode_13h
    int         10h                  ; on appel l'interrupt BIOS 0x10

    mov         ah, 0eh              ; 0eh correspond à la fonction teletype output: https://en.wikipedia.org/wiki/INT_10H
    mov         al, 'H'              ; le registre AL contiendra le caractère ASCII
    mov         bh, 0                ; on s'en fiche de la page. on garde l'index 0
    mov         bl, 0x2              ; on assigne la couleur verte: https://en.wikipedia.org/wiki/BIOS_color_attributes
    int         10h                  ; on appel l'interrupt 0x10 pour afficher 'H' à l'écran

    jmp         $                    ; boucle infinie pour afficher le texte

times 0x167ffe-($ - $$) db 0         ; times = pseudo-instruction de l'assembleur NASM qui répète une instruction un nombre de fois définis
                                     ; $$ = l'adresse du début de la section actuelle
                                     ; $ = l'adresse actuelle de l'état
                                     ; 0x167ffe - ($ - $$) = soustraction de 1.44MB - la taille des instructions car la taille doit être à 1.44MB bytes dans un ISO
                                     ; db = data byte, insère des données en bytes
                                     ; en résumé, la ligne demande à remplir les bytes restant à 0, pour obtenir 1.44MB bytes d'espace total


dw 0xAA55                            ; signature de boot, ordre inversé
                                     ; l'instruction dw est de 2 bytes donc le seuil de 1.44MB bytes est atteint et le programme peut démarrer