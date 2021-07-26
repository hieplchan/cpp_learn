#include <iostream>

using namespace std;

void error_msg(int error_code, initializer_list<string> il) {
    cout << error_code << ": ";
    for (auto &element : il) {
        cout << element << " ";
    }
    cout << endl;
}

int main(int argc, char **argv) {
    cout << "Initializer list: " << argv[0] << endl;

    // Pass 3 value to error_msg func
    error_msg(3, {"ARG1", "ARG2", "ARG3"});

    // Pass 2 value to error_msg func
    error_msg(2, {"ARG4", "ARG5"});

    return 0;
}