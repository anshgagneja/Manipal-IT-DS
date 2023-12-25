#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int info;
    struct node* next;
}node;
node* stack=NULL;
node* queue=NULL;

node* CreateNode(int data){
    node* temp=(node*)malloc(sizeof(node));
    temp->next=NULL;
    temp->info=data;
    return temp;
}

void display(node** head){
    if(*head==NULL){
        printf("Empty. Nothing to display\n");
        return;
    }
    node* c=*head;
    while(c!=NULL){
        printf("%d\t",c->info);
        c=c->next;
    }
    printf("\n");
}

node* push(){
    int val;
    printf("Enter value: ");
    scanf("%d",&val);
    node* temp=CreateNode(val);
    if(stack==NULL)
        stack=temp;
    else{
        node* current=stack;
        temp->next=current;
        stack=temp;
    }
    return stack;
}

node* pop(){
    if(stack==NULL){
        printf("Underflow\n");
        return NULL;
    }
    node* current=stack;
    stack=current->next;
    printf("Popped element: %d\n",current->info);
    free(current);
    return stack;
}

node* enq(){
    int val;
    printf("Enter value: ");
    scanf("%d",&val);
    node* temp=CreateNode(val);
    if(queue==NULL){
        queue=temp;
        return queue;
    }
    node* c=queue;
    while(c->next!=NULL)
        c=c->next;
    c->next=temp;
    return queue;
}

node* deq(){
    if(queue==NULL){
        printf("Underflow\n");
        return NULL;
    }
    node* current=queue;
    queue=current->next;
    printf("Dequeued element: %d\n",current->info);
    free(current);
    return queue;
}

int main()
{
    int ch;
    while(1){
        printf("1.Push\n2.Pop\n3.Enqueue\n4.Dequeue\n5.Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                push();
                printf("Stack: ");
                display(&stack);
                break;
            case 2:
                pop();
                printf("Stack: ");
                display(&stack);
                break;
            case 3:
                enq();
                printf("Queue: ");
                display(&queue);
                break;
            case 4:
                deq();
                printf("Queue: ");
                display(&queue);
                break;
            case 5:
                printf("Exiting!!");
                exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
