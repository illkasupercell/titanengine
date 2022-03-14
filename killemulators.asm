format PE64 GUI 5.0
include 'win64a.inc'
entry $
   xor    rdi,rdi
   push   rdi
   push   rdi
   push   rdi;$400000
   push   rdi
   push   rdi
   mov    rax,CW_USEDEFAULT
   push   rax
   push   rax
   push   rax
   push   rax
   push   rdi
   push   rdi
   push   rdi
   push   rdi
   mov    r9,WS_VISIBLE+WS_OVERLAPPEDWINDOW
   mov    r8,_title
   mov    rdx,_class
   mov    rcx,rdi
   call   [CreateWindowEx]
   mov    r8,WindowProc
   mov    rdx,-4
   mov    rcx,rax
   call   [SetWindowLongPtrA]
   mov    qword[_title],rax
   pop    rdi
   mov    rsi,rsp
   xor    rbx,rbx
   mov    bl,40
@@:sub    rsp,rbx
   xor    r9,r9
   xor    r8,r8
   xor    rdx,rdx
   mov    rcx,rsi
   call   [GetMessage]
   mov    rcx,rsi
   call   [DispatchMessage]
   add    rsp,rbx
   jmp    @b
WindowProc:
   push   r9
   cmp    rdx,WM_CLOSE
   je     app_close
defwndproc:
   push   rdi
   push   rdi
   push   rdi
   push   rdi
   mov    r9,r8
   mov    r8,rdx
   mov    rdx,rcx
   mov    rcx,qword[_title]
   call   [CallWindowProc]
   pop    rdi
   pop    rdi
   pop    rdi
   pop    rdi
   pop    rdi
   ret
app_close:
   call   [exit]
  _title db '1KBytex64',0
  _class db '#32770',0
data import
  library\
    user32,'USER32.DLL',\
    msvcrt,'msvcrt.dll'
  include 'api\user32.inc'
  import msvcrt,\
    exit,'_exit'
end data
