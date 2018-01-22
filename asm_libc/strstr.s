	section .text
	global strstr

strstr:

	push rbp
	mov rbp, rsp

	mov rax, rdi
	cmp byte[rsi], 0
	je  endall
	xor rdx, rdx
	xor rcx, rcx

loop:
	mov r8b, [rsi]
	cmp byte[rdi + rdx], 0
	je enderr

	cmp byte[rdi + rdx], r8b
	je init_pointer

	inc rdx
	jmp loop

init_pointer:

	mov rax, rdi
	add rax, rdx


loop_other:

	mov r8b, [rsi + rcx]

	cmp r8b, 0
	je endall

	cmp byte[rdi + rdx], 0
	je enderr

	cmp byte[rdi + rdx], r8b
	jne restart

	inc rdx
	inc rcx

	jmp loop_other

restart:

	sub rdx, rcx
	add rdx, 1
	xor rcx, rcx

	jmp loop

endall:

	mov rsp, rbp
	pop rbp

	ret
enderr:

	mov rax, 0

	mov rsp, rbp
	pop rbp

	ret
