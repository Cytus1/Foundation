#include <stdio.h>

int main() {
    printf("arithmetic operators\n");
    int a = 10, b = 3;
    printf("addition: a + b = %d\n", a + b);
    printf("subtraction: a - b = %d\n", a - b);
    printf("multiplication: a * b = %d\n", a * b);
    printf("division: a / b = %d\n", a / b);
    printf("modulus: a %% b = %d\n", a % b);

    printf("assignment operators\n");
    int c = 5;
    c += 2;
    printf("c += 2: %d\n", c);
    c -= 1;
    printf("c -= 1: %d\n", c);
    c *= 3;
    printf("c *= 3: %d\n", c);
    c /= 2;
    printf("c /= 2: %d\n", c);
    c %= 3;
    printf("c %%= 3: %d\n", c);

    printf("\nrelational operators\n");
    printf("a == b: %d\n", a == b);
    printf("a != b: %d\n", a != b);
    printf("a > b: %d\n", a > b);
    printf("a < b: %d\n", a < b);
    printf("a >= b: %d\n", a >= b);
    printf("a <= b: %d\n", a <= b);

    printf("\nlogical operators\n");
    int x = 1, y = 0;
    printf("x && y: %d\n", x && y);
    printf("x || y: %d\n", x || y);
    printf("!x: %d\n", !x);

    printf("\nbitwise operators\n");
    int m = 6, n = 3;
    // 6 = 110, 3 = 011
    printf("m & n: %d\n", m & n);
    printf("m | n: %d\n", m | n);
    printf("m ^ n: %d\n", m ^ n);
    printf("~m: %d\n", ~m);
    printf("m << 1: %d\n", m << 1);
    printf("m >> 1: %d\n", m >> 1);

    printf("\nunary operators\n");
    int u = 5;
    printf("u++: %d\n", u++);
    printf("now u: %d\n", u);
    printf("++u: %d\n", ++u);
    printf("u--: %d\n", u--);
    printf("now u: %d\n", u);
    printf("--u: %d\n", --u);

    printf("\nternary operator\n");
    int max = (a > b) ? a : b;
    printf("max of a and b is: %d\n", max);

    printf("\n8. sizeof operator\n");
    printf("size of int: %lu bytes\n", sizeof(int));
    printf("size of char: %lu bytes\n", sizeof(char));
    printf("size of float: %lu bytes\n", sizeof(float));

    printf("\ncomma operator\n");
    int k;
    k = (a = 3, b = 4, a + b);
    printf("result of comma expression: %d\n", k);

    printf("\npointer operators\n");
    int z = 100;
    int* ptr = &z;
    printf("address of z: %p\n", (void*)&z);
    printf("value using pointer: %d\n", *ptr);

    printf("\nstruct member access\n");
    struct point { int x, y; };
    struct point p1 = {2, 3};
    struct point* pptr = &p1;
    printf("using dot: p1.x = %d\n", p1.x);
    printf("using arrow: pptr->y = %d\n", pptr->y);

    return 0;
}
