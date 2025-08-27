#include <stdio.h>

/*
this tells the compiler that you want this value to be in the register
however, the compiler does the optimization
*/

int main(void){
    register int var;
    return 0;
}