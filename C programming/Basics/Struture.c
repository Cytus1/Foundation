#include <stdio.h>

struct myStruct {
    int age;
    char myString [10];
};


int main(void){

    struct myStruct Kid = {10, "Bob"};
    printf("Kid name: %s\n Kid age: %d\n", Kid.myString, Kid.age);
    return 0;
}
