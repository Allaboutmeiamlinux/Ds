#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node*next;
};
struct Node*head=NULL;
void append(int data){
    struct Node*new_node=(struct Node*)malloc(sizeof(struct Node));
    new_node->data=data;
    new_node->next=NULL;
    if(head==NULL){
        head=new_node;
        return;
    }
    struct Node*last_node=head;
    while(last_node->next!=NULL){
        last_node=last_node->next;
    }
    last_node->next=new_node;
}
void display(){
    struct Node*current=head;
    printf("\nLinked List");
    while(current!=NULL){
        printf("%d->",current->next);
        current=current->next;
    }
    printf("NULL");
}
void deleteNode(int key){
    struct Node*temp=head;
    struct Node*prer=NULL;
    if(temp!=NULL&&temp->data==key){
        head=temp->next;
        free(temp);
        printf("\nNode with data %d delecd successfully",key);
        return;
    }
    while(temp!=NULL&&temp->data!=key){
        prer=temp;
        temp=temp->next;
    }
    if(temp==NULL){
        printf("\nNode with data %d not found",key);
        return;
    }
    prer->next=temp->next;
    free(temp);
    printf("\nNode with data %d delecd successfully",key);
}
int main(){
    int chioce,data,key;
    while(1){
        printf("\n\n1.Append to the linked list");
        printf("\n2.Display the linked list");
        printf("\n3.Delect a node");
        printf("\n4.Exit");
        printf("\nEnter your choice:-");
        scanf("%d",&chioce);
        switch(chioce){
            case 1:
            printf("\nEnter data to append:-");
            scanf("%d",&data);
            append(data);
            break;

            case 2:
            display();
            break;

            case 3:
            printf("\nEnter data of the node to delete:-");
            scanf("%d",&key);
            deleteNode(key);
            break;

            case 4:
            printf("\nExiting program\t");
            exit(0);

            default:
            printf("\nInvalid choice");
        }
    }
    return 0;
}