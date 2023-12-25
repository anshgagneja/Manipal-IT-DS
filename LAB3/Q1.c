//Write a C program to check whether a given string is a palindrome or not using stacks
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
char stack[MAX];
int top=-1;
void push(char x){
    if(top==MAX-1){
        printf("Stack overflow!\n");
        return;
    }
    stack[++top]=x;
}
char pop(){
    if(top==-1){
        printf("Stack underflow!\n");
        return '#';
    }
    return stack[top--];
}
int main(){
    char str[MAX];
    printf("Enter string:");
    gets(str);
    for(int i=0;str[i]!='\0';i++){
        push(str[i]);
    }
    int i=0;
    int flag=1;
    while(top!=-1){
        if(str[i++]!=pop()){
            flag=0;
            break;
        }
    }
    if(flag==0){
        printf("Not a palindrome!\n");
    }
    else{
        printf("Palindrome String!\n");
    }

return 0;
}