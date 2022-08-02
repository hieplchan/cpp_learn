#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL, *rear = NULL;
    
bool IsEmpty() {
    return (rear == NULL && front == NULL);
}

void Enqueue(int x) {
    struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));
    new_node->data = x;
    new_node->next = NULL;

    if (IsEmpty()) {
        rear = front = new_node;
    } else {
        rear->next = new_node;
        rear = new_node;
    }
}

void Dequeue() {
    if (IsEmpty()) {
        printf("Empty queue, can not Dequeue\n");
    } else if (front == rear) {
        free(front);
        front = rear = NULL;
    } else {
        struct Node *temp = front->next;
        free(front);
        front = temp;
    }
}

int Front() {
    if (IsEmpty()) {
        printf("Empty queue, can not Front\n");
        return -1;
    } else {
        return front->data;
    }
}

void PrintLinkedList() {
    struct Node *temp = front;
    printf("Linked List: ");
    while (temp != NULL) {
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    printf("---------------------- 0\n");
    Dequeue(); // Should show empty
    printf("---------------------- 0\n");

    Enqueue(1);
    Enqueue(2);
    Enqueue(3);
    Enqueue(4);
    PrintLinkedList();

    printf("---------------------- 0\n");
    printf("Front: %d\n", Front());
    Dequeue();
    printf("Front: %d\n", Front());
    Dequeue();
    PrintLinkedList();
    printf("---------------------- 0\n");

    Dequeue();
    Dequeue();
    PrintLinkedList();

    printf("---------------------- 1\n");
    Dequeue(); // Should show empty
    printf("---------------------- 1\n");

    return 0;
}