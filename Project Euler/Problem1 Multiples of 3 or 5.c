#include <stdio.h>
/*
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum
of these multiples is 23. Find the sum of all the multiples of 3 or 5 below 1000.

Solution:
Solved by using the sum formula, with inclusion-exclusion principle.
Multiple of S3 + S5 - S15 gives the answer.
*/

// k = n of term, return is the sum formula * the multiple
int sum_of_multiples(int n, int limit) {
    int k = (limit) / n;
    return n * k * (k + 1) / 2;
}

int main(){
    int limit = 999;
    int sum3 = sum_of_multiples(3, limit);
    int sum5 = sum_of_multiples(5, limit);
    int sum15 = sum_of_multiples(15, limit);

    int total = sum3 + sum5 - sum15;

    printf("Sum of multiples of 3 or 5 below %d = %d\n", limit, total);
    return 0;
}
