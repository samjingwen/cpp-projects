#include <iostream>
#include <list>
#include <numeric>
#include <print>
#include <vector>

template <typename Container>
using ElementType = typename Container::value_type;

template <typename Container> ElementType<Container> sum(const Container& c) {
  // The third argument is the initial value for the sum (e.g., 0 for int, 0.0
  // for double)
  return std::accumulate(c.begin(), c.end(), ElementType<Container>{});
}

int main() {
  std::vector<int> v1{1, 2, 3, 4};
  std::list<double> v2{1.5, 2.5, 3.5};

  // std::cout << "Sum of vector: " << sum(v1) << std::endl;
  // std::cout << "Sum of list: " << sum(v2) << std::endl;

  std::println("Sum of vector: {}", sum(v1));
  std::println("Sum of list: {}", sum(v2));
}