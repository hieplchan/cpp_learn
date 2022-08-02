#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *link;
};
struct Node *top = NULL;

void Push(int x) {
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

int Top() {
    return top->data;
}

void Print() {
    struct Node* temp = top;
    printf("Stack ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int main() {

    Push(2);
    Print();
    Push(10);
    Print();
    Push(7);
    Print();

    Pop();
    Print();
    Push(12);
    Print();

    return 0;

    return 0;
}