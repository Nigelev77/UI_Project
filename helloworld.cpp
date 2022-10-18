#include <iostream>

struct AStruct {
  int x, y, z;

  int showResult() { return x + y + z; }

  AStruct(int a, int b, int c) : x{a}, y{b}, z{c} {}
  AStruct() : x{}, y{}, z{} {}
};

int main() {
  std::cout << "Hello World\n";

  AStruct a{};
  AStruct b{5, 3, 4};
  std::cout << a.showResult() << '\n';
  std::cout << b.showResult();

  return 0;
}
