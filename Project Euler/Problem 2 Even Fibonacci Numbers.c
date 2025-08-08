#include <stdio.h>

/*
By considering the terms in the Fibonacci sequence whose value do not exceed four million,
find the sum of even-valued terms.

Solution:
I notice the parity pattern being odd odd, even, odd odd, even, odd odd, even... (0, 1, 1, 2, 3, 5, 8...)
Let E stands for even and F stands for fib

E(1) = F(3)  = 2  
E(2) = F(6)  = 8  
E(3) = F(9)  = 34  
E(4) = F(12) = 144  
...

We know F(n) = F(n - 1) + F(n - 2)，and we need E(n). Where F（3n) = E(n)
Taking a look at E(n): 2， 8， 34, 144...
I notice 4E(n-1) + E(n-2) = E(n)

So we can use this formula for a faster approach
*/

int main() {
    register int a = 2;             // E(n-2)
    register int b = 8;             // E(n-1)
    register int sum = a + b;
    register int next = 4 * b + a;  // E(n)

    while (next <= 4000000) {
        sum += next;
        a = b;
        b = next;
        next = 4 * b + a;
    }

    printf("Sum = %d\n", sum);
    return 0;
}