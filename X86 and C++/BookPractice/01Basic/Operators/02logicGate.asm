.code

LogicGateU32_a proc

    mov     rax, rcx        ; a AND b
    and     rax, rdx

    mov     rbx, rcx        ; a OR b
    or      rbx, rdx
    or      rax, rbx

    mov     rbx, rcx        ; XOR ab
    xor     rbx, rdx
    or      rax, rbx

    mov     rbx, rcx        ; NOT a
    not     rbx
    or      rax, rbx

    mov     rbx, rdx        ; NOT b
    not     rbx
    or      rax, rbx

    mov     rbx, rcx        ; NAND ab
    and     rbx, rdx
    not     rbx
    or      rax, rbx

    mov     rbx, rcx        ; NOR ab
    or      rbx, rdx
    not     rbx
    or      rax, rbx

    mov     rbx, rcx        ; XNOR ab
    xor     rbx, rdx
    not     rbx
    or      rax, rbx

    ret

LogicGateU32_a endp

end
