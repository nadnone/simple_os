# Simple bootloader

### Projet de création d'un programme assembleur x86 capable de se lancer au démarrage de l'ordinateur

---------------

Ce projet à pour but de m'initier et de commencer la programmation assembleur d'abord sur x86, puis, je projette d'étudier ensuite l'assembleur Armv8 pour mon Rasbperry Pi 4

## Afin de réussir ce projet, je me suis documenté avec les sources suivantes:

- https://en.wikibooks.org/wiki/X86_Assembly
- https://en.wikipedia.org/wiki/VGA_text_mode
- https://en.wikipedia.org/wiki/INT_10H
- https://en.wikipedia.org/wiki/BIOS_color_attributes
- https://interrupt.memfault.com/blog/how-to-write-a-bootloader-from-scratch
- https://softwareengineering.stackexchange.com/questions/165025/what-is-the-difference-between-times-and-dup-in-assembly-language
- https://ceionius.com/vga
- https://wiki.osdev.org/Bootable_CD
- https://www.gladir.com/LEXIQUE/INTR/INT10.HTM
- https://stackoverflow.com/questions/34121971/using-es-register-gives-errors
- https://www.ditig.com/256-colors-cheat-sheet
- https://stackoverflow.com/questions/12556973/how-does-int-10-13h-work-with-attributes

# Etat des choses

Pour le moment, ce programme est capable d'afficher une phrase à l'écran

![demo](./demo/demo.png)

# Défis à venir

- [x] Mon défis suivant, serait d'afficher une chaine de caractère et donc une phrase.

- [ ] Un autre serait de charger mon programme [nad_on_boot](https://github.com/nadnone/nad_on_boot) écrit en Rust à l'aide de ce bootloader

- [ ] Je verrais ensuite (peut-être) comment jouer avec les autres composants de l'ordinateur en créant un système d'exploitation primitif

