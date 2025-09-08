#include <stdio.h>
#include <stdlib.h>


// malloc = random value, calloc = set 0, realloc = resize
// note: sizeof is a compile-time type query, not a runtime

int main(void){
    int *pointer = malloc(5 * sizeof *pointer);

    if (pointer == NULL) {
        printf("Memory allocation Failed");
        exit(0);
    }

    printf("Size of *pointer: %d\n", sizeof(*pointer));
    for(int i = 0; i< 5; i++){
        pointer[i] = i + 1;
    }

    for(int i = 0; i < 5; i++){
        printf(("Element [%d]: %d\n"), i, pointer[i]);
    }

    printf("[After shuffle in value] Size of *pointer: %d\n", sizeof(*pointer));
    // if you free , then the reference is gone, and the code below will all not execute, without warning.
    //free(pointer);
    printf("[After free value] Size of *pointer: %d\n", sizeof(*pointer));

    int *tmp = realloc(pointer, 8 * sizeof *pointer);
    if (!tmp) {           // on failure, ptr is still valid
        fprintf(stderr, "realloc failed; keeping original 5 elements\n"); // note, fprintf sends error message to term
        free(pointer);
        return EXIT_FAILURE;
    }
    pointer = tmp;

    // init new slots
    for (int i = 5; i < 8; i++) {
        pointer[i] = (i + 1) * 10;
    }

    puts("After realloc to 8:");
    for (int i = 0; i < 8; i++) {
        printf("Element [%d]: %d\n", i, pointer[i]);
    }

    //still print the same type sizes; it do NOT reflect heap state.
    free(pointer); pointer = NULL;
    printf("[Freed] Size of *pointer: %d\n", sizeof(*pointer));
    return 0;
}
