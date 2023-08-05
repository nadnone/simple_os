# compilation
nasm -f elf32 kernel.asm -o kernel_asm.o &&
gcc -m32 -c kernel.c -o kernel.o &&

# Linking
ld -m elf_i386 -T link.ld -o kernel kernel_asm.o kernel.o &&

# on émule pour check
qemu-system-i386 -kernel kernel # On prie pour que ca marche
