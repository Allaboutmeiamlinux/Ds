#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node*next;
};
struct Node*top=NULL;
void push(int value){
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=top;
    top=newNode;
    printf("\nPushed %d on to the stack",value);
}
void pop(){
    if(top==NULL){
        printf("\nStack is underflow");
        return;
    }
    struct Node*temp=top;
    top=top->next;
    printf("\nPopped %d from the stack",temp->data);
    free(temp);
}
void display(){
    if(top==NULL){
        printf("\nStack is empty");
        return;
    }
    printf("\nstack elaments:-");
    struct Node*temp=top;
    while(temp!=NULL){
        printf("%d",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main(){
    int choice,value;
    do{
        printf("\n\nMenu");
        printf("\n1.Push");
        printf("\n2.Pop");
        printf("\n3.Display");
        printf("\n4.Exit");
        printf("\nEnter yuor choice:-");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("\nEnter value of push:-");
            scanf("%d",&value);
            push(value);
            break;

            case 2:
            pop();
            break;

            case 3:
            display();
            break;

            case 4:
            printf("\nExiting program");
            break;

            default:
            printf("Invalid choice \n");
        }
    }
    while(choice !=4);
    return 0;
}