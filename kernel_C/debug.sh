# compilation
nasm -f elf32 src_asm/kernel.asm -o bin/kernel_asm.o && 
echo "Compilation ASM" &&

# option -c pour ne pas linker, je le fais en deuxième temps
gcc -m32 -c -nostdlib \
    -I./src/headers/ \
    src/kernel.c -o bin/kernel.o &&
echo "Compilation C" &&

# Linking
ld -m elf_i386 -T linker/link.ld -o bin/kernel bin/kernel_asm.o bin/kernel.o &&
echo "LINKING" &&

# création d'un disque virtuel vide
# dd if=/dev/zero of=disk.img iflag=fullblock bs=1M count=56 &&

# on émule pour check avec des options de QEMU_x86_64
echo "RUNING QEMU" &&
qemu-system-x86_64 -kernel bin/kernel \
    -m 16M \
    -drive file=disk.img,index=0,media=disk,format=raw \