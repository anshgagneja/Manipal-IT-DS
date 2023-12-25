// Write a C program to convert a given decimal number to a number in any base using 
// stack.
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int stack[MAX];
int top=-1;
void push(int x){
    if(top==MAX-1){
        printf("Stack overflow!\n");
        return;
    }
    stack[++top]=x;
}
int pop(){
    if(top==-1){
        printf("Stack underflow!\n");
        return -1;
    }
    return stack[top--];
}
int isEmpty(){
    return top==-1;
}
int main(){
    int n;
    printf("Enter the decimal number:");
    scanf("%d",&n);
    int base;
    printf("Enter the base to convert:");
    scanf("%d",&base);
    while(n!=0){
        int rem=n%base;
        push(rem);
        n=n/base;
    }
    char b[]="0123456789ABCDEF";
    printf("After base conversion:");
    int x;
    while(!isEmpty()){
        x=pop();
        printf("%c ",b[x]);
    }
return 0;
}
