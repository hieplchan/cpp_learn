#include "Smiley.h"

Smiley::~Smiley() {
    // First delete though pointer or ref
    delete mouth;
    for (auto p : eyes)
        delete p;
    // Then virtual function mechanism call proper destructor
    // to implicit involkes destoructor of its base and members
}

void Smiley::draw() const {
    Circle::draw();
    for (auto p : eyes)
        p->draw();
    mouth->draw();
}