#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int queue[MAX];
int front =-1;
int rear=-1;

void enqueue(int x){
    if(rear==MAX-1){
        printf("Queue overflow!\n");
    }
    else if(front==-1&&rear==-1){
        front=rear=0;
        queue[rear]=x;
    }
    else{
        rear++;
        queue[rear]=x;
    }
}
void dequeue(){
    if(front ==-1&&rear==-1){
        printf("Queue underflow!\n");
    }
    else if(front==rear){
        printf("Dequeued element is:%d\n",queue[front]);
        front=rear=-1;
    }
    else {
        printf("Dequeued element is:%d\n",queue[front]);
        front++;
    }
}
void display(){
    if(front==-1&&rear==-1){
        printf("Queue is empty!\n");
    }
    else {
        for(int i=front ;i<rear+1;i++){
            printf("%d\t",queue[i]);
        }
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
    //do function calls

    return 0;
}