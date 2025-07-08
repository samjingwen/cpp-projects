#include <iostream>

class Shape
{
public:
    void move(double x, double y)
    {
        std::cout << "Moving shape to (" << x << ", " << y << ")" << std::endl;
    }

    virtual void draw() const
    {
        std::cout << "Drawing generic shape" << std::endl;
    }
};

class Circle : public Shape
{
public:
    void draw() const override
    {
        std::cout << "Drawing circle" << std::endl;
    }
};

class Smiley : public Circle
{
public:
    void draw() const override
    {
        Circle::draw();
        std::cout << "Drawing smiley face features" << std::endl;
    }
};


int main()
{
    Smiley s;
    s.move(5, 10); // Reuses Shape's move (no need to reimplement)
    s.draw();      // Reuses Circle's draw, then adds its own

    // Output:
    // Moving shape to (5, 10)
    // Drawing circle
    // Drawing smiley face features
}
