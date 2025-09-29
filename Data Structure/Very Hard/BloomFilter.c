#include <stdio.h>
#include <stdlib.h> 

/*
idea:
run hash function 3 times for 3 diff number
use those 3 number for matching in bit set
array base where this array's definition can be refined dynamically
*/

struct Array{
    int max;
    int index[];
};

struct Array* createArray(int max){
    struct Array* array = (struct Array*)malloc(sizeof(array) + sizeof(int) * max);
    array -> max = max;
    return array;
}

/*
Spamming XOR and shift bits, then times large constant for random num
and put in random scope of table using %
Since it follows the same set of logic, it is deterministic
*/
unsigned int hashint(unsigned int x, unsigned int table_size) {
    x ^= x >> 16;
    x *= 0x7feb352d;
    x ^= x >> 15;
    x *= 0x846ca68b;
    x ^= x >> 16;
    return x % table_size;
}

/*
Get all letter's ascii and sum them, then load into
the hash int function as return

Note: unsign char was used for extended ASCII ( sometimes
signed char system get negative value for them)
*/
unsigned int hashstr(const char *s, unsigned int table_size){
    unsigned int sum = 0;
    unsigned int i = 0;
    while (s[i] != '\0'){
        sum += (unsigned char)s[i]; i++;
    }
    return hashint(sum, table_size);
}


int main(void){

    int TableSize = 100;
    char wordOne[10] = "letter";
    int tripleHash[2]; 
    
    int wordint = hashstr(wordOne, TableSize);
    tripleHash[0] = wordint;
    wordint = hashint(wordint, TableSize);
    tripleHash[1] = wordint;
    wordint = hashint(wordint, TableSize);
    tripleHash[2] = hashint(wordint, TableSize);

    for (int i = 0; i < 3; i++){
        printf("[Table = %d][Element = %d] int: %d\n", TableSize, i, tripleHash[i]);
    }

    return 0;
}