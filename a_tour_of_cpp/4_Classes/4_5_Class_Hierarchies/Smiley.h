#include <vector>
#include <memory>

#include "Circle.h"

class Smiley : public Circle {
public:
    Smiley(Point p, int rad) 
        : Circle{p, rad}, mouth{nullptr} {}
    
    // ~Smiley();

    void move(Point p) override;
    void draw() const override;
    void rotate(int angle) override;    

    void add_eye(std::unique_ptr<Shape> s) {
        eyes.push_back(s);
    }

    // still do not fully understand unique and move
    void set_mouth(std::unique_ptr<Shape> s) {
        mouth = std::move(s);
    }

    virtual void wink(int i);

private:
    std::vector<std::unique_ptr<Shape>> eyes;
    std::unique_ptr<Shape> mouth;
};