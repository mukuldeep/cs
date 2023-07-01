ORG 0x7c00 ; Assembly origin
BITS 16 ; for 16 bit arch

start:
    mov si, message ; point Reg si to message
    call print ; call sub-routinge print
    jmp $ ; jump on itself

print: ; Sub-routine to loop using si until 0
    mov bx,0
.loop:
    lodsb ; Load the char pointed by Reg si
    cmp al,0 ; comparing if al is 0
    je .done ; if 0 then jump to .done:
    call print_char ; otherwise, call print_char sub-routine to print it
    jmp .loop ; and continue looping
.done:
    ret

print_char: ; Subroutine to print the char in Reg al
    mov ah, 0eh
    int 0x10 ;Interrupt for output content of Reg al, http://www.ctyme.com/intr/rb-0106.htm
    ret

message: db 'Hello World!', 0 ; define bytes, ends with 0

times 510-($-$$) db 0 ; Padding upto 510bytes with 0 after previous code
dw 0xAA55 ; 0x55AA in l-endian, last 2bytes as boot signature. dw - define word.

