	section .text
	global strlen

strlen:

	push rbp
	mov rbp, rsp
	xor ecx, ecx
	jmp loop

loop:
	cmp byte[rdi], 0
	je end

	add rdi, 1
	inc ecx

	jmp loop

end:
	mov eax, ecx
	mov rsp, rbp
	pop rbp

	ret
