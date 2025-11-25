#include "02header.h"


unsigned int LogicGateU32_cpp(
    unsigned int a,
    unsigned int b
)
{
    unsigned int AND_ab  = a & b;
    unsigned int OR_ab   = a | b;
    unsigned int XOR_ab  = a ^ b;
    unsigned int NOT_a   = ~a;
    unsigned int NOT_b   = ~b;
    unsigned int NAND_ab = ~(a & b);
    unsigned int NOR_ab  = ~(a | b);
    unsigned int XNOR_ab = ~(a ^ b);

    unsigned int result =
        AND_ab  |
        OR_ab   |
        XOR_ab  |
        NOT_a   |
        NOT_b   |
        NAND_ab |
        NOR_ab  |
        XNOR_ab;

    return result;
}
