#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 25
char stack[MAX][25];
char postfix[MAX];
int top=-1;
void push(char x[]){
    if(top==MAX-1){
        printf("Stack Overflow!\n");
        return;
    }
    strcpy(stack[++top],x);
}
char*pop(){
    if(top==-1){
        printf("Stack underflow!\n");
        return "#";
    }
    return stack[top--];
}
void postToIn(){
    char op1[MAX],op2[MAX],res[MAX],temp[2];
    for(int i=0;postfix[i]!='\0';i++){
        char c=postfix[i];
        temp[0]=postfix[i];
        temp[1]='\0';
        if(c=='+'||c=='-'||c=='*'||c=='/'){
            strcpy(op2,pop());
            strcpy(op1,pop());
            strcpy(res,"(");
            strcat(res,op1);
            strcat(res,temp);
            strcat(res,op2);
            strcat(res,")");
            push(res);
        }
        else{
            push(temp);
        }
    }
    if(top!=0){
        printf("Invalid expression!\n");
    }
    else{
        printf("Corresponding Infix:%s",pop());
    }
}
int main(){
    printf("Enter a postfix expression:");
    gets(postfix);
    postToIn();
return 0;
}