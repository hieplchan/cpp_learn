#include <vector>

#include "Shape.h"

void rotate_all(std::vector<Shape*>& v, int angle) {
    for (auto p : v) {
        p->rotate(angle);
    }
}