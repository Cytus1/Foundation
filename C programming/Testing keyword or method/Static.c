#include <stdio.h>

/*
Static subject will be remember in that method or class.
*/

int getNum(){
    static int num = 1;
    num += 1;
    return num;
}

int main(void){
    for (int i = 0; i < 3; i++){
        int var = getNum();
        printf("%d\n", var);
    }
    return 0;
}
