#include "01header.h"

int main(void){
    int a = 10;
    int b = 20;
    int c = 30;
    int d = 40;

    int r1 = (a + b) - (c + d) + 1;
    int r2 = AddSubfasm(a, b, c, d);
    DisplayResults(a, b, c, d, r1, r2);
    return 0;
}

// C:\Program Files\Microsoft Visual Studio\2022\Community> ml64 /c 01AddSubfasm.asm
// C:\Program Files\Microsoft Visual Studio\2022\Community> cl 01main.cpp 01misc.cpp 01AddSubfasm.obj
