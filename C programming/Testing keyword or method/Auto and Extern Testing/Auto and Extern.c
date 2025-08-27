#include <stdio.h>

/*
auto stands for automatic, meaning the var will be destroyed after at the end.
If random value will be given if no value is assign  ( can diff base on gcc ver).


extern means to find the value where the variable is at another file. this process is automatically done by the compiler.
*/

extern int var123;

int main(void){
    auto int var = 0;
    printf("var123 = %d", var123);
    return 0;
}
