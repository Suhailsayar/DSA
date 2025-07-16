#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* link;
};
struct node* top = 0;
void push(int x){
    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->link=top;
    top=newnode;
}
void pop(){
    if(top==NULL){
        printf("the stack is empty");
        return;
    }
    struct node * temp =top;

    printf("the poped element is %d\n",top->data);
 top=top->link;
 free(temp);
}
void peek(){
    if(top==NULL){
        printf("the stack is empty:");
        return;
    }
    printf("the topmost element is %d",top->data);
}
void display(){
    if(top==NULL){
        printf("the top is empty");
        return;
    }
    struct node* temp = top;
    printf("the elements are:\n");
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp = temp->link;
    }
    printf("\n");
}
int main(){
    int x;
    char choice;
    while(1){
        printf("\n--stack operations---\n");
        printf("1.push\n");
        printf("2.pop\n");
        printf("3.peek\n");
        printf("4.display\n");
        printf("5.exit\n");
        printf("enter the choice:");
        scanf(" %c",&choice);
        switch(choice){
            case '1':
            printf("enter the value to push:");
            scanf("%d",&x);
            push(x);
            break;
            case '2':
            pop();
            break;
            case '3':
            peek();
            case '4':
            display();
            break;
            case '5':
            printf("exiting the program");
            return 0;
            default:
            printf("enter a valid choice");
        }
    }
    return 0;

}