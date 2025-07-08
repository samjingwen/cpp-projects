#include <iostream>
#include <vector>

template <typename T>
class LessThan
{
    const T val;

public:
    LessThan(const T &v) : val(v) {}

    bool operator()(const T &x) const
    {
        return x < val;
    }
};

template<typename C, typename P>
int count(const C& c, P pred) {
    int cnt = 0;
    for (const auto& x : c) {
        if (pred(x)) {
            ++cnt;
        }
    }
    return cnt;
}

int main()
{
    int x = 5;
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8};

    std::cout << "number of values less than " << x << ": " << count(vec, LessThan<int>{x}) << std::endl;

    return 0;
}