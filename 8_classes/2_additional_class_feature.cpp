#include <iostream>
#include "Screen.h"

using std::cout;
using std::cin;
using std::endl;

int main() {
    cout << "Class additional features example" << endl;

    Screen my_screen(5, 5, 'x');
    char a = my_screen.get();
    char b = my_screen.get(4, 4);
    cout << a << " " << b << endl;

    // Test mutable variable
    const Screen my_screen_2(5, 5, 'x');
    cout << my_screen_2.access_ctr_count() << " ";
    my_screen_2.some_member();
    cout << my_screen_2.access_ctr_count() << endl;

    return 0;
}