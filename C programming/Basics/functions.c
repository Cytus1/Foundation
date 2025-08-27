#include <stdio.h>


// header (prototype/declaration)
int add(int a, int b);

// source (definition)
int add(int a, int b) { return a + b; }

// C call by value, not reference， so we can use pointers to swap using 3 addresses
void swap(int *x, int *y) { int t = *x; *x = *y; *y = t; }

// no return value
void hello(void) { puts("hi"); }


double area(double w, double h) { return w * h; }


// function that allocates memory on the heap for an array of n integers, initializes them to zero, and returns a pointer to that memory.
// note: reserving a block of memory for program to use
int *make_array(size_t n){
    int *p = malloc(n * sizeof *p);
    if (!p) return NULL;
    for (size_t i=0;i<n;i++) p[i]=0;
    return p;
}

int main(void) {
    int s = add(2, 3);
    printf("s: %d\n", s);

    int a = 0, b = 1;
    printf("a: %d, b:%d\n", a, b);
    swap(&a, &b);
    printf("a: %d, b:%d\n", a, b);

    size_t n = 5;
    int *arr = make_array(n);

    if (!arr) {
        printf("Allocation failed!\n");
        return 1;
    }

    for (size_t i = 0; i < n; i++) {
        printf("%d ", arr[i]);   // prints 0 0 0 0 0
    }
    printf("\n");

    return 0;
}
