bits 32                         ; set bits to 32
global _start                   ; tell linker where it starts
extern kernel_early             ; external func kernel_early
extern main                     ; external func main

section .text                   ; actual code
    align 4                     ; whatever number follows the align directive must be a power of 2
    dd 0x1BADB002               ; magic field required by GRUB
    dd 0x00                     ; define flags
    dd - (0x1BADB002 + 0x00)    ; checksum, when added to the values of magic and flags fields, should always be 0

_start:
    cli                         ; clear interuppts
    mov esp, stack              ; move stack into esp
    call kernel_early           ; call kernel_early func
    call main                   ; call main func
    hlt                         ; halt

section .bss                    ; variables
resb 8192                       ; reserve byte
stack:                          ; the function calling into the stack pointer esp