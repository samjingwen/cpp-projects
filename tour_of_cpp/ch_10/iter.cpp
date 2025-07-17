#include <iostream>
#include <string>
#include <vector>

void print_vector(std::vector<int>& vec) {
  std::string delim;
  for (int num : vec) {
    std::cout << delim << num;
    delim = " ";
  }
  std::cout << '\n';
}

template <typename C, typename V>
std::vector<typename C::iterator> find_all(C& c, V v) {
  std::vector<typename C::iterator> res;
  res.reserve(std::size(c));

  for (auto p = c.begin(); p != c.end(); ++p) { 
    if (*p == v) {
      res.push_back(p);
    }
  }

  return res;
}

int main() {
  std::vector<int> data{1, 2, 3, 2, 4, 2, 5};

  std::cout << "Original vector: ";
  print_vector(data);

  auto matches = find_all(data, 2);

  std::cout << "Found " << matches.size() << " matches:\n";
  for (auto it : matches) {
    std::cout << "  value: " << *it
              << ", index: " << std::distance(data.begin(), it) << '\n';
  }

  return 0;
}
