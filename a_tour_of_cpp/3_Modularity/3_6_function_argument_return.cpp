#include <iostream>
#include <vector>

using namespace std;

void test(
    vector<int> v,          // pass by value
    vector<int>& rv,        // pass by reference
    const vector<int>& crv, // pass by const reference, can not modify
    int defaultArg = 10)    // default value
{
    v[0] = 2;
    rv[1] = 66;
    // crv[2] = 100; // compile error
}

int& bad_return()
{
    int x = 10;
    return x; // bad: return pointer to local variable, destroyed
}

struct Entry {
    string name;
    int value;
};

// Structured binding
Entry read_entry(istream& is) {
    string s;
    int i;
    is >> s >> i;
    return {s, i};
}

// int MyMain() {
int main() {
    vector<int> v = {1, 1, 1, 4, 5};

    test(v, v, v);
    cout << v[0] << ' ' << v[1] << '\n';

    auto e = read_entry(cin);
    cout << e.name << ' ' << e.value << '\n';
    
    // auto [n, v] = read_entry(cin); // structured binding required c++17
    // cout << n << ' ' << v << '\n';

    return 0;
}
