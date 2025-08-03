#include <stdio.h>
#include <limits.h>

int main() {
    // Using 'short' to easily observe 16-bit behavior
    short x = 1234;
    short neg_x = -x;

    printf("x         = %d\n", x);
    printf("-x        = %d\n", neg_x);
    printf("x (hex)   = 0x%x\n", (unsigned short)x);
    printf("-x (hex)  = 0x%x\n", (unsigned short)neg_x);

    // Show short type limits
    short max = SHRT_MAX;  //  32767 (0111 1111 1111 1111)
    short min = SHRT_MIN;  // -32768 (1000 0000 0000 0000)

    printf("SHRT_MAX      = %d\n", max);
    printf("SHRT_MAX + 1  = %d (overflow)\n", (short)(max + 1));
    printf("SHRT_MIN - 1  = %d (underflow)\n", (short)(min - 1));

    return 0;
}
