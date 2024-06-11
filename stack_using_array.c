#include<stdio.h>
int stack[100],choice,n,top,x,i;
void push(void);
void pop(void);
void display(void);
int main(){
    top=-1;
    printf("\nEnter the size of stack[max=100]:-");
    scanf("%d",&n);
    do{
        printf("\n\n\tStak Operation using array");
        printf("\n\t--------------------------");
        printf("\n1.Push");
        printf("\n2.Pop");
        printf("\n3.Display");
        printf("\n4.Exit");
        printf("\nEnter your choice:-");
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                push();
                break;
            }
            case 2:{
                pop();
                break;
            }
            case 3:{
                display();
                break;
            }
            case 4:{
                printf("\n\tExit Point");
                break;
            }
            default:{
                printf("\n\tPlease Enter a valid choice");
            }
        }
    }
    while(choice !=4);
    return 0;
}
void push(){
    if(top>=n-1){
        printf("\n\tStack is over flow");
    }
    else{
        printf("\nEnter a value to be pushed:-");
        scanf("%d",&x);
        top++;
        stack[top]=x;
    }
}
void pop(){
    if(top<=-1){
        printf("\n\tStack is under flow");
    }
    else{
        printf("\n\tThe Popped Elements is %d",stack[top]);
        top--;
    }
}
void display(){
    if(top>=0){
        printf("\n\tThe Elements in stack");
        for(i=top;i>=0;i--)
        printf("\n %d",stack[i]);
        printf("\n press next chioce");
    }
    else{
        printf("\n the stack is empty");
    }
}