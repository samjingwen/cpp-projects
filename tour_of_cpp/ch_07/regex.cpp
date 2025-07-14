#include <iostream>
#include <regex>
#include <string>

int main() {
  // 1. Match a Simple Pattern
  std::string text1{"email: sam@example.com"};
  std::regex pattern1{R"(\w+@\w+\.\w+)"};
  if (std::regex_search(text1, pattern1)) {
    std::cout << "[1] Email found" << std::endl;
  }

  // 2. Extract All Matches
  std::string text2{"Sam: 1234, Jing: 5678"};
  std::regex pattern2{R"(\d{4})"};
  std::cout << "[2] Extracted matches:" << std::endl;
  for (auto it = std::sregex_iterator{text2.begin(), text2.end(), pattern2};
       it != std::sregex_iterator{}; ++it) {
    std::cout << "  Match: " << it->str() << std::endl;
  }

  // 3. Regex Replace
  std::string text3{"1st line\n2nd line\n3rd line"};
  std::regex pattern3{R"(\n)"};
  std::string replaced{std::regex_replace(text3, pattern3, "; ")};
  std::cout << "[3] Replaced text: " << replaced << std::endl;

  // 4. Full Match Check
  std::string input{"S1234567X"};
  std::regex pattern4{R"(S\d{7}[A-Z])"};
  std::cout << "[4] NRIC Check: ";
  if (std::regex_match(input, pattern4)) {
    std::cout << "Valid NRIC" << std::endl;
  } else {
    std::cout << "Invalid NRIC" << std::endl;
  }

  return 0;
}
