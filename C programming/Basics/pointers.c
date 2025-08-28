#include <stdio.h>


struct twoNum {
    int x;
    int y;
};


int main(void){
    struct twoNum myTwoNum = {0, 1};
    printf("%d\n", myTwoNum.x);
    printf("%d\n", myTwoNum.y);

    struct twoNum *ptr = &myTwoNum;
    printf("%d\n", ptr->x);
    printf("%d\n", ptr->y);
    return 0;
}
