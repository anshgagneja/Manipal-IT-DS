#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX 100

char stack[MAX],infix[MAX],prefix[MAX];
int top=-1;

void push(char ch){
    top++;
    stack[top]=ch;
}
char pop(){
    char ch=stack[top];
    top--;
    return ch;
}
int isEmpty(){
    if(top==-1){
        return 1;
    }
    return 0;
}
void reverseString(char*infix){
    int n=strlen(infix);
    for(int i=0;i<strlen(infix)/2;i++){
        char temp=infix[i];
        infix[i]=infix[n-i-1];
        infix[n-i-1]=temp;
    }
}
int precedence(char ch){
    switch(ch){
        case '+':
        case '-':
        return 1;
        case '*':
        case '/':
        return 2;
        case '^':
        return 3;
        default :
        return 0;
    }
}
void inToPre(){
    char symbol,next;
    int j=0;
    for(int i=0;i<strlen(infix);i++){
        symbol=infix[i];
        switch(symbol){
            case ')':
            push(symbol);
            break;
            case '(':
            while((next=pop())!=')'){
                prefix[j]=next;
                j++;
            }
            break;
            case '+':
            case '-':
            case '*':
            case '/':
            while(precedence(stack[top])>precedence(symbol)){
                prefix[j]=pop();
                j++;
            }
            push(symbol);
            break;
            default:
            prefix[j]=symbol;
            j++;
            break;
        }
    }
    while(!isEmpty()){
        prefix[j]=pop();
        j++;
    }
    prefix[j]='\0';
    reverseString(prefix);
    
}
void print(){
    printf("The corresponding prefix expression is:");
    for(int i=0;prefix[i]!='\0';i++){
        printf("%c",prefix[i]);
    }
    printf("\n");
}

int main(){
    printf("Enter an algebraic infix expression:");
    gets(infix);
    reverseString(infix);
    inToPre();
    print();

    return 0;
}