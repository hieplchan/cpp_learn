#include <iostream>
#include "Screen.h"
#include "Window_mgr.h"

using std::cout;
using std::cin;
using std::endl;

int main() {
    cout << "Class additional features example" << endl;

    Screen my_screen(5, 5, '1');
    char a = my_screen.get();
    char b = my_screen.get(4, 4);
    cout << a << " " << b << endl;

    // Test mutable variable
    const Screen my_screen_2(5, 5, '2');
    cout << my_screen_2.access_ctr_count() << " ";
    my_screen_2.some_member();
    cout << my_screen_2.access_ctr_count() << endl;

    // Move cursor and set value of that cursor
    cout << my_screen.get(4, 0) << " ";
    my_screen.move(4,0).set('a'); // these operator execure on same object because we return *this object
    cout << my_screen.get(4, 0) << endl;

    // Display test
    my_screen.display(cout);
    cout << endl;
    my_screen_2.display(cout);
    cout << endl;
    my_screen.set(2, 3, 'k').display(cout);
    cout << endl;

    return 0;
}