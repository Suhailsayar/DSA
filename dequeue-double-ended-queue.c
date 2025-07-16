#include<stdio.h>
#define max 100

int deque[max];
int front = -1;
int rear = -1;

void insertFront(int x) {
    if ((front == 0 && rear == max - 1) || (front == rear + 1)) { // Check if deque is full
        printf("Deque is full! Cannot insert at the front.\n");
        return;
    }
    if (front == -1 && rear == -1) { // Check if deque is empty
        front = 0;
        rear = 0;
    } else if (front == 0) { // Wrap around to the end
        front = max - 1;
    } else {
        front--;
    }
    deque[front] = x;
    printf("Element %d inserted at the front.\n", x);
}

void insertRear(int x) {
    if ((front == 0 && rear == max - 1) || (front == rear + 1)) { // Check if deque is full
        printf("Deque is full! Cannot insert at the rear.\n");
        return;
    }
    if (front == -1 && rear == -1) { // Check if deque is empty
        front = 0;
        rear = 0;
    } else if (rear == max - 1) { // Wrap around to the front
        rear = 0;
    } else {
        rear++;
    }
    deque[rear] = x;
    printf("Element %d inserted at the rear.\n", x);
}

void deleteFront() {
    if (front == -1 && rear == -1) { // Check if deque is empty
        printf("Deque is empty! Cannot delete from the front.\n");
        return;
    }
    printf("Element %d deleted from the front.\n", deque[front]);
    if (front == rear) { // If deque becomes empty
        front = -1;
        rear = -1;
    } else if (front == max - 1) { // Wrap around to the front
        front = 0;
    } else {
        front++;
    }
}

void deleteRear() {
    if (front == -1 && rear == -1) { // Check if deque is empty
        printf("Deque is empty! Cannot delete from the rear.\n");
        return;
    }
    printf("Element %d deleted from the rear.\n", deque[rear]);
    if (front == rear) { // If deque becomes empty
        front = -1;
        rear = -1;
    } else if (rear == 0) { // Wrap around to the end
        rear = max - 1;
    } else {
        rear--;
    }
}

void display() {
    if (front == -1 && rear == -1) { // Check if deque is empty
        printf("The deque is empty.\n");
        return;
    }
    printf("The deque elements are: ");
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
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
        printf("---Double-Ended Queue Operations---\n");
        printf("1. Insert Front\n");
        printf("2. Insert Rear\n");
        printf("3. Delete Front\n");
        printf("4. Delete Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        switch (choice) {
            case '1':
                printf("Enter the value to insert at the front: ");
                scanf("%d", &x);
                insertFront(x);
                break;
            case '2':
                printf("Enter the value to insert at the rear: ");
                scanf("%d", &x);
                insertRear(x);
                break;
            case '3':
                deleteFront();
                break;
            case '4':
                deleteRear();
                break;
            case '5':
                display();
                break;
            case '6':
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Enter a valid choice!\n");
        }
    }
    return 0;
}