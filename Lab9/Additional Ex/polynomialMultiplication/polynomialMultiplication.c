#include<stdio.h>
#include<stdlib.h>
struct node{
    float coeff;
    int exp;
    struct node*next;
};
struct node*insert(struct node*head,float co,int exp){
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->coeff=co;
    newnode->exp=exp;
    newnode->next=0;
    if(head==0||head->exp<exp){
        newnode->next=head;
        head=newnode;
    }
    else {
        struct node*temp=head;
        while(temp->next!=0&&temp->next->exp>exp){
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
    return head;
}
struct node*create(){
    struct node*head=0;
    int n;
    printf("Enter the number of terms:");
    scanf("%d",&n);
    float coeff;
    int exp;
    for(int i=0;i<n;i++){
        printf("Enter the coeff of term %d:",i+1);
        scanf("%f",&coeff);
        printf("Enter the exponent of term %d:",i+1);
        scanf("%d",&exp);
        head=insert(head,coeff,exp);
    }   
    return head;
}
void display(struct node*head){
    if(head==0){
        printf("No polynomial\n");
        return;
    }
    struct node*temp=head;
    while(temp!=0){
        printf("(%.1fX^%d)",temp->coeff,temp->exp);
        temp=temp->next;
        if(temp!=0){
            printf("+");
        }
        else {
            printf("\n");
        }
    }
}
void mulPoly(struct node*head1,struct node*head2){
    if(head1==0||head2==0){
        printf("No polynomial\n");
        return;
    }
    struct node*temp1=head1;
    struct node*temp2=head2;
    struct node*head3=0;
    while(temp1!=0){
        temp2=head2;
        while(temp2!=0){
            head3=insert(head3,temp1->coeff*temp2->coeff,temp1->exp+temp2->exp);
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }
    printf("\nAfter multiplying:\n");
    display(head3);
    struct node*temp3=head3;
    struct node*temp=0;
    while(temp3->next!=0){
        if(temp3->exp==temp3->next->exp){
            temp3->coeff=temp3->coeff+temp3->next->coeff;
            temp=temp3->next;
            temp3->next=temp3->next->next;
            free(temp);
        }
        else{
            temp3=temp3->next;
        }
    }
    printf("\nAfter simplification:\n");
    display(head3);
}
int main(){
    struct node*head1,*head2;
    head1=create();
    display(head1);
    head2=create();
    display(head2);
    mulPoly(head1,head2);
return 0;
}