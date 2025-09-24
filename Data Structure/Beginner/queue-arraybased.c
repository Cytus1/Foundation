#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
FIFO : First in first out
1, 2, 3, 4, 5
front = 1, rear = 5

operations to add for practice:
    Enqueue: adding an element on back of the queue
    Dequeue: remove first element
    Peek:    see first element, no removal
    isEmpty: check if queue empty
    isFull:  check if queue full (in case of a fixed size array implementation).
    PrintQ:  literally what it stands for
*/

// front = head, rear = tail
#define MAX 5
struct Queue {
    int nums[MAX];
    int front;
    int rear;
};

/*
Note: malloc function's prototpy is void* malloc(size_t size);
but C can run without cast, I wrote cast for good practice because of C++ is needed.

Some other note:
(struct Queue*) cast tells the compiler to treat this generic pointer as a pointer to a struct queue
sizeof(struct Queue) asks for how many bytes are needed for one struct queue
(the struct have 5 int , with front and rear being int type, that (5+2)x4 = 28 bytes, and we might have padding that goes for more)

Then its just giving some basic definition on q
*/

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q -> front = -1;
    q -> rear = -1;
    return q;
}

void peek(struct Queue*q){
    if (q -> front == -1) {printf("this queue is empty"); return;}
    printf("peek result: ", q -> front);
}

bool isFull(struct Queue* q){
    return ((q -> rear + 1) % MAX == q -> front);
}

bool isEmpty(struct Queue* q){
    return (q -> front == -1);
}

/*
note: rear = -1, so we can add 1 at beginning for 0, which fits.
and using % MAX, we can go from max to 0 as the remainder's behavior
*/
void enqueue(struct Queue* q, int value){
    if (isFull(q) == true)   {printf("q is full\n"); return;}
    if (q -> front == -1) {q -> front = 0;}
    q -> rear = (q -> rear + 1) % MAX;
    q -> nums[q -> rear] = value;
}

void dequeue(struct Queue* q){
    if(isEmpty(q)){
        printf("queue is empty\n");
        return;
    }
    
    printf("%d going to be removed\n", q -> nums[q -> front]);

    if(q -> front == q -> rear){
        q -> front = -1;
        q -> rear = -1;
        printf("queue is empty\n");
    }
    else {
        q -> front = (q->front + 1) % MAX;
    }

    printf("success\n");
}


/*
note: % MAX was reuse for circular remainder behavior, and we do rear + 1 or else it stops before 1 last element
also, I used do while instead of while, or else for example, we start at 0 and check stop at 0, the loop just stops.
If we do it first, then we are at 1, and we stop when 0 is checked.
*/
void PrintQ(struct Queue* q){
    if (q -> front == -1) {printf("queue is empty\n"); return;}
    
    printf("queue: ");

    int i = q -> front;

    do {
        printf("%d ", q -> nums[i]);
        i = (i + 1) % MAX;
    } while (i != (q -> rear + 1) % MAX);

    printf("\n");
}


int main(void){
    struct Queue* q = createQueue();

    for (int i = 0; i < 5; i++){
        enqueue(q, i + 1);
    }

    PrintQ(q);
    return 0;
}
