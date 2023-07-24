extern printf
global main
section .data
format_string:
 db '%s',10,0
format_float:
 db '%f',10,0
format_int:
 db '%d',10,0
format_line:
 db 10,0
number:
 dq 240.25
struc Roommate
 s_name resb 25
 f_rent resb 30 ;make function to update rent
 i_age resb 10
 c_room resb 5
 a_chores resb 50 ;array of strings
endstruc
lumi istruc Roommate
 at s_name, db 'Lumi Nottia',
 at f_rent, dq 350.75
 at i_age, dw 23
 at c_room, dw 'B',
 at a_chores, db 'Dishes ', 'Sweep ', 'Trash ', 'Vaccum ', 'Groceries'
iend
section .text
main:
 mov rbx,2
loop:
 dec rbx
 mov rdi, format_string
 mov rsi, lumi + s_name ;lumi is the location of the struct and s_name is the
location of the name
 xor rax, rax
 call printf
 push rbp
 movsd xmm0, [lumi + f_rent]
 mov rdi, format_float
 mov rax, 1
 call printf
 pop rbp
 mov rdi, format_int
 mov rsi, [lumi + i_age]
 xor rax, rax
 call printf
 mov rdi, format_string
 mov rsi, lumi + c_room
 xor rax, rax
 call printf
 mov rdi, format_string
 mov rsi, lumi + a_chores
 xor rax, rax
 call printf
 mov rdi, format_line
 mov rsi, ' '
 xor rax, rax
 call printf
function: ;function to change the number of the rent

 movsd xmm0, [number]
 movsd qword [lumi + f_rent], xmm0

 cmp rbx, 0
 jne loop
