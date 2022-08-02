#include <iostream>
using namespace std;

size_t count_calls() {
    static size_t cnt = 0;
    return ++cnt;
}

int main() {
    cout << "Local static variables are destroy when program terminate" << endl;

    for (size_t i = 0; i < 10; ++i)
        cout << count_calls() << endl;

    return 0;
}