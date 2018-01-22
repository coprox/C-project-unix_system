	section .text
	global strcspn

strcspn:
	push rbp
	mov rbp, rsp
	mov rdx, -1

loop_s:
	xor rcx, rcx
	inc rdx
	mov r8b, [rdi + rdx]

	cmp r8b, 0
	je end

loop_reject:

	cmp r8b, byte[rsi + rcx]
	je end

	cmp byte[rsi + rcx], 0
	je loop_s

	inc rcx
	jmp loop_reject


end:
	mov rax, rdx

	mov rsp, rbp
	pop rbp

	ret
