#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* link;
};
struct node* front = NULL;
struct node* rear = NULL;
void enqueue(int x){
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->link = NULL;
    if(rear == NULL){
        front = rear = newnode;
    } else {
        rear->link = newnode;
        rear = newnode;
    }
    printf("Element %d enqueued into the queue.\n", x);
}
void dequeue() {
    if(front==NULL){
        printf("Queue is empty! Cannot dequeue.\n");
        return;
    }
    struct node* temp = front;
    printf("Element %d dequeued from the queue.\n", front->data);
    front = front->link;
    if(front == NULL) {
        rear = NULL; // If the queue becomes empty
    }
    free(temp);
}
void peek(){
    if(front == NULL) {
        printf("Queue is empty! No peek element.\n");
        return;
    }
    printf("The peek element is: %d\n", front->data);
}
void display(){
    if(front == NULL) {
        printf("The queue is empty.\n");
        return;
    }
    struct node* temp = front;
    printf("The queue elements are: ");
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}
int main() {
    int x;
    char choice;
    while(1) {
        printf("\n--Queue Operations--\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        switch(choice) {
            case '1':
                printf("Enter the element to enqueue: ");
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
                printf("Exiting the program!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}