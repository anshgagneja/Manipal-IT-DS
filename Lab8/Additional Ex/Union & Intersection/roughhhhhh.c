#include<stdio.h>
#include<stdlib.h>
struct node{
    float coeff;
    int expo;
    struct node*next;
};
struct node*insert(struct node*head,float  coeff,int expo){
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->coeff=coeff;
    newnode->expo=expo;
    struct node*prev=0;
    struct node*temp=head;
    if(head==0||expo>(head->expo)){
        newnode->next=head;
        head=temp=newnode;
    }
    else{
        while(temp!=0&&(temp->expo)>expo){
            prev=temp;
            temp=temp->next;
        }
        newnode->next=temp;
        prev->next=newnode;
    }
    return head;
}
struct node*create(){
    struct node*head=0;
    int n;
    printf("Enter the number of terms:");
    scanf("%d",&n);
    float coeff;
    int expo;
    for(int i=0;i<n;i++){
        printf("Enter coeff of term %d:",i+1);
        scanf("%f",&coeff);
        printf("Enter expo of term %d:",i+1);
        scanf("%d",&expo);
        head=insert(head,coeff,expo);
    }
    return head;
}
void display(struct node*head){
    if(head==0){
        printf("No polynomial!\n");
    }
    struct node*temp=head;
    while(temp!=0){
        printf("(%.1fx^%d)",temp->coeff,temp->expo);
        temp=temp->next;
        if(temp!=0){
            printf("+ ");
        }
        else{
            printf("\n");
        }
    }
}
struct node*polyAdd(struct node*head1,struct node*head2){
    struct node*head3=0;
    struct node*temp1=head1;
    struct node*temp2=head2;
    struct node*temp3=head3;
    while(temp1!=0&&temp2!=0){
        if(temp1->expo>temp2->expo){
            head3=insert(head3,temp1->coeff,temp1->expo);
            temp1=temp1->next;
        }
        if(temp1->expo<temp2->expo){
            head3=insert(head3,temp2->coeff,temp2->expo);
            temp2=temp2->next;
        }
        else{
            head3=insert(head3,temp2->coeff+temp1->coeff,temp2->expo);
            temp2=temp2->next;
            temp1=temp1->next;
        }
    }
    while(temp1!=0){
        head3=insert(head3,temp1->coeff,temp1->expo);
        temp1=temp1->next;
    }
    while(temp2!=0){
        head3=insert(head3,temp2->coeff,temp2->expo);
        temp2=temp2->next;
    }
    return head3;
}

int main(){
    struct node*head1;
    head1=create();
    display(head1);
    struct node*head2;
    head2=create();
    display(head2);
    struct node*head3=polyAdd(head1,head2);
    display(head3);

return 0;
}