#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>

struct Person {
  std::string name;
  int age;
};

std::ostream& operator<<(std::ostream& os, const Person& p) {
  return os << "Name: " << p.name << ", Age: " << p.age;
}

int main() {
  int x1;
  std::cout << "Enter an integer: ";
  std::cin >> x1;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cout << "You have chosen: " << x1 << '\n';

  std::string name;
  std::cout << "Please enter your name: ";
  std::getline(std::cin, name);
  std::cout << "Hello, " << name << '\n';

  std::istringstream input{"12\n34\n56"};
  std::vector<int> res;
  for (int x2; input >> x2;) {
    res.push_back(x2);
  }
  for (int num : res) {
    std::cout << num << ' ';
  }
  std::cout << '\n';

  Person person{"John", 42};
  std::cout << person << '\n';

  return 0;
}
