// Write a program to input an infix expression and convert into its equivalent post fix 
// form and display. Operands can be single character
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
char stack[MAX];
char infix[MAX];
char postfix[MAX];
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
int isEmpty(){
    return top==-1;
}
int precedence(char c){
    switch(c){
        case '+':
        case '-':
        return 1;
        case '*':
        case '/':
        return 2;
        default:
        return 0;
    }
}
int isSpace(char ch){
    if(ch==' '||ch=='\t'){
        return 1;
    }
    return 0;
}
void inToPost(){
    char symbol,next;
    int j=0;
    for(int i=0;i<strlen(infix);i++){
        symbol=infix[i];
        if(!isSpace(symbol)){
            switch(symbol){
                case '(':
                push(symbol);
                break;
                case ')':
                while((next=pop())!='('){
                    postfix[j++]=next;
                }
                break;
                case '+':
                case '-':
                case '*':
                case '/':
                while(precedence(stack[top])>=precedence(symbol)){
                    postfix[j++]=pop();
                }
                push(symbol);
                break;
                default:
                postfix[j++]=symbol;
                break;
            }
        }       
    }
    while(!isEmpty()){
        postfix[j++]=pop();
    }
    postfix[j]='\0';
}
void display(){
    for(int i=0;postfix[i]!='\0';i++){
        printf("%c",postfix[i]);
    }
}
int main(){
    printf("Enter an infix expression:");
    gets(infix);
    inToPost();
    display();
return 0;
}