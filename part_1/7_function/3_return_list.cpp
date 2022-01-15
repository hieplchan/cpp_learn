#include <iostream>
#include <vector>

using namespace std;

vector<string> process(int error_code) {
    if (error_code == 0) {
        return {};
    } else if (error_code == 1) {
        return {"ARG1", "ARG2", "ARG3"};
    } else {
        return {"ARG4", "ARG5"};
    }
}

int main(int argc, char **argv) {
    cout << "Function return list example: " << argv[0] << endl;

    vector<string> result;

    result = process(0);
    for (auto &element : result) {
        cout << element << " ";
    }
    cout << endl;

    result = process(1);
    for (auto &element : result) {
        cout << element << " ";
    }
    cout << endl;

    result = process(2);
    for (auto &element : result) {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}