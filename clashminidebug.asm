.org 80h
inc:
	push %bp
	mov %bp %sp
	sub %sp 0010h
	mov [%bp + FFFEh] %sp
	mov [%bp + FFFCh] %b
	lea %a [%bp + FFFCh]
	mov %a [%a]
	push %a
	inc %a
	pop %si
	mov [%si] %a
	jmp @.return.inc
.return.inc:
	mov %sp %bp
	pop %bp
	ret
main:
	push %bp
	mov %bp %sp
	sub %sp 0010h
	mov [%bp + FFFCh] %sp
	memset [%bp + FFFEh] 0002h 0h
	lea %a [%bp + FFFEh]
	push %a
	mov %a 0000h
	pop %si
	mov [%si] %a
.L.begin.1:
	mov %a 0001h
	cmp %a 0h
	jz @.0
	lea %a [%bp + FFFEh]
	push %a
	pop %b
	call @inc
	push %a
	mov %a 0050h
	pop %si
	cmp %si %a
	jgz @.compare3
	mov %al 1h
	.compare3:
	mov %ah 0h
	cmp %a 0h
	jz  @.else.2
	jmp @.0
	jmp @.end.2
.else.2:
.end.2:
.1:
	jmp @.L.begin.1
.0:
.return.main:
	mov %sp %bp
	pop %bp
	ret
start:
	mov %sp FFFFh
	call @main
.return.start:
	int 0h

<-------------------->

short inc(short* i)
{
	return ++(*i);
}

void main(void)
{
	short i = 0s;
	while(1) 
	{
		if(inc(&i) > 0x50)
			break;
	}
}

void start(void)
{
	asm("mov %sp FFFFh");
	main();
}
