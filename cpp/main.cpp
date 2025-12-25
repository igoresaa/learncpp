#include <iostream>

using num = int;
using frac = double;
using line = std::string;

#define print std::cout
#define n '\n'
#define $ ;

int main() {
    num number{50}$
    frac fractionalNumber{2.5}$
    line hello{"привет"}$
    print << hello << n $
    print << number << ' ' << fractionalNumber << n $
    return number $
}