
Update 
`sudo apt update`

install nasm - Tool for compiling assembly
`sudo apt install nasm`
`nasm -v`

Install emulator - qemu
`sudo apt install qemu-system-x86`
`qemu-system-x86_64`

Compile asm file using nasm
`nasm -f bin ./bootloader.asm -o ./bootloader.bin`

See content of the binary file 
`ndisasm ./bootloader.bin`

Run on qemu
`qemu-system-x86_64 -hda ./bootloader.bin`