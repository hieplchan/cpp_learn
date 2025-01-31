#include <vector>
#include <memory>
#include <iostream>

#include "Shape.h"
#include "Smiley.h"
#include "Circle.h"

using std::vector, std::unique_ptr, std::cin;

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

template<typename C, typename Oper>
void for_all(C& c, Oper op)
{
    for (auto& x : c)
        op(x);
}

void testLamdaExpression()
{
    vector<unique_ptr<Shape>> v;
    // while (cin)
        // v.push_back(readShape(cin));

    // dont need to write 2 seperate draw_all, rotate_all and so on
    for_all(v, [](unique_ptr<Shape>& ps){ ps->draw(); });
    for_all(v, [](unique_ptr<Shape>& ps){ ps->rotate(45); });
}

// lamda can be generic
// lamda with auto params -> generic lamda
template<typename S>
void rotate_and_draw(vector<S>& v, int r)
{
    for_all(v, [](auto& s){ s->rotate(r); s->draw(); });
}

void testRotateAndDraw()
{
    vector<unique_ptr<Shape>> v1;
    vector<Shape*> v2;

    // generic so can be use with both pointer type
    rotate_and_draw(v1, 10);
    rotate_and_draw(v2, 15);
}

void test_leak() {
    // prevent using "naked pointer", use smart pointer instead
    // Circle* p = new Circle(Point(), 1);
    std::unique_ptr<Circle> p = std::unique_ptr<Circle>{ new Circle(Point(), 1)};
}