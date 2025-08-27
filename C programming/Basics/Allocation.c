#include <stdio.h>
#include <stdlib.h>

/*
note: <stdlib.h> fix implict warning on used lib function malloc, calloc, realloc, and free()

malloc makes memory content with uninitialized value, where uninitialized values are random number.
example: int *arr = malloc(5 * sizeof(int));  will allocates memory for 5 ints

calloc makes memory content with all zero
int *arr = calloc(5, sizeof(int));  will allocates memory for 5 ints, all = 0

realloc resizes size of memory
arr = realloc(arr, 10 * sizeof(int));  will resize to hold 10 ints
*/

// static allocation
int global_static = 42;           // global in the file, static as only can be call in the file
static int file_static = 99;      // in scope of a file, which is static

// automatic (Stack) Allocation with recursion, depth is just the amount of calls
// when the function returns, this frame is popped off the stack
void stack_recursion_demo(int depth) {
    int local_stack = depth;  // lives in this call’s stack frame, which is how stack overflow can occur in some files

    printf("[Stack] depth= %d local_stack= %d (address: %p)\n",
           depth, local_stack, (void*)&local_stack);

    if (depth > 0) {
        stack_recursion_demo(depth - 1);
    }
}

// dynamic (Heap) allocation --------
void heap_allocation_demo(size_t n) {
    int *arr = malloc(n * sizeof *arr);

    if (!arr) {
        printf("[Heap] Allocation failed!\n");
        return;
    }

    for (size_t i = 0; i < n; i++) {
        arr[i] = (int)(i * 10);
        printf("[Heap] arr[%zu] = %d (address: %p)\n", i, arr[i], (void*)&arr[i]);
    }

    free(arr);
}

int main(void) {
    printf("[Static] global_static = %d (address: %p)\n", global_static, (void*)&global_static);
    printf("[Static] file_static   = %d (address: %p)\n", file_static, (void*)&file_static);

    stack_recursion_demo(3);

    heap_allocation_demo(5);

    return 0;
}
