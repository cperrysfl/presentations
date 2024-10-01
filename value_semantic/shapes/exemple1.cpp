#include <vector>
#include <span>

void print(const std::vector<int>& vec);

int main()
{
  std::vector<int> v{1,2,3,4};

  const std::vector<int> w{ v };
  const std::span<int> s{ v };

  w[2] = 99; // Compilation error!
  s[2] = 99; // Compilation error!

  print( v );
}
