	section .text
	global rindex

rindex:
	push rbp
	mov rbp, rsp
	xor rcx, rcx
	cmp rsi, 0
	je end_loop

count:
	cmp byte [rdi + rcx], 0
	je loop
	inc rcx
	jmp count

loop:
	cmp rcx, -1
	je endiff
	cmp byte [rdi + rcx], sil
	je endit
	dec rcx
	jmp loop

endit:
	add rdi, rcx
	mov rax, rdi
	mov rsp, rbp
	pop rbp
	ret


end_loop:

	cmp byte[rdi], 0
	je enderr
	add rdi, 1
	jmp end_loop

enderr:
	mov rax, rdi
	mov rsp, rbp
	pop rbp
	ret

endiff:
	mov rax, 0
	mov rsp, rbp
	pop rbp
	ret
