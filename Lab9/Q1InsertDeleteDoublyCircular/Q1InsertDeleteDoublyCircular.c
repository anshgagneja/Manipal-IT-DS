#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*prev;
    struct node*next;
};
struct node*head,*tail=0;
void display(){
    if (head == 0) {
        printf("List is empty.\n");
        return;
    }
    struct node*temp;
    temp=head;
    while(temp!=tail){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("%d\n",temp->data);
}
void createList(){
    struct node*newnode;
    int choice=1;
    while(choice){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data:");
        scanf("%d",&newnode->data);
        newnode->next=0;
        newnode->prev=0;
        if(head==0){
            head=tail=newnode;
            newnode->prev=tail;
            newnode->next=head;
        }
        else {
            newnode->prev=tail;
            newnode->next=head;
            tail->next=newnode;
            tail=newnode;
        }
        printf("Press 1 to continue and 0 to exit!\n");
        scanf("%d",&choice);
    }
    display();
}
void insertEle(){
    if(head==0){
        printf("List is empty!\n");
        return;
    }
    int pos;
    printf("Enter the position where you want to insert data:");
    scanf("%d",&pos);
    int count=0;
    struct node*temp=head;
    while(temp!=0&&count<pos-1){
        temp=temp->next;
        count++;
    }
    if(temp==0||pos<1){
        printf("Invalid position\n");
        return;
    }
    struct node*newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter data to be inserted at that pos:");
    scanf("%d",&newnode->data);
    if(pos==1){
        newnode->next=head;
        newnode->prev=tail;
        head->prev=newnode;
        head=newnode;
        tail->next=head;
    }
    else {
        newnode->next=temp;
        newnode->prev=temp->prev;
        temp->prev->next=newnode;
        temp->prev=newnode;
    }
    display();
}
void delEle(){
    if(head==0){
        printf("List is empty!\n");
        return;
    }
    int ele;
    printf("Enter the element to be deleted:");
    scanf("%d",&ele);
    struct node*temp=head;
    struct node*prev=0;
    while(temp!=0&&temp->data!=ele){
        prev=temp;
        temp=temp->next;
    }
    if(temp==0){
        printf("Element not found!\n");
        return;
    }
    if(temp==head){
        head=temp->next;
        free(temp);
        temp=head;
        tail->next=head;
    }
    else if(temp==tail){
        prev->next=head;
        tail=prev;
        free(temp);
        temp=tail;
        head->prev=tail;
    }
    else{
        prev->next=temp->next;
        free(temp);
        temp=prev->next;
    }
    display();
}
int main() {
    createList();
    int choice;

    while (1) {
        printf("\nDoubly Circular Linked List Menu:\n");
        printf("1. Insert an Element into Circular List\n");
        printf("2. Delete an Element from Circular List\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertEle();
                break;
            case 2:
                delEle();
                break;
            case 0:
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
