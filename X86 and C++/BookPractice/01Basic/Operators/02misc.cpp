#include <iostream>
#include <iomanip>
#include "02header.h"

void DisplayResults(
    unsigned int a,
    unsigned int b,
    unsigned int r1,
    unsigned int r2
)
{
    constexpr int  w =  8;
    constexpr char nl = '\n';

    std::cout << "Result: \n";
    std::cout << std::setfill('0');
    std::cout << "a  = 0x" << std::hex << std::setw(w) << a << nl;
    std::cout << "b  = 0x" << std::hex << std::setw(w) << b  << nl;
    std::cout << "r1 = 0x" << std::hex << std::setw(w) << r1 << nl;
    std::cout << "r2 = 0x" << std::hex << std::setw(w) << r2 << nl;

    if (r1 != r2) std ::cout << "Compare Check Failed" << nl;
    if (r1 == r2) std ::cout << "Compare Check Passed" << nl;
}
