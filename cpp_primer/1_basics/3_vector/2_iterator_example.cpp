#include <string>
#include <iostream>

int main() {

    std::cout << "Start string iterator example\n" << std::endl;

    std::string s("Some string");

    // Uppercase first element
    if (s.begin() != s.end()) {
        auto it = s.begin();
        *it = toupper(*it);
        std::cout << s << std::endl;
    } else {
        std::cout << "String s is empty" << std::endl;
    }

    // Uppercase all elements before space charactor
    for (auto it = s.begin(); (it != s.end()) && !isspace(*it); ++it) {
        *it = toupper(*it);
    }
    std::cout << s << std::endl;

    return 0;
}