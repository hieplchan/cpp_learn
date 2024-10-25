#include <iostream>

using namespace std;

enum class Color {red, blue, green};

enum class TrafficLight {green, yellow, red};
TrafficLight& operator++(TrafficLight& t) {
    switch (t) {
        case TrafficLight::green: return t = TrafficLight::yellow;
        case TrafficLight::yellow: return t = TrafficLight::red;
        case TrafficLight::red: return t = TrafficLight::green;
    }
}

int main() {
    // red is different scope
    Color::red;
    TrafficLight::red;

    // Custom operator
    TrafficLight currentLight = TrafficLight::green;
    TrafficLight nextLight = ++currentLight; // TrafficLight::yellow

    cout << static_cast<int>(nextLight);
}