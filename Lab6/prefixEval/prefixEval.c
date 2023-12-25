#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
char prefix[MAX];
int top = -1;

void push(int x) {
    top++;
    stack[top] = x;
}

int pop() {
    int x = stack[top];
    top--;
    return x;
}

int isEmpty() {
    if (top == -1) {
        return 1;
    }
    return 0;
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int preEval(char* expression) {
    int result;
    int length = strlen(expression);
    
    for (int i = length - 1; i >= 0; i--) {
        if (isdigit(expression[i])) {
            push(expression[i] - '0'); // Convert character to integer
        } else if (isOperator(expression[i])) {
            int operand1 = pop();
            int operand2 = pop();
            
            switch (expression[i]) {
                case '+':
                    push(operand1 + operand2);
                    break;
                case '-':
                    push(operand1 - operand2);
                    break;
                case '*':
                    push(operand1 * operand2);
                    break;
                case '/':
                    push(operand1 / operand2);
                    break;
                case '^':
                    push(pow(operand1, operand2));
                    break;
            }
        }
    }
    
    result = stack[top];
    return result;
}

int main() {
    int result;
    char input[MAX];
    
    printf("Enter a prefix expression: ");
    scanf("%s", input);

    result = preEval(input);
    printf("Result: %d\n", result);

    return 0;
}
