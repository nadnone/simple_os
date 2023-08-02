cd nad_boot_kernel &&

nasm -f bin bootloader_nad_kernel.asm -o bootloader_nad_kernel.bin &&

cd .. &&

rm nadkernel_bootable.img &&

dd if=./nad_boot_kernel/bootloader_nad_kernel.bin of=./nadkernel_bootable.img seek=0 count=1 conv=notrunc && # on copie le bootloader (secteur 0)

dd if=./nad_boot_kernel/nad_on_boot of=./nadkernel_bootable.img oflag=append conv=notrunc && # on copie le kernel (secteur 1)

qemu-system-x86_64 -drive format=raw,file=./nadkernel_bootable.img # On prie pour que ca marche

