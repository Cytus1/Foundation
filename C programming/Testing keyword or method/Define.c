#include <stdio.h>

/*
#define NAME value
can also define macros
*/

#define value 1

#define add(x, y) ((x) + (y))
#define isOdd(x) do { \
    if ((x) % 2 != 0) \
        printf("%d is odd\n", (x)); \
    else \
        printf("%d is even\n", (x)); \
} while(0)

int main() {
    printf("%d\n", value);
    printf("1 + 2 = %d\n", add(1, 2));
    printf("10 * (1 + 2) = %d\n", 10 * add(1, 2));
    isOdd(3);
    isOdd(4);
    return 0;
}
