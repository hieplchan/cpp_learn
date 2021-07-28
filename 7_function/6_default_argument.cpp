#include <iostream>

using namespace std;

void printSomething(char arg1 = '1', char arg2 = '2', char arg3 = '3') {
    cout << "printSomething: " << arg1 << arg2 << arg3 << endl;
}

int main(int argc, char **argv) {
    cout << "Default arguments example: " << endl;

    printSomething();
    printSomething('4');
    printSomething('4', '5');
    printSomething('4', '5', '6');

    return 0;
}