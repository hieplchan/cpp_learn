#include <iostream>

using namespace std;

bool lengthCompare(const string &s1, const string &s2) {
    cout << "lengthCompare" << endl;
    return (s1.size() > s2.size()) ? true : false;
}
bool (*pf)(const string &, const string &);

int main(int argc, char **argv) {
    cout << "Pointer to function simple example" << endl;
    
    // pf = &lengthCompare;
    pf = lengthCompare; // the same as above

    bool result1 = pf("ARG1_", "ARG2"); // call lengthCompare
    cout << result1 << endl;
    
    bool result2 = (*pf)("ARG1_", "ARG2"); // save as above
    cout << result2 << endl;

    bool result3 = lengthCompare("ARG1_", "ARG2"); // normal call
    cout << result3 << endl;

    return 0;
}