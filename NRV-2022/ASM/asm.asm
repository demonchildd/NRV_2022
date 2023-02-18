.586
.model flat, stdcall
includelib libucrt.lib
includelib kernel32.lib
includelib ../Debug/StaticLib.lib
ExitProcess PROTO :DWORD

OutputInt PROTO : DWORD
OutputStr PROTO : DWORD
EXTRN Date: proc
EXTRN Time: proc

.stack 4096

.CONST
	overflownum BYTE "Выход за пределы значения", 0
	neguint BYTE "Отрицательное число", 0
	zerodel BYTE "Деление на ноль", 0
	L1 DWORD 1
	L2 DWORD 4
	L3 DWORD 2
	L4 DWORD 1
	L5 BYTE "NRV - 2022", 0
	L6 DWORD 5
	L7 DWORD 9

.data
	count DWORD 0
	sum_c DWORD 0
	check_x DWORD 0
	main_result DWORD 0
	main_date DWORD ?
	main_time DWORD ?
	main_d DWORD 0
	main_s DWORD ?

.code

sum PROC sum_a : DWORD, sum_b : DWORD
	push sum_a
	push sum_b
	pop ebx
	pop eax
	sub eax, ebx
	cmp eax, 255
jg OVERFLOW
	cmp eax, 0
jl NEGNUM
	push eax
	pop sum_c
	push sum_c
	push L1
	pop ecx
CYCLE0:
	pop eax
	shl eax, 1
	cmp eax, 255
jg OVERFLOW
	cmp eax, 0
jl NEGNUM
	push eax
	loop CYCLE0
	pop sum_c
	push sum_c
	jmp local0
local0:
	pop eax
	ret
OVERFLOW:
	push offset overflownum
	call OutputStr
	push 0
	call ExitProcess
NEGNUM:
	push offset neguint
	call OutputStr
	push 0
	call ExitProcess
DELZERO:
	push offset zerodel
	call OutputStr
	push 0
	call ExitProcess
sum ENDP

check PROC 
	push L1
	pop check_x
	push L2
	pop count
	add count, 1
	mov ecx, count
CYCLE100:
	push check_x
	push L3
	pop eax
	pop ebx
	add eax, ebx
	cmp eax, 255
jg OVERFLOW
	cmp eax, 0
jl NEGNUM
	push eax
	pop check_x
	push check_x
	call OutputInt
	dec count
	mov ecx, count
loop CYCLE100
	push L4
	jmp local1
local1:
	pop eax
	ret
OVERFLOW:
	push offset overflownum
	call OutputStr
	push 0
	call ExitProcess
NEGNUM:
	push offset neguint
	call OutputStr
DELZERO:
	push offset zerodel
	call OutputStr
	push 0
	call ExitProcess
check ENDP

news PROC 
	push offset L5
	jmp local2
local2:
	pop eax
	ret
OVERFLOW:
	push offset overflownum
	call OutputStr
	push 0
	call ExitProcess
NEGNUM:
	push offset neguint
	call OutputStr
DELZERO:
	push offset zerodel
	call OutputStr
	push 0
	call ExitProcess
news ENDP

main PROC
	push L6
	push L7
	pop edx
	pop edx
	push L7
	push L6
	call sum
	push eax
	push L1
	pop ecx
CYCLE1:
	pop eax
	shr eax, 1
	cmp eax, 255
jg OVERFLOW
	cmp eax, 0
jl NEGNUM
	push eax
	loop CYCLE1
	pop main_result
	push main_result
	call OutputInt
	call Date
	push eax
	pop main_date
	push main_date
	call OutputStr
	call Time
	push eax
	pop main_time
	push main_time
	call OutputStr
	call check
	push eax
	pop main_d
	call news
	push eax
	pop main_s
	push main_s
	call OutputStr
OutAsm:
	push 0
	call ExitProcess
OVERFLOW:
	push offset overflownum
	call OutputStr
	push 0
	call ExitProcess
NEGNUM:
	push offset neguint
	call OutputStr
DELZERO:
	push offset zerodel
	call OutputStr
	push 0
	call ExitProcess
main ENDP
end main