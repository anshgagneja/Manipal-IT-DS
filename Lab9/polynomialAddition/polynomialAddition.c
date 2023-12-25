#include<stdio.h>
#include<stdlib.h>
struct node{
    float coefficient;
    int exponent;
    struct node*next;
};
struct node* insert(struct node*head,float coeff,int expo){
    struct node*temp,*prev;
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->coefficient=coeff;
    newnode->exponent=expo;
    newnode->next=0;
    if(head==0||expo>(head)->exponent){
        newnode->next=head;
        head=newnode;
    }
    else {
        temp=head;
        prev=0;
        while(temp!=0 && expo<temp->exponent){
            prev=temp;
            temp=temp->next;
        }
        newnode->next=temp;
        prev->next=newnode;
    }
    return head;
}
struct node* create(){
    struct node*head=0;
    int n;
    printf("Enter the number of terms:");
    scanf("%d",&n);
    float coeff; int expo;
    for(int i=0;i<n;i++){
        printf("Enter coefficient for term %d:",i+1);
        scanf("%f",&coeff);
        printf("Enter the exponent for term %d:",i+1);
        scanf("%d",&expo);
        head=insert(head,coeff,expo);
    }
    return head;
}
struct node* polyAdd(struct node*head1,struct node*head2){
    struct node*temp1=head1;
    struct node*temp2=head2;
    struct node*head3=0;
    while(temp1!=0&&temp2!=0){
        if(temp1->exponent==temp2->exponent){
            head3=insert(head3,(temp1->coefficient+temp2->coefficient),temp1->exponent);
            temp1=temp1->next;
            temp2=temp2->next;
        }
        else if(temp1->exponent>temp2->exponent){
            head3=insert(head3,temp1->coefficient,temp1->exponent);
            temp1=temp1->next;
        }
        else {
            head3=insert(head3,temp2->coefficient,temp2->exponent);
            temp2=temp2->next;
        }
    }
    while(temp1!=0){
        head3=insert(head3,temp1->coefficient,temp1->exponent);
        temp1=temp1->next;
    }
    while(temp2!=0){
        head3=insert(head3,temp2->coefficient,temp2->exponent);
        temp2=temp2->next;
    }
    return head3;
}
void display(struct node*head){
    if(head==0){
        printf("No polynomial\n");
        return;
    }
    struct node*temp=head;
    while(temp!=0){
        printf("(%.1fx^%d)",temp->coefficient,temp->exponent);
        temp=temp->next;
        if(temp!=0){
            printf("+");
        }
        else {
            printf("\n");
        }
    }
}
int main(){
    printf("Enter the polynomial!\n");
    struct node*head1=create();
    display(head1);
    struct node*head2=create();
    display(head2);
    struct node*head3=polyAdd(head1,head2);
    display(head3);
return 0;
}
