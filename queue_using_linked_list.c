#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};

struct Node *front=NULL,*rear=NULL;

void insert(int);
void delete();
void display();

int main()
{
    int choice,value;
    printf("\n::Queue Implementation Using Linked List::\n");
    while(1)
    {
        printf("\tMENU");
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter Your Choice:-");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter The Value To Be Inserted:");
                    scanf("%d",&value);
                    insert(value);
                    break;
            case 2:delete(); break;
            case 3:display(); break;
            case 4:exit(0);

            default:printf("\nWrong Selection !!! Please Try Again !!!:");
        }
    }
    return 0;
}
void insert(int value)
{
    struct Node *newNode;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    if(!newNode)
    {
        printf("\nMemory Allocation Failed");
        return;
    }
    newNode->data=value;
    newNode->next=NULL;
    if(front == NULL)
    front = rear = newNode;
    else{
        rear->next =newNode;
        rear =newNode; 
    }
    printf("\n Insertion Is Success !!!\n");
}
void delete()
{
    if(front==NULL)
    printf("\nQueue Is Empty !!!");
else
{
struct Node *temp=front;
front=front->next;
printf("\nDeleted Element :%d\n",temp->data);
free(temp);
}
}
void display()
{
    if(front==NULL)
    printf("\nQueue Is Empty !!!\n");
    else
    {
        struct Node *temp=front;
        while(temp!=NULL)
        {
            printf("%d --->",temp->data);
            temp=temp->next;
        }
        printf("NULL\n");
    }
}