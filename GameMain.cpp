const int sum(int a, int b){
    return a+b;
}

int a(int x)
{
    const std::function<int(int)> sum4 = std::bind(sum,_1, 4);    
    return sum4(123);
}

int b(int x)
{
    puts("bagor");    
    const std::function<int(int)> sum4 = std::bind(sum,_1, 4);    
    return sum4(123);
}

int c(int x)
{
    const std::function<int(int)> sum4 = std::bind(sum,_1, 4);    
    puts("bagor");    
    return sum4(123);
}


sum(int, int):                               # @sum(int, int)
        lea     eax, [rdi + rsi]
        ret
a(int):                                  # @a(int)
        mov     eax, 127
        ret
b(int):                                  # @b(int)
        push    rax
        mov     edi, offset .L.str
        call    puts
        mov     eax, 127
        pop     rcx
        ret


c(int):                                  # @c(int)
        push    rbx
        sub     rsp, 32
        mov     edi, 16
        call    operator new(unsigned long)
        mov     rbx, rax
        mov     qword ptr [rax], offset sum(int, int)
        mov     dword ptr [rax + 8], 4
        mov     qword ptr [rsp], rax
        mov     qword ptr [rsp + 24], offset std::_Function_handler<int (int), std::_Bind<int const (*(std::_Placeholder<1>, int))(int, int)> >::_M_invoke(std::_Any_data const&, int&&)
        mov     qword ptr [rsp + 16], offset std::_Function_handler<int (int), std::_Bind<int const (*(std::_Placeholder<1>, int))(int, int)> >::_M_manager(std::_Any_data&, std::_Any_data const&, std::_Manager_operation)
        mov     edi, offset .L.str
        call    puts
        mov     esi, dword ptr [rbx + 8]
        mov     edi, 123
        call    qword ptr [rbx]
        mov     ebx, eax
        mov     rax, qword ptr [rsp + 16]
        test    rax, rax
        je      .LBB3_3
        mov     rdi, rsp
        mov     rsi, rdi
        mov     edx, 3
        call    rax
.LBB3_3:
        mov     eax, ebx
        add     rsp, 32
        pop     rbx
        ret
        mov     rdi, rax
        call    __clang_call_terminate
        mov     rbx, rax
        mov     rax, qword ptr [rsp + 16]
        test    rax, rax
        je      .LBB3_6
        mov     rdi, rsp
        mov     rsi, rdi
        mov     edx, 3
        call    rax
.LBB3_6:
        mov     rdi, rbx
        call    _Unwind_Resume@PLT
        mov     rdi, rax
        call    __clang_call_terminate
__clang_call_terminate:                 # @__clang_call_terminate
        push    rax
        call    __cxa_begin_catch
        call    std::terminate()
std::_Function_handler<int (int), std::_Bind<int const (*(std::_Placeholder<1>, int))(int, int)> >::_M_invoke(std::_Any_data const&, int&&): # @std::_Function_handler<int (int), std::_Bind<int const (*(std::_Placeholder<1>, int))(int, int)> >::_M_invoke(std::_Any_data const&, int&&)
        mov     rax, qword ptr [rdi]
        mov     rcx, qword ptr [rax]
        mov     edi, dword ptr [rsi]
        mov     esi, dword ptr [rax + 8]
        jmp     rcx                             # TAILCALL
std::_Function_handler<int (int), std::_Bind<int const (*(std::_Placeholder<1>, int))(int, int)> >::_M_manager(std::_Any_data&, std::_Any_data const&, std::_Manager_operation): # @std::_Function_handler<int (int), std::_Bind<int const (*(std::_Placeholder<1>, int))(int, int)> >::_M_manager(std::_Any_data&, std::_Any_data const&, std::_Manager_operation)
