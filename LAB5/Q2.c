#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define MAX 100
int stack[MAX];
char postfix[MAX];
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
        return -99999;
    }
    return stack[top--];
}
int isOperator(char c){
    return c=='+'||c=='-'||c=='*'||c=='/';
}
void postEval(){
    for(int i=0;postfix[i]!='\0';i++){
        char symbol=postfix[i];
        if(isdigit(postfix[i])){
            push(symbol-'0');
        }
        if(isOperator(symbol)){
            int operand2=pop();
            int operand1=pop();
            int result;
            switch(symbol){
                case '+':
                result=operand1+operand2;
                break;
                case '-':
                result=operand1-operand2;
                break;
                case '*':
                result=operand1*operand2;
                break;
                case '/':
                if (operand2 != 0) {
                    result = operand1 / operand2;
                } 
                else{
                    printf("Error: Division by zero\n");
                    exit(1);
                }
                break;
            }
            push(result);
        }
    }
    printf("Result:%d",pop());
}
int main(){
    printf("Enter postfix expression:");
    gets(postfix);
    postEval();

return 0;
}