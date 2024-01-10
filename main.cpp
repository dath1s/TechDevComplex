#include <iostream>
#include "Complex.h"

int main() {
    Complex num(1, 1);
    int exp = 3;
    std::cout << num.pow(exp);
    return 0;
}
