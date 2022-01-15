#include <iostream>

using namespace std;

// Version 1, return reference to const string
const string &shorterString(const string &s1, const string &s2) {
    cout << "version 1" << endl;
    return (s1.size() <= s2.size()) ? s1 : s2;
}

// Version 2, return plain reference of string instead of const string
// string &shorterString(string &s1, string &s2) {
//     cout << "version 2" << endl;
//     return (s1.size() <= s2.size()) ? s1 : s2;
// }

// Version 2 but using const_cast
string &shorterString(string &s1, string &s2) {
    cout << "version 2 const_cast" << endl;
    const string &result = shorterString(const_cast<const string&>(s1), const_cast<const string&>(s2));
    return const_cast<string&>(result);
}


int main(int argc, char **argv) {
    cout << "Overloaded function and const_cast example: " << endl;

    // Using version 1
    const string s1 = "1234";
    const string s2 = "456";
    const string &result1 = shorterString(s1, s2);
    for (auto element : result1)
        cout << element;
    cout << endl;
    //result1 = "789"; // can not change value of nonconst reference
    

    // Using version 2
    string s3 = "1234";
    string s4 = "456";
    string &result2 = shorterString(s3, s4);
    for (auto element : result2)
        cout << element;
    cout << endl;

    result2 = "789"; // can change value of nonconst reference
    for (auto element : result2)
        cout << element;
    cout << endl;

    return 0;
}