#include <stdio.h>


struct Node {
    int number;
    struct Node* next;
};


int main(void) {
    struct Node node1;
    struct Node node2;
    struct Node node3;

    node1.number = 1;
    node2.number = 2;
    node3.number = 3;

    node1.next = &node2;
    node2.next = &node3;
    node3.next = NULL;

    struct Node* current = &node1;
    while (current != NULL) {
        printf("%d\n", current -> number);
        current = current -> next;
    }

    return 0;
}

// note: i made this linked list where the node was access through memory, not object, to show -> is useful in this case.
