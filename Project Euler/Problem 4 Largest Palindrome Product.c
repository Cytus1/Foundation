#include <stdio.h>

/*
Find the largest palindrome made from the product of two 3-digit numbers.
Solution:
On paper, I define the range of being (100^2, 999^2). Since the max is 998001, I assume the max palindrome to be start with a 9, and 6 digit.
I represented this as palindrome n = fedcba, where each letter is the number. We can see f = 100000 * a, e = 10000 * a...
So we can say N = 100001*a + 10010*b + 1100*c, where a can not by 0.
*/


int isPalindrome(int n) {
    register int rev = 0, temp = n; // deepcopy because pass by value, rev for reverse
    while (temp) {
        register rev = rev * 10 + temp % 10;
        temp /= 10;
    }
    return n == rev;
}

int main() {
    register max = 0;
    register int x = 0, y = 0;

    for (int a = 999; a >= 100; a--) {
        int step = (a % 11 == 0) ? 1 : 11;
        for (int b = 999; b >= 100; b -= step) {
            int p = a * b;
            if (p <= max) break;
            if (isPalindrome(p)) {
                max = p; x = a; y = b;
            }
        }
    }
    
    printf("Largest palindrome: %d = %d x %d\n", max, x, y);
    return 0;
}
