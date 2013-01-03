#!/bin/sh

cp build/kernel.bin build/iso/alphaos.bin
cp bin/initrd/initrd.img build/iso/initrd
grub-mkrescue -o alphaos.iso build/iso/
qemu-system-i386 alphaos.iso
