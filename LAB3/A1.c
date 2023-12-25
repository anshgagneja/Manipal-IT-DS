//Write a C program to implement Multiple stacks using arrays.
#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int top[MAX],b[MAX],arr[MAX];
void createStack(int n){
    int i;
    for(i=0;i<n;i++){
        top[i]=b[i]=(MAX/n)*i-1;
    }
    b[i]=MAX-1;
}
void push(int x){
    int n;
    printf("Enter the stack number:");
    scanf("%d",&n);
    if(top[n-1]==b[n]){
        printf("Stack overflow!!\n");
        return;
    }
    arr[++top[n-1]]=x;
}
void pop(){
    int n;
    printf("Enter the stack number:");
    scanf("%d",&n);
    if(top[n-1]==b[n-1]){
        printf("Stack underflow!!\n");
        return;
    }
    printf("Popped element:%d\n",arr[top[n-1]--]);
}
void display(){
    int n;
    printf("Enter the stack number:");
    scanf("%d",&n);
    if(top[n-1]==b[n-1]){
        printf("Empty stack!\n");
        return;
    }
    for(int i=top[n-1];i>b[n-1];i--){
        printf("%d\t",arr[i]);
    }
    printf("\n");
}
int main(){
    int n;
    printf("Enter the number of stacks:");
    scanf("%d",&n);
    createStack(n);
    int ch;
    int x;
    do{
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter the element:");
                scanf("%d",&x);
                push(x);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting now!!");
                break;
            default: printf("Invalid option");

        }
    } while(ch!=4);
return 0;
}