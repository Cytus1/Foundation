#include <stdio.h> 

/*
Declaration: property of variable to compiler.
Properties:  size, name.
Definition:  allocating memory to a variable.

Note: Modifier is dominant over declaration and definition.
Type modifiers like const, static, unsigned, register, etc. affect how a variable behaves more than just the declaration or definition itself.
*/

int global_var = 100;

void show_static() {
    static int counter = 0; // persists across calls, unlike regular local vars
    counter++;
    printf("static counter = %d\n", counter);
}

int main() {

    // 1. Declaration + Definition + Initialization
    int normal_var = 42; // Arbitrary integer, test/demo value
    printf("normal_var = %d\n", normal_var);

    // 2. Constant variable (read only after initialization)
    const int const_var = 10;
    printf("const_var = %d\n", const_var);
    // const_var = 20; // Uncommenting this will cause a compile-time error

    // 3. Unsigned types, or complementary
    // The range of any unsigned (U) should be 0 to 2^w - 1
    // For signed (complementary), range is –2^(w–1) to 2^(w–1) – 1
    unsigned int u = 3000000000U;
    printf("unsigned int u = %u\n", u);

    // 4. Short and long
    short s = -12345;
    long l = 1234567890L;
    printf("short s = %hd, long l = %ld\n", s, l);

    // 5. Float and double
    float f = 3.14f;
    double d = 2.7182818284;
    printf("float f = %.2f, double d = %.10f\n", f, d);

    // 6. Char and variations
    char c = 'A'; // ASCII char = 65, so no error base on its range

    // char is 8 bits
    // signed char: range = -128 to 127
    // unsigned char: range = 0 to 255

    signed char sc_min = -128;     // minimum valid signed 8-bit
    signed char sc_max = 127;      // maximum valid signed 8-bit
    signed char sc_overflow = 128; // overflow! stored as -128 due to wraparound

    unsigned char uc_normal = 128; // valid in unsigned 8-bit range

    printf("signed char min  = %d\n", sc_min);       // -128
    printf("signed char max  = %d\n", sc_max);       // 127
    printf("signed char 128  = %d (overflow)\n", sc_overflow); // -128 (overflow)
    printf("unsigned char 128 = %u\n", uc_normal);   // 128

    // This shows misrepresentation on overflow, but binary info is kept.

    // 7. Static variable (shows persistence across function calls)
    show_static();
    show_static();

    // 8. Register variable (suggests storing in a fast CPU register)
    register int r = 7;
    printf("register r = %d\n", r);
    // printf("&r = %p\n", &r); // Error: can't take address of register variable

    // 9. Global variable access
    printf("global_var = %d\n", global_var);

    return 0;
}
