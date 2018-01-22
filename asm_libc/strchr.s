	;; char	*strchr(const char *s, int c)
	;; rax		rdi, rsi
	BITS 64

	section	.text
	global	strchr

strchr:
	push	rbp
	mov	rbp, rsp
	mov	r8, rdi
	mov	rax, 0
	cmp	rsi, 0
	je	loop2

loop:
	cmp	byte[r8], 0
	je	end

if:
	cmp	byte[r8], sil
	jne	else
	mov	rax, r8
	jmp	end

else:
	add	r8, 1
	jmp	loop

loop2:
	cmp	byte[r8], 0
	jl	end

if2:
	cmp	byte[r8], sil
	jne	else2
	mov	rax, r8
	jmp	end

else2:
	add	r8, 1
	jmp	loop2

end:
	mov	rsp, rbp
	pop	rbp

	ret
