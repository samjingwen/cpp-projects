#include "my_vec.h"
#include <iostream>
#include <numeric>

int main() {
  Vector v(5);
  std::iota(&v[0], &v[0] + v.size(), 1);

  for (int i = 0; i < v.size(); ++i) {
    std::cout << v[i] << " ";
  }
  std::cout << std::endl;

  for (int i = 0; i < v.size(); ++i) {
    std::cout << v[i] * 2 << " ";
  }
  std::cout << std::endl;
}
