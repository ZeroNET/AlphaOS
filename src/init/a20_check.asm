[bits 16]
[global a20_check]

a20_check:
	xor eax, eax
	inc eax
	mov eax, 0x000000 
	cmp eax, 0x100000
	
	mov ax, 0
	jne exit_a20
	mov ax, 1

exit_a20:
	ret
