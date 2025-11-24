#include "02header.h"


int main(void){
    unsigned int a  = 0xabcdefab;
    unsigned int b  = 0x12345678;

    unsigned int r1 = LogicGateU32_cpp (a, b);
    unsigned int r2 = LogicGateU32_a   (a, b);

    DisplayResults(a, b, r1, r2);
    return 0;
}
