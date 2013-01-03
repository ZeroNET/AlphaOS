[bits 16]

setup_paging:
	mov eax, 0x7c00
	mov cr3, eax

	mov eax, cr0
	or eax, 0x80000000
	mov cr0, eax
	ret

enable_pse:
	mov eax, cr4
	or eax, 0x00000010
	mov cr4, eax
	ret

