#include <iostream>

using std::begin;
using std::end;

int main() {
    constexpr size_t row = 3, col = 4;
    int ia[row][col];

    // for (size_t i = 0; i != row; ++i) {
    //     for (size_t j = 0; j != col; ++j) {
    //         ia[i][j] = i*col + j;
    //     }
    // }

    // Another version using for range
    int cnt = 0;
    for (auto &row : ia)
        for (auto &col : row) {
            col = cnt;
            ++cnt;
        }

    // for (auto &row : ia)
    //     for (auto &col : row)
    //         std::cout << col << " ";
    // std::cout << std::endl;

    // Another way to print using pointer
    // for (auto p = ia; p != ia + row; ++p) {
    //     for (auto q = *p; q != *p + col; ++q)
    //        std::cout << *q << " "; 
    //     std::cout << std::endl;
    // }

    // Another way to print using begin & end
    for (auto p = begin(ia); p != end(ia); ++p) {
        for (auto q = begin(*p); q != end(*p); ++q)
           std::cout << *q << " "; 
        std::cout << std::endl;
    }

    return 0;
}