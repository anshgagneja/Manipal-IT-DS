#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int info;
    struct node* next;
    struct node* prev;
}node;
node* head1=NULL;
node* head2=NULL;
node* sum=NULL;

node* CreateNode(int data){
    node* temp=(node*)malloc(sizeof(node));
    temp->info=data;
    temp->next=temp->prev=NULL;
    return temp;
}

node* insert(node** head,int data){
    node* temp=CreateNode(data);
    if(*head==NULL){
        *head=temp;
        return *head;
    }
    node* c=*head;
    while(c->next!=NULL)
        c=c->next;
    c->next=temp;
    temp->prev=c;
    return *head;
}

void display(node* head){
    if(head==NULL){
        printf("Number not entered\n");
        return;
    }
    node* c=head;
    while(c!=NULL){
        printf("%d",c->info);
        c=c->next;
    }
}

node* add(){
    int carry=0,s;
    node* p1=head1;
    node* p2=head2;
    while(p1 && p2){
        s=p1->info+p2->info+carry;
        carry=s/10;
        insert(&sum, s%10);
        p1=p1->next;
        p2=p2->next;
    }
    while(p1){
        s=p1->info+carry;
        carry=s/10;
        insert(&sum, s%10);
        p1=p1->next;
    }
    while(p2){
        s=p2->info+carry;
        carry=s/10;
        insert(&sum, s%10);
        p2=p2->next;
    }
    if(carry!=0)
        insert(&sum,carry);
    return sum;
}

node* reverse(){
    node*p=sum;
    node*q=NULL;
    node*r=NULL;
    while(p!=NULL){
        q=p;
        p=p->next;
        q->next=r;
        q->prev=p;
        r=q;
    }
    sum=q;
    return sum;
}

int main()
{
    char int1[60], int2[60];
    int i;
    printf("Enter 1st integer: ");
    scanf("%s",&int1);
    strrev(int1);
    for(i=0;int1[i]!='\0';i++)
        insert(&head1,int1[i]-'0');

    printf("Enter 2nd integer: ");
    scanf("%s",&int2);
    strrev(int2);
    for(i=0;int2[i]!='\0';i++)
        insert(&head2,int2[i]-'0');

    add();
    reverse();
    printf("%s + %s = ",strrev(int1),strrev(int2));
    display(sum);
    return 0;
}
