	section .text
	global strncmp

strncmp:

	push rbp
	mov rbp, rsp
	xor r8b, r8b
	mov rcx, 1
	cmp rdx, 0
	je ende
	jmp loop

loop:
	mov r8b, [rdi]
	cmp rdx, rcx
	je choose
	cmp  byte[rsi], r8b
	je add
	cmp  byte[rsi], r8b
	jg endg
	cmp  byte[rsi], r8b
	jl endl

add:
	cmp byte[rdi], 0
	je ende
	add rdi, 1
	add rsi, 1
	inc rcx
	jmp loop

choose:
	cmp  byte[rsi], r8b
	je ende
	cmp  byte[rsi], r8b
	jg endg
	cmp  byte[rsi], r8b
	jl endl


endl:
	mov eax, 1
	mov rsp, rbp
	pop rbp
	ret

endg:
	mov eax, -1
	mov rsp, rbp
	pop rbp
	ret


ende:
	mov eax, 0
	mov rsp, rbp
	pop rbp
	ret
