#include<stdio.h>
#include<stdlib.h>
//function prototypes
void display(int arr[],int size);
void insertelement(int arr[],int *size);
void deleteelement(int arr[],int *size);
void searchelement(int arr[],int size);
void updateelement(int arr[],int size);
void sortarray(int arr[],int size);
void calculateaddress(int arr[],int size);

int main(){
    int arr[10],size;
     size=0;
     int choice;
     printf("enter five elements of array(max 10 allowed):\n");
     for(int i = 0; i<5; i++){
        printf("enter element %d:",i+1);
        scanf("%d",&arr[i]);
        size++;
     }
     printf("--arrayoperations--");
     while (1) {
        printf("1.display array:\n");
        printf("2.insertelement:\n");
        printf("3.deleteelement:\n");
        printf("4.searchelement:\n");
        printf("5.updateelement:\n");
        printf("6.sortarray:\n");
        printf("7.calculateaddress:\n");
        printf("8.exit\n");
        printf("enter your choice:");
        scanf("%d",&choice);
         switch(choice){
            case 1:
            display(arr,size);
            break;
            case 2:
            insertelement(arr,&size);
            break;
            case 3:
            deleteelement(arr,&size);
            break;
            case 4:
            searchelement(arr,size);
            break;
            case 5:
            updateelement(arr,size);
            break;
            case 6:
            sortarray(arr,size);
            break;
            case 7:
            calculateaddress(arr,size);
            break;
            case 8:
            printf("exiting the program!");
            exit(0);
            default:
            printf("enter a valid choice!");

         }
     
     }
return 0;
}
//function defintions
void display(int arr[],int size){
    if(size==0){
        printf("array is empty:");
        return;
    }
    printf("array elements:");
    for(int i = 0; i<size;i++){
        printf("%d",arr[i]);
    }
    printf("\n");
}
//function to insertan element in array
void insertelement(int arr[],int *size){
    if(*size>=10){
        printf("the array is full cannot insert more elements!");
        return;
    }
    int pos, value;
    printf("enter the position(1 t0 %d) to insert element",*size+1);
    scanf("%d",&pos);
    if (pos<1 || pos>*size+1) {
        printf("enter a valid position!");
        return;
    }
    printf("enter the value to insert:");
    scanf("%d",&value);
    for(int i = *size;i>=pos;i--){
        arr[i]=arr[i-1];
    }
    arr[pos-1]=value;
    (*size)++;
}
//function to delete an element in array
void deleteelement(int arr[],int *size){
    if(*size==0){
        printf("the array is empty!");
        return;
    }
    int pos;
    printf("enter the position(1 to %d) to delete an element:",*size);
    scanf("%d",&pos);
    if(pos<1 || pos>*size){
        printf("invalid position!");
        return;
    }
    for(int i = pos-1;i<*size-1;i++){
        arr[i] = arr[i+1];
    }
    (*size)--;
}
//function to search for the element in an array
void searchelement(int arr[],int size){
    if(size==0){
        printf("the array is empty!");
        return;
    }
    int value,found = 0;
    printf("the value to search:");
    scanf("%d",&value);
    for(int i = 0;i< size;i++)
    {
        if(arr[i]==value){
            printf("the element is found at index= %d",i);
            found=1;
            break;
        }
    }
    if(!found){
        printf("the element not found!");
        return;
    }
}
//function to update an element in array
void updateelement(int arr[],int size){
    if(size==0){
        printf("the array is empty!");
        return;
    }
    int pos, value;
    printf("enter the position (1 to %d)to update",size);
    scanf("%d",&pos);
    if(pos<1 || pos>size){
       printf("invalid position!");
       return;
    }
    printf("enter the new value:");
        scanf("%d",&value);
        arr[pos-1]=value;
}
//function to sort the array
void sortarray(int arr[], int size) {
    if (size == 0) {
        printf("The array is empty\n");
        return;
    }

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("Array sorted successfully.\n");
    printf("The sorted array is: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
        
//function to calculate address
void calculateaddress(int arr[],int size){
    if(size==0){
        printf("the array is empty");
        return;
    }
    int index;
    printf("enter the index to calculate address(0 to %d)",size);
    scanf("%d",&index);
    if(index<1 || index>size){
        printf("invalid!");
        return;
    }
    // Address of the first element is the base address
    printf("Address of element at index %d: %p\n", index, (arr + index));

}