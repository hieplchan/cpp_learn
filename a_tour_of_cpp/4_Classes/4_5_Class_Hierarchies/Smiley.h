#include <vector>
#include "Circle.h"

class Smiley : public Circle {
public:
    Smiley(Point p, int rad) 
        : Circle{p, rad}, mouth{nullptr} {}
    
    ~Smiley();

    void move(Point p) override;
    void draw() const override;
    void rotate(int angle) override;    

    void add_eye(Shape* s) {
        eyes.push_back(s);
    }

    void set_mouth(Shape* s) {
        mouth = s;
    }

    virtual void wink(int i);

private:
    std::vector<Shape*> eyes;
    Shape* mouth;
};