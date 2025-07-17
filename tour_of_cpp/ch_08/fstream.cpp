#include <fstream>
#include <vector>
#include <iostream>

int main() {
    std::ifstream in{"numbers.txt"};
    std::vector<int> nums;

    for (int i; in >> i;) {
        nums.push_back(i);
    }

    for (int n : nums) {
        std::cout << n << ' ';
    }
    std::cout << '\n';

    return 0;
}
