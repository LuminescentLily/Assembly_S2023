extern printf
global main

section .data

format_specifier:
    db '%x',' ',0

line:
    db 10,0

section .text

main:

    mov rbx, 5
    

loop:

    mov rdi, line
    mov rsi, ' '
    xor rax, rax
    call printf

    mov rcx, qword 16

fill:
   
    dec rcx
    push rcx

    mov rdi, format_specifier
    mov rsi, rcx

    xor rax, rax
    call printf
    pop rcx

    cmp rcx, qword 0
    jne fill

    dec rbx
    cmp rbx, 0
    jne loop

    mov rdi, line
    mov rsi, ' '
    xor rax, rax
    call printf
