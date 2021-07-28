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

// using callbackFuncType = decltype(lengthCompare) (*); 
typedef decltype(lengthCompare)* callbackFuncType; // same as above

void testFunc(const string &s1, const string &s2, callbackFuncType pf) {
    cout << "testFunc" << endl;
    string::size_type result1 = pf(s1, s2);
    cout << result1 << endl;
}

// callbackFuncType *chooseCallBackFunc(const string &option) {
auto chooseCallBackFunc(const string &option) -> callbackFuncType { // same as above
    if (option == "lengthCompare") {
        return &lengthCompare;
    } else {
        return &lengthSum;
    }
}

int main(int argc, char **argv) {
    cout << "Pointer to function as params example" << endl;

    callbackFuncType callbackFunc1 = chooseCallBackFunc("lengthCompare");
    testFunc("ARG1_", "ARG2", callbackFunc1);

    callbackFuncType callbackFunc2 = chooseCallBackFunc("lengthSum");
    testFunc("ARG1_", "ARG2", callbackFunc2);

    return 0;
}