GDT_start:          ; https://wiki.osdev.org/GDT_Tutorial#Protected_Mode.2C_Flat_Model

    null_descriptor:
        dd 0
        dd 0

    code_segment_descriptor:
        dw 0xffff       ; les premier 16 bit de la limite
        
        dw 0            ; base
        db 0            ; 16bits + 8 bit = 24 (dw + db)

        db 10011010b    ; type flags (https://youtu.be/Wh5nPn2U_1w)

        db 11001111b    ; limite
        db 0            ; base

    data_segment_descriptor:
        dw 0xffff       ; les premier 16 bit de la limite
        
        dw 0            ; base
        db 0            ; 16bits + 8 bit = 24 (dw + db)

        db 10011010b    ; type flags (https://youtu.be/Wh5nPn2U_1w)

        db 11001001b    ; limite
        db 0            ; base
    
GDT_end:

gdt_descriptor:
    dw GDT_end - GDT_start - 1  ; taille
    db GDT_start                ; adresse de départ


CODE_SEG equ code_segment_descriptor - GDT_start
DATA_SEQ equ data_segment_descriptor - GDT_start