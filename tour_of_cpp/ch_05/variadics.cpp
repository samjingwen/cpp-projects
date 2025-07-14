#include <iostream>

template <typename T> void print(const T& x) { std::cout << x << std::endl; }

template <typename T, typename... Args>
void print(const T& first, const Args&... args) {
  std::cout << first << " ";
  print(args...);
}

int main() {
  std::cout << "result: ";
  print(1, 2.5, "hello");
}
