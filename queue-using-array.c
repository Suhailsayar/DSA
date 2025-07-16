#include<stdio.h>
#define max 100
int queue[max];
int front = -1;
int rear = -1;
void enqueue(int x){
    if(rear==max-1){
        printf("queue is full! cannot insert more elements");
        return;
    }
 if( front==-1 && rear== -1){
        front = 0;
        rear =0;
    }else {
    rear++;
}
queue[rear]=x;
printf("element enqueued = %d",x);
    }
void dequeue(){
    if(front==-1 || front>rear){
        printf("empty cannot dequeue");
        return;
    }
    printf("element %d dequeued from the queue.\n,",queue[front]);
    front++;
    if(front==rear){
        front = -1;
        rear = -1;
    }
    }
    void peek(){
    if(front==-1&&rear==-1)
    {
        printf("empty");
    return;
    }
    printf("the peek element is :%d",queue[front]);
    }
void display(){
    if(front==-1&&rear==-1){
        printf("theb queue is empty:");
        return;
    }
    printf("the queue elements are");
    for(int i = front;i<=rear;i++){
        printf("%d\n",queue[i]);
    }
    printf("\n");
}
int main(){
    int x;
    char choice;
    while(1){
        printf("---queue opeartions--");
        printf("1.enqueue\n");
        printf("2.dequeue\n");
        printf("3.peek\n");
        printf("4.display\n");
        printf("5.exit\n");
        printf("enter the choice:");
        scanf(" %c",&choice);
        switch(choice){
            case '1':
            printf("enter the value to insert:");
            scanf("%d",&x);
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
            printf("exiting the program\n");
            return 0;
            default:
            printf("enter a valid choice");
        }
       
    }
    return 0;
}