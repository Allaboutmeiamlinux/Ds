#include<stdio.h>
#define SIZE 100
void enqueue();
void dequeue();
void show();
int inp_arr[SIZE];
int Rear=-1;
int Front=-1;
int main(){
    int choice;
    while(1){
        printf("\n\n1.Enqueue operation");
        printf("\n2.Dequeue operation");
        printf("\n3.Display the queue");
        printf("\n4.Exit");
        printf("\nEnter Your Choice of Operation:-");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            enqueue();
            break;

            case 2:
            dequeue();
            break;

            case 3:
            show();
            break;

            case 4:
            return 0;
            
            default:
            printf("\nInvalid choice");
        }
    }
    return 0;
}
void enqueue(){
    int insert_item;
    if(Rear==SIZE-1)
    printf("\nOver Flow");
    else{
        if(Front==-1)
        Front=0;
        printf("\nElement to be inserted in the Queue:-");
        scanf("%d",&insert_item);
        Rear=Rear+1;
        inp_arr[Rear]=insert_item;
    }
}
void dequeue(){
    if(Front==-1||Front>Rear){
        printf("\nUnter Flow");
        return;
    }
    else{
        printf("\nElement delect from the queue:-%d",inp_arr[Front]);
        Front=Front+1;
    }
}
void show(){
    if(Front==-1)
    printf("\nEmpty queue");
    else{
        printf("\nQueue");
        for(int i=Front;i<=Rear;i++)
        printf("%d",inp_arr[i]);
        printf("\n");
    }
}