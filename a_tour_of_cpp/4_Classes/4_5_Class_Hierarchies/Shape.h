#ifndef SHAPE_H_
#define SHAPE_H_

#include "Point.h"

class Shape { // abstract class
public:
    virtual Point center() const = 0; // pure virtual
    virtual void move(Point to) = 0;

    virtual void draw() const = 0; // draw on current Canvas
    virtual void rotate(int angle) = 0;

    ~Shape() {} // destructor
};

#endif SHAPE_H_