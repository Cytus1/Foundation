#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue{
    struct Node* front;
    struct Node* rear;
};

struct Node* createNode(int data){
    struct Node* node = (struct Node*) malloc (sizeof(struct Node));
    node -> data  = data;
    node -> next = NULL;
    return node;
}

/*
note: front and rear should be null instead of -1,
because no size of array for index is given in definition of
construct.
*/
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*) malloc (sizeof(struct Queue));
    q -> front = NULL;
    q -> rear = NULL;
    return q;
}


void enqueue(struct Queue* q, int data){
    struct Node* node = createNode(data);
    if (q -> rear == NULL) {
        q -> rear  = node;
        q -> front = node;
        return;
    }
    else {
        q -> rear -> next = node;
        q -> rear = node;
        return;
    }
}

void dequeue (struct Queue* q){
    if (q -> front == NULL) {printf("queue is empty"); return;}

    struct Node* clearThis = q -> front;
    q -> front = q -> front -> next;
    free (clearThis);

    if (q -> front == NULL) {q -> rear = NULL;}
}

void peek(struct Queue*q){
    if (q -> front == NULL) {printf("queue is empty"); return;}
    printf("peek result: ", q -> front);
}


/*
Note: I realize that you don't need construct new node for seeing queue;
Declare it will make a copy address, which is fine to access and read.

and const is to avoid value change for good practice. Logic is bout as
doing this.next repeatedly like java.
*/
void printQueue(struct Queue* q){
    if (q -> front == NULL) {printf("queue is empty"); return;}
    
    const struct Node* seeTheQueue = q -> front;
    while (seeTheQueue != NULL) {
        printf("%d ", seeTheQueue -> data);
        seeTheQueue = seeTheQueue -> next;
    }
    printf("\n");
}


int main (void){
    struct Queue* q = createQueue();
    for (int i = 0; i < 5; i++){
        enqueue(q, i + 1);
    }

    printQueue(q);
    dequeue(q);
    printQueue(q);
    dequeue(q); dequeue(q); dequeue(q); dequeue(q);
    printQueue(q);

    return 0;
}
