#include <stdio.h>

/*
ideal graph

     a
    / \
   b   c
  /
 d

Note:
some task I can do...
iterative traversals using a stack (like preorder and inorder).
get height / size / leaf count functions.
print the tree sideways.
dynamic insert with malloc (and a make_node helper).
verify outputs by collecting into an array instead of printing.
*/


struct Node{
    int value;
    struct Node* left;
    struct Node* right;
};



void preorder (struct Node* n){           // root, left, right  3 2 4 1
    if(!n) return;
    printf("%d ", n->value);
    preorder(n->left);
    preorder(n->right);
}

void inorder (struct Node* n){            // left, root, right  4 2 3 1
    if(!n) return;
    inorder(n->left);
    printf("%d ", n->value);
    inorder(n->right);
}

void postorder (struct Node* n){          // left, right, root  4 2 1 3
    if(!n) return;
    postorder(n->left);
    postorder(n->right);
    printf("%d ", n->value);
}

void levelorder (struct Node* root){      // BFS by levels      3 2 1 4
    if(!root) return;
    struct Node* q[32];                   // simple queue (enough for small trees)
    int h = 0, t = 0;
    q[t++] = root;
    while(h < t){
        struct Node* n = q[h++];
        printf("%d ", n->value);
        if(n->left)  q[t++] = n->left;
        if(n->right) q[t++] = n->right;
    }
}


int main (void){
    struct Node a;  a.value = 3;
    struct Node b;  b.value = 2;
    struct Node c;  c.value = 1;
    struct Node d;  d.value = 4;


    a.left = &b;    a.right = &c;
    b.left = &d;    b.right = NULL;
    c.left = NULL;  c.right = NULL;
    d.left = NULL;  d.right = NULL;


    printf("Preorder:    "); preorder(&a);    printf("\n"); // 3 2 4 1
    printf("Inorder:     "); inorder(&a);     printf("\n"); // 4 2 3 1
    printf("Postorder:   "); postorder(&a);   printf("\n"); // 4 2 1 3
    printf("Levelorder:  "); levelorder(&a);  printf("\n"); // 3 2 1 4


    return 0;
}
