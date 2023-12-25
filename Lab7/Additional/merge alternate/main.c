#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int info;
    struct node* next;
}node;
node* start1=NULL;
node* start2=NULL;

node* CreateNode(int data){
    node* temp=(node*)malloc(sizeof(node));
    temp->next=NULL;
    temp->info=data;
    return temp;
}

node* insert_start(node **start){
    int val;
    printf("Enter value: ");
    scanf("%d",&val);
    node* temp=CreateNode(val);
    if(*start==NULL){
        *start=temp;
        return *start;
    }
    temp->next=*start;
    *start=temp;
    return *start;
}

void display1(node **start){
    if(*start==NULL){
        printf("List empty.\n");
        return;
    }
    node* c=*start;
    while(c!=NULL){
        printf("%d\t",c->info);
        c=c->next;
    }
    printf("\n");
}

/*void display2(){
    if(start2==NULL){
        printf("List empty.\n");
        return;
    }
    node* c=start2;
    while(c!=NULL){
        printf("%d\t",c->info);
        c=c->next;
    }
    printf("\n");
}*/

node* merge(){
    node* p1=start1;
    node* p2=start2;
    node* c=NULL, *d=NULL;
    while(p1!=NULL&&p2!=NULL){
        c=p1->next;
        d=p2->next;
        p1->next=p2;
        p2->next=c;
        p1=c;
        p2=d;
    }
    start2=NULL;
    return start1;
}

int main()
{
    int ch,op;
    while(1){
        printf("1.Insert1\n2.Insert2\n3.Merge Alternate\n4.Display1\n5.Display2\n6.Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                insert_start(&(start1));
                break;
            case 2:
                insert_start(&(start2));
                break;
            case 3:
                merge();
                break;
            case 4:
                display1(&(start1));
                break;
            case 5:
                display1(&(start2));
                break;
            case 6:
                printf("Exiting now!!");
                exit(0);
        }
    }
    return 0;
}
