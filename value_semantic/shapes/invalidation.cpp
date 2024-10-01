#include <vector>
#include <span>

void print(std::span<int> s);

int main()
{
    std::vector<int> v{1,2,3,4};

    const std::span<int> s{v};

    v = {5,6,7,8,9};

    print(s);
}
