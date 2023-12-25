#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
    struct node*prev;
}; 
struct node* createDLL(){
    struct node*head=0;
    struct node*tail=0;
    int choice=1;
    while(choice){
        struct node*newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data:");
        scanf("%d",&newnode->data);
        newnode->next=0;
        newnode->prev=0;
        if(head==0){
            head=tail=newnode;
        }
        else {
            tail->next=newnode;
            newnode->prev=tail;
            tail=newnode;
        }
        printf("Do you want to continue?\n");
        printf("Press 1 to continue 0 to exit:");
        scanf("%d",&choice);
    }
    return head;
} 
void display(struct node*head){
    if(head==0){
        printf("List is empty!\n");
        return;
    }
    struct node*temp=head;
    while(temp!=0){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n");
}    
struct node* merge(struct node*X1,struct node*X2){
    struct node*temp=X1;
    while(temp->next!=0){
        temp=temp->next;
    }
    temp->next=X2;
    X2->prev=temp;
    return X1;
}
int main(){
    printf("LIST 1:\n");
    struct node*X1=createDLL();
    printf("LIST 2:\n");
    struct node*X2=createDLL();
    printf("LIST 1:\n");
    display(X1);
    printf("LIST 2:\n");
    display(X2);
    printf("After concatenation:\n");
    X1=merge(X1,X2);
    display(X1);
    return 0;
}