includelib  C:\Irvine\User32.Lib
includelib  C:\Irvine\Kernel32.Lib
includelib  D:\masm32\lib\Irvine32.lib
include     \masm32\include\Irvine32.inc
; D:/masm32/bin/ml.exe /c  /coff  "D:\asm\simple.asm"
; D:/masm32\bin\link.exe /subsystem:console  "D:\asm\simple.obj"
.data
X Dword  ? 
A dword  ? 
B dword  ?
M dword  ? 
.code
main PROC
mov eax, 1
xor ecx , ecx
xor ebx, ebx
strt:
add eax , 1
mov X, eax
push eax
call simple
cmp ebx, 1
pop eax
je ext
call WriteInt
call CrLF
ext:

cmp eax, 50000000
jb strt

	exit
main ENDP
Simple PROC uses ecx
Mov A, 1
call Sqrt
Mov A , eax
MOV edx , 2
rn:
;push edx
mov ecx, edx

mov eax , X
mov ebx, edx
xor edx ,edx
div ebx 
cmp edx, 0
jne stp
mov ebx ,1
jmp var
stp:
;pop edx
mov edx,ecx
cmp edx, A
inc edx
jb rn
var:
ret
Simple  ENDP
Sqrt PROC USES ebx
  mov A, 1 ;A = 1
  mov  eax ,X
  push eax
  shr  EAX, 5
  add   EAX , 8
  Mov B , EAX
  pop eax
  cmp B,0FFFFh
  jbe crt
  mov B, 0FFFFh
crt:;do {
    mov ebx, B 
	push A
	add A,ebx
	shr A, 1
	mov ebx, A
	pop A
	mov M ,ebx
	mov eax, ebx
	mul ebx
	cmp eax , X
    jbe  opt	
	Mov eax, M
	dec  eax
	mov B , eax
	jmp dz
	opt:
	mov eax, M
	inc  eax
	mov A , eax
	dz:
	mov eax, B
	cmp eax,A
	Jae crt
	mov  eax , A 
	dec eax
	ret
Sqrt  ENDP
 END main
