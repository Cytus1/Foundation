#include <stdio.h>
#include <limits.h>

int main() {
    // Signed integer overflow
    int a = INT_MAX;    // a =  2147483647 (0x7FFFFFFF)
    int b = 1;
    int sum = a + b;    // OVERFLOW: wraps to INT_MIN (0x80000000)

    printf("Signed overflow:\n");
    printf("INT_MAX + 1 = %d (undefined behavior)\n\n", sum);
    // Expected: INT_MAX + 1 = -2147483648 (may vary by platform)

    // Unsigned integer overflow (wraparound is defined)
    unsigned int ua = UINT_MAX;  // ua = 4294967295 (0xFFFFFFFF)
    unsigned int ub = 1;
    unsigned int usum = ua + ub; // Wraps around to 0 (mod 2^32)

    printf("Unsigned wraparound:\n");
    printf("UINT_MAX + 1 = %u (wraps to 0)\n\n", usum);
    // Expected: UINT_MAX + 1 = 0

    // Integer division truncates toward zero
    int x = 7, y = 3;
    printf("Integer division:\n");
    printf("7 / 3 = %d\n", x / y);   // 7 / 3 = 2
    printf("7 %% 3 = %d\n\n", x % y); // 7 % 3 = 1

    // Negative dividend case
    x = -7;
    printf("Negative division:\n");
    printf("-7 / 3 = %d\n", x / y);   // -7 / 3 = -2 (truncates toward 0)
    printf("-7 %% 3 = %d\n", x % y);  // -7 % 3 = -1 (same sign as dividend)

    return 0;
}
