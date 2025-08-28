#include <stdio.h>


struct linkedlist {
    int number;
    struct Node* next;
};



int main(void) {
    struct linkedlist node1;
    struct linkedlist node2;
    struct linkedlist node3;

    node1.number = 1;
    node2.number = 2;
    node3.number = 3;

    node1.next = &node2;
    node2.next = &node3;
    node3.next = NULL;

    struct linkedlist* current = &node1;
    while (current != NULL) {
        printf("%d\n", current -> number);
        current = current -> next;
    }

    return 0;
}

// note: i made this linked list where the node was access through memory, not object, to show -> is useful in this case.
