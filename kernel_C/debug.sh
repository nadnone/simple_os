# compilation
nasm -f elf32 src_asm/kernel.asm -o bin/kernel_asm.o &&
gcc -m32 -c -Iinclude/std -I./src/headers/ \
    src/kernel.c -o bin/kernel.o && 

# Linking
ld -m elf_i386 -T linker/link.ld -o bin/kernel bin/kernel_asm.o bin/kernel.o &&

# on émule pour check
qemu-system-x86_64 -kernel bin/kernel # On prie pour que ca marche
