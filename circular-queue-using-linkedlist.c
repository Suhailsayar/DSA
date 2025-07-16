#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* link;
};

struct node* front = NULL;
struct node* rear = NULL;

void enqueue(int x) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->link = NULL;

    if (front == NULL && rear == NULL) { // Check if the queue is empty
        front = rear = newnode;
        rear->link = front; // Make it circular
    } else {
        rear->link = newnode; // Link the new node to the rear
        rear = newnode; // Update the rear pointer
        rear->link = front; // Make it circular
    }
    printf("Element %d enqueued into the circular queue.\n", x);
}

void dequeue() {
    if (front == NULL && rear == NULL) { // Check if the queue is empty
        printf("Circular Queue is empty! Cannot dequeue.\n");
        return;
    }
    struct node* temp = front;
    if (front == rear) { // If there is only one element
        printf("Element %d dequeued from the circular queue.\n", front->data);
        front = rear = NULL; // Reset the queue
    } else {
        printf("Element %d dequeued from the circular queue.\n", front->data);
        front = front->link; // Move the front pointer
        rear->link = front; // Update the rear's link to maintain circularity
    }
    free(temp); // Free the memory of the dequeued node
}

void peek() {
    if (front == NULL && rear == NULL) { // Check if the queue is empty
        printf("Circular Queue is empty! No peek element.\n");
        return;
    }
    printf("The peek element is: %d\n", front->data); // Display the front element
}

void display() {
    if (front == NULL && rear == NULL) { // Check if the queue is empty
        printf("The circular queue is empty.\n");
        return;
    }
    struct node* temp = front;
    printf("The circular queue elements are: ");
    do {
        printf("%d ", temp->data);
        temp = temp->link;
    } while (temp != front); // Stop when we reach the front again
    printf("\n");
}

int main() {
    int x;
    char choice;
    while (1) {
        printf("\n---Circular Queue Operations---\n");
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