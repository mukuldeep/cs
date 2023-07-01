ORG 0x7c00 ; Assembly origin
BITS 16 ; for 16 bit arch

start:
    mov ah, 0eh 
    mov al, 'A'
    mov bx, 0
    int 0x10 ; Interrupt for output content of Reg al, http://www.ctyme.com/intr/rb-0106.htm

    jmp $ ; jump on itself

times 510-($-$$) db 0 ; Padding upto 510bytes with 0 after previous code
dw 0xAA55 ; 0x55AA in l-endian, last 2bytes as boot signature. dw - define word.

