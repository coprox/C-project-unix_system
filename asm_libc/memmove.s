	;; void	*memmove(void *dest, const void *src, size_t n)
	;; RAX			RDI,RSI,RDX
	BITS 64

	section .text
	global	memmove

memmove:
	push	rbp
	mov	rbp, rsp
	mov	rax, rdi 	;save pointer to return

	mov	r8, rsi
	sub	r8, rdi
	cmp	r8, 0
	jge	copy_from_beg

copy_from_end:
	mov	rcx, rdx
	sub	rcx, 1
	
loop1:
	cmp	rcx, 0
	jl	end

	mov	r9b, [rsi + rcx]
	mov	[rdi + rcx], r9b
	sub	rcx, 1
	jmp	loop1

copy_from_beg:
	xor	rcx, rcx
	mov	r10, rdx
loop2:
	cmp	rcx, r10
	je	end

	mov	r9b, [rsi + rcx]
	mov	[rdi + rcx], r9b
	add	rcx, 1
	jmp	loop2

end:
	mov	rsp, rbp
	pop	rbp

	ret
