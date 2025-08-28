#include <stdio.h>
#include <string.h>

/*
Kid (struct) byte size = age (4 bytes) + name (10 bytes) + padding (2 bytes)
Person (union): special
age = 4 bytes
name = 10 bytes
the largest is 10, but due to compiler, it often rounds up to mult of 4. So instead of 10, it round up to 12.

Structure can have all data all the time, union however all member shares the same memory location.
*/

struct Kid {
    int age;
    char name[10];
};


union Person {
    int age;
    char name[10];
};


int main(void) {
    puts("Single Struct");  // note, single and array are both at reference kid
    struct Kid kid1 = {10, "Bob"};
    printf("name: %s, age: %d\n", kid1.name, kid1.age);
    struct Kid kids[2] = {
        {8, "Amy"},
        {11, "Chris"}
    };
    printf("\nArray of structs:\n");
    printf("kids[0]  name: %s, age: %d\n", kids[0].name, kids[0].age);
    printf("kids[1]  name: %s, age: %d\n", kids[1].name, kids[1].age);

    union Person u1;
    u1.age = 20;
    printf("\n[union] age: %d\n", u1.age);

    strcpy(u1.name, "Tom"); // tested strcpy function, i suppose it copy string tom and overwrite the memory on reference name, so int become nonsense.
    printf("[union] name: %s\n", u1.name);
    printf("[union] age after writing name: %d\n", u1.age);

    // size of struct and union
    printf("\nSize of struct: %zu\n", sizeof(struct Kid));
    printf("Size of union : %zu\n", sizeof(union Person));

    return 0;
}
