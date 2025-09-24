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

bool isEmpty(struct Stack* s) { return s -> top == -1; }
bool isFull (struct Stack* s) { return s -> top == MAXSIZE - 1; }

void push(struct Stack* Stack, int data){
    if (isFull (Stack)) {printf("Full stack\n"); return;}
    //Note: can't do Stack -> top = Stack -> top++;
    Stack -> top++;
    Stack -> items[Stack -> top] = data;
}

/*
I realize that you can pop by removal, but there is no need to;
You can overwrite them automatically each time you push anyways.
*/

void pop(struct Stack* Stack){
    if (isEmpty (Stack)) {printf("Empty stack\n"); return;}
    // Stack -> items[Stack -> top] = NULL;
    int value = Stack -> items[Stack -> top];
    printf("Popped: %d\n", value);
    Stack -> top--;
}

void peek(struct Stack* Stack){
    if      (isEmpty(Stack)) {printf("Empty stack\n"); return;}
    printf("The top data is : %d\n", Stack -> items[Stack -> top]);
}

int main (void){
    // struct Stack* stack;
    // initStack(&stack);

    struct Stack* stack = createStack();

    // testing empty
    pop(stack);

    for (int i = 0; i < 5; i++){
        push(stack, i);
        peek(stack);
    }

    // testing overflow
    push(stack, 1);

    // testing remove ; note: pop is not done by removal but index
    pop(stack);
    peek(stack);

    free(stack);
    return 0;
}
