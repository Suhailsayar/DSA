#include<stdio.h>
#define max 100

int queue[max];
int front = -1;
int rear = -1;

void enqueue(int x) {
    if ((rear + 1) % max == front) { // Check if the queue is full
        printf("Queue is full! Cannot insert more elements.\n");
        return;
    }
    if (front == -1 && rear == -1) { // Check if the queue is empty
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % max; // Increment rear circularly
    }
    queue[rear] = x; // Insert the element
    printf("Element %d enqueued into the queue.\n", x);
}

void dequeue() {
    if (front == -1 && rear == -1) { // Check if the queue is empty
        printf("Queue is empty! Cannot dequeue.\n");
        return;
    }
    printf("Element %d dequeued from the queue.\n", queue[front]);
    if (front == rear) { // If the queue becomes empty after dequeue
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % max; // Increment front circularly
    }
}

void peek() {
    if (front == -1 && rear == -1) { // Check if the queue is empty
        printf("The queue is empty. No peek element.\n");
        return;
    }
    printf("The peek element is: %d\n", queue[front]); // Display the front element
}

void display() {
    if (front == -1 && rear == -1) { // Check if the queue is empty
        printf("The queue is empty.\n");
        return;
    }
    printf("The queue elements are: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) {
            break;
        }
        i = (i + 1) % max; // Increment circularly
    }
    printf("\n");
}

int main() {
    int x;
    char choice;
    while (1) {
        printf("---Circular Queue Operations---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        switch (choice) {
            case '1':
                printf("Enter the value to insert: ");
                scanf("%d", &x);
                enqueue(x);
                break;
            case '2':
                dequeue();
                break;
            case '3':
                peek();
                break;
            case '4':
                display();
                break;
            case '5':
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Enter a valid choice!\n");
        }
    }
    return 0;
}