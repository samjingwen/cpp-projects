#include <initializer_list>

class Vector
{
public:
    Vector(int s);
    Vector(std::initializer_list<double> lst);
    ~Vector();

    double &operator[](int i);
    int size() const;

private:
    double *elem;
    int sz;
};
