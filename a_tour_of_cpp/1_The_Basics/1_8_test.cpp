#include <vector>

void do_something(const std::vector<int>& v) {
    if (auto n = v.size()){
        // go there if n != 0
        // n is in if statement scope
    }
}