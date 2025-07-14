#include <cctype>
#include <format>
#include <iostream>
#include <ranges>
#include <string>
#include <string_view>

int main() {
  // 1. Prefix and Suffix Checks (C++20+)
  std::string greeting = "hello world";
  std::cout << std::boolalpha;
  std::cout << "Starts with 'hello': " << greeting.starts_with("hello")
            << std::endl;
  std::cout << "Ends with 'world': " << greeting.ends_with("world")
            << std::endl;

  // 2. String Views and Ranges (C++23)
  std::string alphanum = "abc123";
  std::cout << "Digits in string: ";
  for (char c :
       alphanum | std::views::filter([](char c) { return std::isdigit(c); }))
    std::cout << c << ' ';
  std::cout << std::endl;

  // 3. String Concatenation and Formatting (C++20)
  std::string name = "Sam";
  int age = 32;
  std::string msg = std::format("Name: {}, Age: {}", name, age);
  std::cout << msg << std::endl;

  // 4. Substring Check using .contains() (C++23)
  std::string occupation = "quantitative trader";
  if (occupation.contains("quant"))
    std::cout << "It's quant!" << std::endl;

  // 5. String Splitting with Ranges (C++23)
  std::string_view input = "buy,sell,hold";
  std::cout << "Split parts:" << std::endl;
  for (auto part : std::views::split(input, ',')) {
    std::cout << std::string_view(part.begin(), part.end()) << std::endl;
  }

  return 0;
}
