#include <vector>
#include <span>

void print(std::span<int> s);

int main()
{
  std::vector<int> v{1, -3, 27, 42, 4, -8, 22, 42, 37, 4, 18, 9};
  print( v );
  const auto pos = std::max_element(begin(v), end(v));
  v.erase(std::remove(begin(v), end(v), *pos), end(v));
  print( v );
}
