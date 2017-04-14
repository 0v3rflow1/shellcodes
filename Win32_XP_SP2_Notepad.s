global _start
_start:
	xor eax,eax
	xor edx,edx
	push edx
	mov al,"e"
	push ax
	mov ax,"ex"
	push ax
	push "pad."
	push "note"
	mov eax,esp
	push 1
	push eax
	mov ebx,0x7c86114d ; mov ebx,kernel32.WinExec
	call ebx
	push 1
	mov ebx,0x7c81caa2 ; mov ebx,kernel32.ExitProcess
	call ebx
