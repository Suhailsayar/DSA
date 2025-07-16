#include<stdio.h>
#define max 100

int stack[max];
int top = -1;

void push(int x) {
    if (top == max - 1) {
        printf("Overflow! No more elements can be inserted.\n");
        return;
    } else {
        top++;
        stack[top] = x;
        printf("Element %d pushed onto the stack.\n", x);
    }
}

void display() {
    if (top == -1) {
        printf("Stack underflow! No elements to display.\n");
        return;
    } else {
        printf("The stack elements are: ");
        for (int i = top; i >= 0; i--) { // Iterate from top to 0
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}
void pop(){
    if(top==-1){
        printf("underflow! no elemnets present to pop!");
    }
    else{
        printf("the popped element is %d",stack[top]);
        top--;
    }
}
void peek(){
    if(top==-1){
        printf("underflow no peek element:");
        return;
    }
    else{
        printf("%d",stack[top]);
    }
}



int main() {
    int x;
    char choice;

    while (1) {
        printf("--Menu--\n");
        printf("1. Push\n");
        printf("2. Display\n");
        printf("3.pop\n");
        printf("4.peek\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice); // Add a space before %c to handle newline

        switch (choice) {
            case '1':
                printf("Enter the value to insert: ");
                scanf("%d", &x);
                push(x);
                break;

            case '2': 
                display();
                break;

            case '3': 
               pop();
               break;

               case '4':
               peek();
               break;

               case '5':
               printf("exiting the program");
               return 0;

            default:
                printf("Enter a valid choice!\n");
        }
    }

    return 0;
}