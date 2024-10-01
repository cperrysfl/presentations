#include <iostream>
#include <vector>
#include <span>

void print(std::span<int> s)
{
    for (const auto& i : s)
        std::cout << i << ", ";
    std::cout << std::endl;
}
