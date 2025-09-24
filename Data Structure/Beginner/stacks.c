#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXSIZE 5


struct Stack {
    int items[MAXSIZE];
    int top;
};

struct Stack* createStack() {
    struct Stack* Stack = (struct Stack*)malloc(sizeof(struct Stack));
    Stack -> top = -1;
    return Stack;
}

bool isEmpty(struct Stack* Stack){
    return Stack -> top == -1;
}

bool isFull(struct Stack* Stack){
    return Stack -> top == MAXSIZE - 1;
}

void push(struct Stack* Stack, int data){
    if      (isEmpty(Stack)) {return;}
    else if (isFull (Stack)) {return;}
    else {
        Stack -> top = Stack -> top++;
        Stack -> items[Stack -> top] = data;
    }
}

void peek(struct Stack* Stack){
    if      (isEmpty(Stack)) {return;}
    printf("The top data is : %d\n", Stack -> items[Stack -> top]);
}

int main (void){
    // struct Stack* stack;
    // initStack(&stack);

    struct Stack* stack = createStack();

    for (int i = 0; i < 5; i++){
        push(stack, i);
        peek(stack);
    }

    free(stack);
    return 0;
}
