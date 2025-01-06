#include "Shape.h"

class Circle : public Shape {
public:
    Circle(Point p, int rad) : x{p}, r{rad} {};

    Point center() const override {
        return x;
    }

    void move(Point p) override {
        x = p;
    }

    void draw() const override;
    void rotate(int angle) override;

private:
    Point x; // center
    int r;  // radius
};