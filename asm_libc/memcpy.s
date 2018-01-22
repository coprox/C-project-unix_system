	BITS 64

	section	.text
	global	memcpy

memcpy:
	push	rbp
	mov	rbp, rsp

	mov	rax, rdi 	;save address beggining
	xor	rcx, rcx

while:
	cmp	rdi, rsi
	je	end
	cmp	rcx, rdx
	jge	end

	mov	r10b, [rsi + rcx]
	mov	[rdi + rcx], r10b
	add	rcx, 1
	jmp	while

end:
	mov	rsp, rbp
	pop	rbp

	ret
