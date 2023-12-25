//Write a C program to check for matching parenthesis in a given expression
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 25
char stack[MAX];
int top=-1;
void push(char x){
    if(top==MAX-1){
        printf("Stack Overflow!\n");
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
int isEmpty(){
    return top==-1;
}
int matchingParanthesis(char a,char b){
    if(a=='('&&b==')'||a=='{'&&b=='}'||a=='['&&b==']'){
        return 1;
    }
    return 0;
}
int checkBalanced(char str[MAX]){
    for(int i=0;i<strlen(str);i++){
        if(str[i]=='('||str[i]=='{'||str[i]=='['){
            push(str[i]);
        }
        if(str[i]==')'||str[i]=='}'||str[i]==']'){
            if(isEmpty()){
                printf("Right brackets are more than left brackets!\n");
                return 0;
            }
            if(!matchingParanthesis(pop(),str[i])){
                printf("Mismatched paranthesis!\n");
                return 0;
            }
        }
    }
    if(isEmpty()){
        return 1;
    }
    else{
        printf("Left brackets are more than right brackets!!\n");
        return 0;
    }
}
int main(){
    char str[MAX];
    printf("Enter an expression:");
    gets(str);
    int x=checkBalanced(str);
    if(x){
        printf("Paranthesis are well balanced and matched!!");
    }
    else{
        printf("Paranthesis are not balanced and matched!!");
    }

return 0;
}