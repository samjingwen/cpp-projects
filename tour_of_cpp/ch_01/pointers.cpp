#include <iostream>

void increment(int v[], size_t size) {
  for (size_t i = 0; i < size; ++i) {
    ++v[i];
  }
}

int main() {
  int n{6};
  int v[]{0, 1, 2, 3, 4, 5};
  increment(v, 6);

  for (int* x = v; x < v + n; ++x) {
    std::cout << *x << std::endl;
  }
}