#include<stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
void createLinkedList(struct Node** head);
void displayLinkedList(struct Node* head);
void insertAtFront(struct Node** head);
void insertAtRear(struct Node** head);
void insertBeforeData(struct Node** head, int y);
void deleteAtFront(struct Node** head);
void deleteAtRear(struct Node** head);
void deleteData(struct Node** head, int x);
void reverseLinkedList(struct Node** head);
int main() {
    struct Node* head = NULL;
    int choice, y, x;
    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Create Linked List\n");
        printf("2. Display Linked List\n");
        printf("3. Insert at Front\n");
        printf("4. Insert at Rear\n");
        printf("5. Insert Before Data Y\n");
        printf("6. Delete at Front\n");
        printf("7. Delete at Rear\n");
        printf("8. Reverse Linked List\n");
        printf("9. Delete Data X\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createLinkedList(&head);
                break;
            case 2:
                displayLinkedList(head);
                break;
            case 3:
                insertAtFront(&head);
                break;
            case 4:
                insertAtRear(&head);
                break;
            case 5:
                printf("Enter data Y: ");
                scanf("%d", &y);
                insertBeforeData(&head, y);
                break;
            case 6:
                deleteAtFront(&head);
                break;
            case 7:
                deleteAtRear(&head);
                break;
            case 8:
                reverseLinkedList(&head);
                break;
            case 9:
                printf("Enter data X: ");
                scanf("%d", &x);
                deleteData(&head, x);
                break;
            case 10:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
void createLinkedList(struct Node** head) {
    int data;
    char choice;
    struct Node* newNode, *temp;
    do {
        printf("Enter data: ");
        scanf("%d", &data);
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = NULL;
        if (*head == NULL) {
            *head = newNode;
        } else {
            temp = *head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
        printf("Add another node? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
}
void displayLinkedList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Linked List: ");
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void insertAtFront(struct Node** head) {
    int data;
    printf("Enter data to insert at front: ");
    scanf("%d", &data);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
    printf("Node inserted at front.\n");
}
void insertAtRear(struct Node** head) {
    int data;
    printf("Enter data to insert at rear: ");
    scanf("%d", &data);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    printf("Node inserted at rear.\n");
}
void insertBeforeData(struct Node** head, int y) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    int data;
    printf("Enter data to insert before %d: ", y);
    scanf("%d", &data);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    if ((*head)->data == y) {
        newNode->next = *head;
        *head = newNode;
        printf("Node inserted before %d.\n", y);
        return;
    }
    struct Node *prev = NULL, *curr = *head;
    while (curr != NULL && curr->data != y) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL) {
        printf("Data %d not found in the list.\n", y);
        free(newNode);
        return;
    }
    newNode->next = curr;
    prev->next = newNode;
    printf("Node inserted before %d.\n", y);
}
void deleteAtFront(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
    printf("Node deleted from front.\n");
}
void deleteAtRear(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        printf("Last node deleted.\n");
        return;
    }
    struct Node* temp = *head;
    while (temp->next->next != NULL)
        temp = temp->next;
    free(temp->next);
    temp->next = NULL;
    printf("Node deleted from rear.\n");
}
void deleteData(struct Node** head, int x) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *head;
    if (temp->data == x) {
        *head = temp->next;
        free(temp);
        printf("Node with data %d deleted.\n", x);
        return;
    }
    struct Node *prev = NULL;
    while (temp != NULL && temp->data != x) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Data %d not found in the list.\n", x);
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Node with data %d deleted.\n", x);
}
void reverseLinkedList(struct Node** head) {
    struct Node *prev = NULL, *current = *head, *next = NULL;
    while (current != NULL) {
        next = current->next; // Store next node
        current->next = prev; // Reverse the link
        prev = current;       // Move prev to current
        current = next;       // Move to next node
    }
    *head = prev; // Update head to new first node
    printf("Linked List reversed.\n");
}