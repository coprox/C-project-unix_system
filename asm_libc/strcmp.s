	section .text
	global strcmp

strcmp:

	push rbp
	mov rbp, rsp
	jmp loop

loop:
	mov r8b, [rdi]
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
	jmp loop


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
