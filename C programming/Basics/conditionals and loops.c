#include <stdio.h>

void ifelse(){
    int x = 10;
    if (x > 0)
        printf("x is positive\n");
    else
        printf("x is zero or negative\n");
}

void elseifchain(){
    int score = 85;
    if (score >= 90)
        printf("grade: a\n");
    else if (score >= 80)
        printf("grade: b\n");
    else
        printf("grade: c or below\n");
}

void nestedif(){
    int a = 5;
    int b = 10;
    if (a < b) {
        if (b - a > 3)
            printf("b is much greater than a\n");
    }
}

void ternary(){
    int a = 5, b = 8;
    int max = (a > b) ? a : b;
    printf("max is %d\n", max);
}

void switchcase(){
    int day = 2;
    switch (day) {
        case 1: printf("monday\n"); break;
        case 2: printf("tuesday\n"); break;
        default: printf("other day\n"); break;
    }
}

void whileloop(){
    int i = 0;
    while (i < 3) {
        printf("while loop i = %d\n", i);
        i++;
    }
}

void dowhileloop(){
    int j = 0;
    do {
        printf("do while loop j = %d\n", j);
        j++;
    } while (j < 3);
}

void forloop(){
    for (int i = 0; i < 3; i++) {
        printf("for loop i = %d\n", i);
    }
}

void nestedloops(){
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("i = %d, j = %d\n", i, j);
        }
    }
}

void infiniteloopdemo(){
    int count = 0;
    while (1) {
        printf("infinite loop demo count = %d\n", count);
        count++;
        if (count >= 2)
            break;
    }
}

void usecontinue(){
    for (int i = 0; i < 5; i++) {
        if (i == 2)
            continue;
        printf("i = %d\n", i);
    }
}

int main(){
    ifelse();
    elseifchain();
    nestedif();
    ternary();
    switchcase();
    whileloop();
    dowhileloop();
    forloop();
    nestedloops();
    infiniteloopdemo();
    usecontinue();
    return 0;
}
