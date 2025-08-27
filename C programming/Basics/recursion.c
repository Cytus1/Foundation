#include <stdio.h>

int recursion (int call_amount) {
    int static n = 0; n += 1 ; printf("%d\n", n);
    if (call_amount > 1) {
        recursion(call_amount - 1);
    }
    return n;
}


int main(void){
    recursion(5);
    return 0;
}
