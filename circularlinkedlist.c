#include<stdio.h>
#include<stdlib.h>
#include <string.h>

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL; // Global head pointer

void createcLL() { // Function to create a circular linked list
    struct node *temp, *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
        newnode->next = head; // Point to itself to make it circular
    } else {
        temp = head;
        while (temp->next != head) { // Traverse to the last node
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head; // Make it circular
    }
}
//function to traverse the circular linked list
void traversecLL() {
    if (head == NULL) {
        printf("The circular linked list is empty.\n");
        return;
    }
    struct node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}
//display the circular linked list
void displaycLL() {
    if (head == NULL) {
        printf("The circular linked list is empty.\n");
        return;
    }
    struct node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}
//function to delete a node from the circular linked list
