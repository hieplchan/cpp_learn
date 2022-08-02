#include <stdio.h>
#include <stdbool.h>

#define STACK_MAX_SIZE 101

int A[STACK_MAX_SIZE];
int top = -1;

void Push(int x) {
    if (top == STACK_MAX_SIZE - 1) {
        printf("Error: Stack Overflow\n");
        return;
    }
    A[++top] = x;
}

void Pop() {
    if (top == -1) {
        printf("Error: Stack have no element to pop\n");
        return;
    }
    top--;
}

int Top() {
    return A[top];
}

bool IsEmpty() {
    if (top == -1) {
        return true;
    } else {
        return false;
    }
}

void Print() {
    int i;
    printf("Stack ");
    for (i = 0; i <= top; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main() 
{
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
}