#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

void print_vector(std::vector<int>& vec) {
  std::string delim;
  for (int num : vec) {
    std::cout << delim << num;
    delim = " ";
  }
  std::cout << '\n';
}

int main() {
  std::vector<int> data = {3, 1, 2, 2, 3, 4, 4, 5};
  std::sort(data.begin(), data.end());

  print_vector(data);

  std::vector<int> result;
  std::unique_copy(data.begin(), data.end(), std::back_inserter(result));

  print_vector(result);

  return 0;
}
