#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int queue[MAX];
int front=-1;
int rear=-1;

void enqueue(int x){
    if(front==-1&&rear==-1){
        front=rear=0;
        queue[rear]=x;
        return;
    }
    else if((rear+1)%MAX==front){
        printf("Queue overflow!\n");
        return;
    }
    else {
        rear=(rear+1)%MAX;
        queue[rear]=x;
        return;
    }
}
void dequeue(){
    if(front==-1&&rear==-1){
        printf("Queue underflow!\n");
        return;
    }
    else if(front==rear){
        printf("Dequeued element is:%d\n",queue[front]);
        rear=front=-1;
        return;
    }
    else {
        printf("Dequeued element is:%d\n",queue[front]);
        front=(front+1)%MAX;
        return;
    }
}
void display(){
    if(front==-1&&rear==-1){
        printf("Queue is empty!\n");
        return;
    }
    else {
        int i=front;
        while(i!=rear){
            printf("%d\t",queue[i]);
            i=(i+1)%MAX;
        }
        printf("%d\t",queue[rear]);
        return;
    }
}
void peek(){
    if(front==-1&&rear==-1){
        printf("Queue is empty!\n");
    }
    else {
        printf("Element at the front:%d\n",queue[front]);
    }
}
int main(){
    int choice,x;

    while(choice){
    printf("\nPress:\n1:enqueue\n2:dequeue\n3:display\n4:peek\n0:exit\n");
    printf("Enter choice:");
    scanf("%d",&choice);
        switch(choice){
        case 1:
        printf("Enter the element you want to enqueue:");
        scanf("%d",&x);
        enqueue(x);
        break;
        case 2:
        dequeue();
        break;
        case 3:
        display();
        break;
        case 4:
        peek();
        break;
        case 0:
        break;
    }
    }

    return 0;
}