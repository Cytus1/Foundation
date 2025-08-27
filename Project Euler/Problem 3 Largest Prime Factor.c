#include <stdio.h>


/*
What is the largest prime factor of the number 600851475143?

Solution:
Solved by Pollard's Rho.
The main function is f(x) = (x^2 + 1) mod n, where n is our number.
Our computation is on d, where d = gcd(|x - y|, n) ; x = f(x),    y = f(f(x))

Example: if we have 91, then we do d = gcd(|x - y|, 91)

let x, y = 2
then x = f(2) = (2^2 + 1) = 5, and we use 5 as y
then y = f(5) = (5^2 + 1) = 26
the difference is 21, using gcd (21, 91), we get 7.
Using this alg with the number in problem 3 will give us the answer.

Note: Pollard’s Rho is a probabilistic algorithm, 2 is a seed.
Raising to higher power can increase performance, but also higher chance to fail.
So changing C is prob the best bet.

I used unsign since stuff should just be positive, without it, long long would be in range regardless of complementary trait.
*/


// formula = (x^2 + c) mod n
unsigned long long f(unsigned long long x, unsigned long long c, unsigned long long n) {
    return (x * x + c) % n;
}

// euclidean alg
unsigned long long gcd(unsigned long long x, unsigned long long y){

    // return y == 0 ? x : gcd(y, x % y);  was dump, because stacked a lot = memory waste. this can be instant answer too though.

    while (y != 0) {
        unsigned long long temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}

// this follows by x = f(x), y = f(f(y)), going to the gcd method. return 0 if no factor found
unsigned long long pollards_rho(unsigned long long n, unsigned long long c) {
    if ((n & 1) == 0) return 2;

    unsigned long long x = 2;
    unsigned long long y = 2;
    unsigned long long d = 1;

    while (d == 1) {
        x = f(x, c, n);
        y = f(f(y, c, n), c, n);

        // the difference is the absolute value of x - y formula from note above
        unsigned long long diff = (x > y) ? (x - y) : (y - x);
        d = gcd(diff, n);
    }

    return (d == n) ? 0 : d;
}

int main() {
    unsigned long long n = 600851475143ULL;
    unsigned long long largest = 0;

    while (n > 1) {
        unsigned long long factor = 0;

        // try multiple values of c to avoid pho rho failure, note: it can still fail hehe, but not for this problem
        for (unsigned long long c = 1; c < 10 && factor == 0; c++) {
            factor = pollards_rho(n, c);
        }

        if (factor == 0) {
            printf("failed to find a factor.\n");
            break;
        }

        if (factor > largest)
            largest = factor;

        // divide n out the factor until u can't
        while (n % factor == 0)
            n /= factor;
    }

    if (n > 1 && n > largest)
        largest = n;

    printf("Largest prime factor: %llu\n", largest);
    return 0;
}
