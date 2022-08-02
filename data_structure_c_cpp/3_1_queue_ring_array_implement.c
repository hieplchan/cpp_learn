#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define QUEUE_SIZE 4

int8_t A[QUEUE_SIZE] = {-99};
uint32_t front = -1, rear = -1;

bool IsEmpty() {
    return (front == -1 && rear == -1);
}

bool IsFull() {
    return (((rear + 1) % QUEUE_SIZE) == front);
}

void Enqueue(int8_t x) {
    printf("Enqueue, front: %d, rear: %d\n", front, rear);
    if (IsFull()) {
        printf("Queue is full, can not Enqueue \n");
        return;
    } else if (IsEmpty()) {
        rear = front = 0;
    } else {
        rear = (rear + 1) % QUEUE_SIZE;
    }
    A[rear] = x;
}

void Dequeue() {
    printf("Dequeue, front: %d, rear: %d\n", front, rear);
    if (IsEmpty()) {
        printf("Queue is empty, can not Dequeue \n");
        return;
    } else if (rear == front) {
        A[front] = -99; // Debug
        rear = front = -1;
    } else {
        A[front] = -99; // Debug
        front = (front + 1) % QUEUE_SIZE;
    }
}

int8_t Front() {
    if (!IsEmpty()) {
        return A[front];
    } else {
        printf("Queue is empty, can not Front \n");
        return -1;
    }
}

void PrintArray() {
    printf("Queue array: ");
    for (size_t i = 0; i < QUEUE_SIZE; i++) {
        printf("%d ", A[i]);
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
    PrintArray();

    printf("---------------------- 1\n");
    Enqueue(5); // Should show full
    PrintArray();
    printf("---------------------- 1\n");

    Dequeue();
    Dequeue();
    Dequeue();
    Dequeue();
    PrintArray();

    printf("---------------------- 2\n");
    Dequeue(); // Should show empty
    PrintArray();
    printf("---------------------- 2\n");

    Enqueue(6);
    PrintArray();
    Dequeue();
    PrintArray();

    printf("---------------------- 3\n");
    Enqueue(7);
    Enqueue(8);
    Enqueue(9);
    Enqueue(10);
    Enqueue(11); // Should show full
    PrintArray();
    printf("---------------------- 3\n");

    return 0;
}