#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
struct node* create(struct node*h){
    struct node*head=h;
    struct node*temp,*newnode;
    int choice=1;
    while(choice){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data:");
        scanf("%d",&newnode->data);
        newnode->next=0;
        if(head==0){
            head=temp=newnode;
        }
        else {
            temp->next=newnode;
            temp=newnode;
        }
        printf("Enter 1 to continue & 0 to exit:");
        scanf("%d",&choice);
    }
    return head;
}
void display(struct node*head){
    struct node*temp;
    temp=head;
    while(temp!=0){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void merge(){
    struct node*head1,*head2;
    head1=head2=0;
    printf("LIST 1:\n");
    head1=create(head1);
    printf("LIST 2:\n");
    head2=create(head2);
    struct node*temp=head1;
    while(temp->next!=0){
        temp=temp->next;
    }
    temp->next=head2;
    temp=head1;
    int count=1;
    while(temp->next!=0){
        count++;
        temp=temp->next;
    }
    int tempo;
    for(int i=0;i<count-1;i++){
        temp=head1;
        for(int j=0;j<count-i-1;j++){
            if(temp->data>temp->next->data){
                tempo=temp->data;
                temp->data=temp->next->data;
                temp->next->data=tempo;
            }
            temp=temp->next;
        }
    }
    display(head1);
}
int main(){
    merge();
return 0;
}