#include <memory>
#include "Smiley.h"

// After using smart pointer, compiler auto gen destructor code for "delete"
// Smiley::~Smiley() {
//     // First delete though pointer or ref
//     delete mouth;
//     for (auto p : eyes)
//         delete p;
//     // Then virtual function mechanism call proper destructor
//     // to implicit involkes destoructor of its base and members
// }

void Smiley::draw() const {
    Circle::draw();
    // use ref to prevent "copy" of unique pointer
    for (auto& p : eyes) 
        p->draw();
    mouth->draw();
}