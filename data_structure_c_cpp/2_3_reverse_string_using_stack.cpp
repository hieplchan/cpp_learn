#include <stack>
#include <iostream>

void Reverse(char *C, int len) {
    std::stack<char> S;
    for (int i = 0; i < len; i++) {
        S.push(C[i]);
    }
    for (int i = 0; i < len; i++) {
        C[i] = S.top();
        S.pop();
    }
} 

int main() {
    char C[50];

    std::cout << "Please in put string" << std::endl;
    gets(C);

    Reverse(C, strlen(C));
    printf("Output: %s\n", C);
}