#include <iostream>

using namespace std;

string::size_type lengthCompare(const string &s1, const string &s2) {
    cout << "lengthCompare" << endl;
    return (s1.size() > s2.size()) ? s1.size() : s2.size();
}

string::size_type lengthSum(const string &s1, const string &s2) {
    cout << "lengthSum" << endl;
    return s1.size() + s2.size();
}

// Type alias
// typedef decltype(lengthCompare) callbackFunc;
using callbackFunc = decltype(lengthCompare); // same as above

// void testFunc(const string &s1, const string &s2, string::size_type pf(const string &, const string &)) { 
// void testFunc(const string &s1, const string &s2, string::size_type (*pf)(const string &, const string &)) { // same as above
void testFunc(const string &s1, const string &s2, callbackFunc *pf) { // same as above but clear to see
    cout << "testFunc" << endl;
    string::size_type result1 = pf(s1, s2); // call lengthCompare/lengthSum
    cout << result1 << endl;
}

int main(int argc, char **argv) {
    cout << "Pointer to function as params example" << endl;

    // testFunc call back to lengthCompare
    // testFunc("ARG1_", "ARG2", lengthCompare);
    testFunc("ARG1_", "ARG2", &lengthCompare); // same as above

    // Same testFunc but call back to lengthSum
    // testFunc("ARG1_", "ARG2", lengthSum);
    testFunc("ARG1_", "ARG2", &lengthSum); // same as above

    return 0;
}