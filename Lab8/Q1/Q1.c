#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
    struct node*prev;
}; 
struct node*head=0;
struct node*tail=0;
void createDLL(){
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
} 
void insertAtRearEnd(){
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data to insert at the end:");
    scanf("%d",&newnode->data);
    newnode->prev=0;
    newnode->next=0;
    if(head==0){
        head=tail=newnode;
    }
    else {
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }
}
void delFromRearEnd(){
    struct node*temp=tail;
    if(tail==0){
        printf("List is empty! Can't delete!\n");
        return;
    }
    if(head==tail){
        head=tail=0;
        free(temp);
    }
    else {
        tail=temp->prev;
        tail->next=0;
        free(temp);
    }
}
void insertAtGivenPos(){
    int pos;
    printf("Enter the position to insert (1-based index): ");
    scanf("%d", &pos);
    int count = 0;
    struct node *temp = head;
    while(temp!=0&&count<pos-1){ 
        count++;
        temp=temp->next;
    }
    if(temp==0||pos<1){
       printf("Invalid position!\n");
       return;
    }
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data to be inserted there:");
    scanf("%d",&newnode->data);
    newnode->prev=temp->prev;
    newnode->next=temp;
    if(temp->prev!=0){
       temp->prev->next=newnode;
       temp->prev = newnode;
    } 
    else{
       head=newnode;
       temp->prev = newnode;
    }
}
void delFromGivenPos(){
    int pos;
    printf("Enter the position of the element you want to delete:");
    scanf("%d",&pos);
    struct node*temp=head;
    int count=0;
    while(temp!=0&&count<pos-1){
        temp=temp->next;
        count++;
    }
    if(temp==0){
        printf("Invalid position!\n");
    }
    else {
        if(temp->prev!=0&&temp->next!=0){
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            free(temp);
        }
        else {
            if(temp->prev==0){
                head=temp->next;
                head->prev=0;
                free(temp);
            }
            else{
                tail=temp->prev;
                tail->next=0;
                free(temp);
            }
        }
    }
}
void insertAfterAnotherEle(){
    int target;
    printf("Enter the element after which you want to insert an element:");
    scanf("%d",&target);
    struct node*temp=head;
    while(temp!=0&&temp->data!=target){
        temp=temp->next;
    }
    if(temp==0){
        printf("Element not found in the list!\n");
        return;
    }
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the element to be inserted there:");
    scanf("%d",&newnode->data);
    if(temp==tail){
        newnode->prev=temp;
        newnode->next=0;
        temp->next=newnode;
        tail=newnode;
    }
    else{
        newnode->prev=temp;
        newnode->next=temp->next;
        temp->next->prev=newnode;
        temp->next=newnode;
    }
}
void insertBeforeAnotherEle(){
    int target;
    printf("Enter the element before which you want to insert an element:");
    scanf("%d",&target);
    struct node*temp=head;
    struct node*prevnode=0;
    while(temp!=0&&temp->data!=target){
        prevnode=temp;
        temp=temp->next;
    }
    if(temp==0){
        printf("Element not found in the list!\n");
        return;
    }
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the element to be inserted there:");
    scanf("%d",&newnode->data);
    if(temp==head){
        newnode->prev=0;
        newnode->next=temp;
        temp->prev=newnode;
        head=newnode;
    }
    else{
        newnode->prev=prevnode;
        newnode->next=temp;
        prevnode->next=newnode;
        temp->prev=newnode;
    }
}
void traverse(){
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
void reverse(){
    struct node*currentnode=head;
    while(currentnode!=0){
        struct node*nextnode=currentnode->next;
        currentnode->next=currentnode->prev;
        currentnode->prev=nextnode;
        currentnode=nextnode;
    }
    currentnode=head;
    head=tail;
    tail=currentnode;
}
int main() {
    int choice;
    createDLL();
    while (1) {
        printf("\nDoubly Linked List Menu:\n");
        printf("1. Insert an element at the rear end of the list\n");
        printf("2. Delete an element from the rear end of the list\n");
        printf("3. Insert an element at a given position of the list\n");
        printf("4. Delete an element from a given position of the list\n");
        printf("5. Insert an element after another element\n");
        printf("6. Insert an element before another element\n");
        printf("7. Traverse the list\n");
        printf("8. Reverse the list\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insertAtRearEnd();
                break;
            case 2:
                delFromRearEnd();
                break;
            case 3:
                insertAtGivenPos();
                break;
            case 4:
                delFromGivenPos();
                break;
            case 5:
                insertAfterAnotherEle();
                break;
            case 6:
                insertBeforeAnotherEle();
                break;
            case 7:
                traverse();
                break;
            case 8:
                reverse();
                break;
            case 0:
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}





