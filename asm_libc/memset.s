	;; void	*memset(void *s, int c, size_t n)
	;; rax		rdi, rsi, rdx

	BITS 64

	section	.text
	global	memset

memset:
	push	rbp
	mov	rbp, rsp
	mov	r8, rdi
	xor	rcx, rcx

while:
	cmp	rdx, rcx
	je	end

	mov	[r8], sil
	add	rcx, 1
	add	r8, 1
	jmp	while

end:
	mov	rax, rdi
	mov	rsp, rbp
	pop	rbp

	ret
