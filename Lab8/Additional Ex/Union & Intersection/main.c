#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int info;
    struct node* next;
    struct node* prev;
}node;
node* head1=NULL;
node* head2=NULL;
node* uni=NULL;
node* inter=NULL;

node* CreateNode(int data){
    node* temp=(node*)malloc(sizeof(node));
    temp->next=temp->prev=NULL;
    temp->info=data;
    return temp;
}

node* insert(node** head, int data){
    node* temp=CreateNode(data);
    if(*head==NULL){
        *head=temp;
        return *head;
    }
    node* c=*head;
    while(c->next!=NULL)
        c=c->next;
    temp->prev=c;
    c->next=temp;
    return *head;
}

void display(node** head){
    if(*head==NULL){
        printf("Link list is empty\n");
        return;
    }
    node* c=*head;
    while(c!=NULL){
        printf("%d\t",c->info);
        c=c->next;
    }
    printf("\n");
}

node* Union(){
    node* A=head1;
    node* B=head2;
    while(A!=NULL){
        node* U=uni;
        int val=A->info;
        int flag=0;
        while(U!=NULL){
            if(U->info==val){
                flag=1;
                break;
            }
            U=U->next;
        }
        if(flag==0)
            insert(&uni,val);
        A=A->next;
    }
    while(B!=NULL){
        node* U=uni;
        int val=B->info;
        int flag=0;
        while(U!=NULL){
            if(U->info==val){
                flag=1;
                break;
            }
            U=U->next;
        }
        if(flag==0)
            insert(&uni,val);
        B=B->next;
    }
    return uni;
}

node* Intersection(){
    node* A=head1;
    while(A!=NULL){
        int val=A->info;
        int flag=0;
        node* B=head2;
        while(B!=NULL){
            if(B->info==val){
                flag=1;
                break;
            }
            B=B->next;
        }
        if(flag==1)
            insert(&inter,val);
        A=A->next;
    }
    return inter;
}

int main()
{
    int ch,data;
    while(1){
        printf("1.Insert_1\n2.Insert_2\n3.Display_1\n4.Display_2\n5.Union\n6.Intersection\n7.Display union\n8.Display intersection\n9.Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter value of node: ");
                scanf("%d",&data);
                insert(&head1,data);
                break;
            case 2:
                printf("Enter value of node: ");
                scanf("%d",&data);
                insert(&head2,data);
                break;
            case 3:
                display(&head1);
                break;
            case 4:
                display(&head2);
                break;
            case 5:
                Union();
                break;
            case 6:
                Intersection();
                break;
            case 7:
                printf("Union: ");
                display(&uni);
                break;
            case 8:
                printf("Intersection: ");
                display(&inter);
                break;
            case 9:
                printf("Exiting!!");
                exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
