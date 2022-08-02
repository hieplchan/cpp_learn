#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Node {
    char data;
    struct Node *link;
};
struct Node *top = NULL;

void Push(char x) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->link = top;
    top = temp;
}

void Pop() {
    if (top == NULL) {
        printf("Error: Stack have no element to pop\n");
        return;
    }

    struct Node *temp = top;
    top = top->link;

    free(temp);
}

char Top() {
    return top->data;
}

void Print() {
    struct Node* temp = top;
    printf("Stack ");
    while (temp != NULL) {
        printf("%c ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

bool is_balance_parentheses(char *C, size_t len) {
    int i;
    for (i = 0; i < len; i++) {
        if (C[i] == '(' || C[i] == '[' || C[i] == '{') {
            // Open parentheses
            Push(C[i]);
        } else if (C[i] == ')' || C[i] == ']' || C[i] == '}') {
            // Close parentheses
            if (top == NULL) {
                return false; // close without open parentheses
            } 
            
            if (Top() == '(' && C[i] != ')') {
                return false;
            } 
            if (Top() == '[' && C[i] != ']') {
                return false;
            }
            if (Top() == '{' && C[i] != '}') {
                return false;
            }

            Pop();
        }
    }
    
    return (top == NULL);
}

int main() {

    char C[50];
    gets(C);

    if (is_balance_parentheses(C, strlen(C))) {
        printf("Balance\n");
    } else {
        printf("Not balance\n");
    }
}