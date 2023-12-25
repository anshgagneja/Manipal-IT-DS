#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int info;
    char name[10];
    struct node* next;
    struct node* prev;
}node;
int count=1;
node* head=NULL;

node* CreateNode(int data){
    node* temp=(node*)malloc(sizeof(node));
    temp->next=temp->prev=NULL;
    temp->info=data;
    strcpy(temp->name,"User");
    temp->name[4]='0'+count;
    temp->name[5]='\0';
    count++;
    return temp;
}

node* book(){
    int data;
    printf("Enter time: ");
    scanf("%d",&data);
    node* temp=CreateNode(data);
    if(head==NULL){
        head=temp;
        printf("Booked machine for %d minutes\n",temp->info);
        return head;
    }
    node* current=head;
    while(current->next!=NULL)
        current=current->next;
    current->next=temp;
    temp->prev=current;
    printf("Booked machine for %d minutes\n",temp->info);
    return head;
}

node* wash(){
    if(head==NULL){
        printf("Empty queue\n");
        return NULL;
    }
    node* current=head;
    if(current->next==NULL){
        printf("%s takes %d minutes to wash\n",current->name,current->info);
        printf("Process complete\n");
        count--;
        head=NULL;
        free(current);
        return head;
    }
    printf("%s takes %d minutes to wash\n",current->name,current->info);
    printf("Process complete\n");
    current->next->prev=NULL;
    head=current->next;
    free(current);
    return head;
}

void display(){
    if(head==NULL){
        printf("Queue is empty\n");
        return;
    }
    node* cur=head;
    while(cur!=NULL){
        printf("%s has booked for %d minutes\n",cur->name,cur->info);
        cur=cur->next;
    }
}

int main()
{
    int ch;
    while(1){
        printf("1.Booking\n2.Wash\n3.Display\n4.Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                book();
                break;
            case 2:
                wash();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting!!");
                exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
