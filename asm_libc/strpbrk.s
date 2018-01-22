	section .text
	global strpbrk

strpbrk:

	push rbp
	mov rbp, rsp
	mov rcx, -1

loop_s:
	xor rdx, rdx
	inc rcx
	mov r8b, [rdi + rcx]

	cmp r8b, 0
	je enderr

loop_accept:

	cmp r8b, byte[rsi + rdx]
	je end

	cmp byte[rsi + rdx], 0
	je loop_s

	inc rdx
	jmp loop_accept


end:
	add rdi, rcx
	mov rax, rdi

	mov rsp, rbp
	pop rbp

	ret
enderr:
	mov rax, 0

	mov rsp, rbp
	pop rbp

	ret
