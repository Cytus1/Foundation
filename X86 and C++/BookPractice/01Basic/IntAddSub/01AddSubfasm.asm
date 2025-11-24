.code

AddSubfasm proc

    add ecx, edx
    add r8d, r9d
    sub ecx, r8d
    add ecx, 1

    mov eax, ecx

    ret

AddSubfasm endp

end