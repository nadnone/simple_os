genisoimage \
    -no-emul-boot \                             # ne pas émuler l'image, le système le charge sans émulation de disque         
    -b hello_bootloader.bin \                   # fichier executé en premier lors du boot
    -o bootloader_x86_64_1-1.iso \              # output
    floppydisk                                  # dossier contenant le tout