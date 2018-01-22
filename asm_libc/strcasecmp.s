	section .text
	global strcasecmp

strcasecmp:

	mov r8b, [rsi]
	mov r9b, [rdi]

	cmp r9b, 0
	je check_condition_rsi

	cmp r9b, r8b
	jne check_condition_rdi

	add rdi, 1
	add rsi, 1

	jmp strcasecmp

check_condition_rdi:

	cmp r9b, 65
	jl check_condition_rsi

	cmp r9b, 90
	jg check_condition_rsi

	add r9b, 32

	cmp r9b, r8b
	jne check_condition_rsi

	add rdi, 1
	add rsi, 1

	jmp strcasecmp

check_condition_rsi:

	cmp r8b, 65
	jl end_sub

	cmp r8b, 90
	jg end_sub

	add r8b, 32

	cmp r9b, r8b
	jne end_sub

	add rdi, 1
	add rsi, 1

	cmp r9b, 0
	je end_sub

	jmp strcasecmp

end_sub:


	sub r9b , r8b
	movsx rax, r9b

	ret
