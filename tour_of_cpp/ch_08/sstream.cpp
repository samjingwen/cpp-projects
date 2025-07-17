#include <sstream>
#include <stdexcept>
#include <string>
using namespace std;

template <typename Target = string, typename Source = string>
Target to(Source arg) {
  stringstream interpreter;
  Target result;

  if (!(interpreter << arg) || !(interpreter >> result) ||
      !(interpreter >> std::ws).eof())
    throw runtime_error{"to<>() failed"};

  return result;
}

int main() {
  // very explicit (and verbose)
  auto x1 = to<string, double>(1.2);

  // Source is deduced to double
  auto x2 = to<string>(1.2);

  // Target is defaulted to string; Source is deduced to double
  auto x3 = to<>(1.2);

  // the <> is redundant;
  // Target is defaulted to string; Source is deduced to double
  auto x4 = to(1.2);
}