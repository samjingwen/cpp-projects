#include <iostream>
#include <numeric>

class Container {
public:
  virtual double& operator[](int) = 0;
  virtual int size() const = 0;
  virtual ~Container() {}
};

class Vector : public Container {
public:
  Vector(int s) {
    if (s < 0) {
      throw std::length_error{"Vector size cannot be negative"};
    }
    elem = new double[s];
    sz = s;
  };

  Vector(std::initializer_list<double> lst)
      : elem{new double[lst.size()]}, sz{static_cast<int>(lst.size())} {
    std::copy(lst.begin(), lst.end(), elem);
  }

  ~Vector() { delete[] elem; }

  double& operator[](int i) {
    if (i < 0 || size() <= i)
      throw std::out_of_range{"Vector::operator[]"};
    return elem[i];
  }

  int size() const { return sz; }

private:
  double* elem;
  int sz;
};

void print(Container& c) {
  for (int i = 0; i < c.size(); ++i) {
    std::cout << "[" << c[i] << "]" << std::endl;
  }
}

int main() {
  Vector v1(5);
  std::iota(&v1[0], &v1[0] + v1.size(), 1);

  print(v1);

  Vector v2(5);
  std::iota(&v2[0], &v2[0] + v2.size(), 2);

  print(v2);
}
