#include <stdio.h>

/*
scanf = Scan Formatted string
(get datatype using %, & for get reference base on memory address and store)
*/

int main(void){
    int a;
    int b;
    printf("Get first num\n");   scanf("%d", a);
    printf("Get second num\n");  scanf("%d", b);
    printf("a is %d, b is %d", a, b);
    return 0;
}
