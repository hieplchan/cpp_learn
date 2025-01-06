#include <vector>

#include "Shape.h"
#include "Smiley.h"
#include "Circle.h"

void rotate_all(std::vector<Shape*>& v, int angle) {
    for (auto p : v) {
        p->rotate(angle);
    }
}

void test_hierarchy_navigation(Shape* s) {
    if (Smiley* p = dynamic_cast<Smiley*>(s)) { // does it point to Smiley?, else return nullptr
        p->wink(1); // wink only exist on Smiley class, not Shape
    } else {
        // not Smiley shape, do something else
    }
}

void test_leak() {
    // prevent using "naked pointer", use smart pointer instead
    // Circle* p = new Circle(Point(), 1);
    std::unique_ptr<Circle> p = std::unique_ptr<Circle>{ new Circle(Point(), 1)};
}