#include <iostream>

struct Vector {
    int sz;
    double* elem;
};

void vector_init(Vector& v, int s) {
    v.elem = new double[s]{1,2,3,4,5};
    v.sz = s;
}

void vector_print(Vector& v, int s) {
    for (auto x = v.elem; x < v.elem + s; ++x) {
        std::cout << *x << std::endl;
    }
}

int main() {
    Vector v;
    vector_init(v, 5);
    vector_print(v, 5);    
}
