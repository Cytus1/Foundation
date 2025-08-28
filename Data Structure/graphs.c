#include <stdio.h>


// new idea: pointer to a pointer


struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;
};


int main(void){



    return 0;
}
