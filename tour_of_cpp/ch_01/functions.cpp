#include <iostream>

void print(int);

int main() {
  print(sizeof(int));
  return 0;
}

void print(int value) { std::cout << "Value: " << value << std::endl; }