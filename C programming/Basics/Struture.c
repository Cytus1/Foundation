#include <stdio.h>

/*
the struct keyword is used to define a structure,
which is a user-defined data type that groups related
variables (of potentially different types) under a single name.
*/

struct myStruct {
    int age;
    char myString [10];
};


int main(void){

    struct myStruct Kid = {10, "Bob"};
    printf("Kid name: %s\n Kid age: %d\n", Kid.myString, Kid.age);
    return 0;
}
