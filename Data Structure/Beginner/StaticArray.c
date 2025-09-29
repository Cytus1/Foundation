#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int maxsize;
    int index[];
};

struct Array* createArray(int maxsize){
    struct Array* array = (struct Array*)malloc(sizeof(struct Array) + sizeof(int) * maxsize);
    array -> maxsize = maxsize;
    return array;
}



int main (void){
    struct Array* myArray = createArray(5);

    for (int i = 0; i < 5; i++){
        myArray -> index[i] = i * 10;
    }

    for (int i = 0; i < myArray -> maxsize ; i++){
        printf("Index[%d]: %d\n",i , myArray -> index[i]);
    }
    
    free(myArray);
}
