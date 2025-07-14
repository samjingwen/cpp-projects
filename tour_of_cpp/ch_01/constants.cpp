#include <iostream>

const int x = 10;

std::vector<int> vec{1, 2, 3, 4, 5};

constexpr double square(double x) { return x * x; }

constexpr double x1 = 1.4 * square(x);

int main() {
  std::cout << "x: " << x << std::endl;
  std::cout << "x1: " << x1 << std::endl;
  return 0;
}
