#include <iostream>
#include "IProd.h"
#include <vector>

int main()
{
    int x, y;
    std::cout << "Enter x : ";
    std::cin >> x;
    std::cout << "Enter y : ";
    std::cin >> y;
    std::cout << "Answer : " << prod(x, y) << std::endl;
    return 0;
}
