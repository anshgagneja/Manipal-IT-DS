#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define STACK_SIZE 100

struct Stack {
    int top;
    char items[STACK_SIZE][STACK_SIZE];
};

void initialize(struct Stack *s) {
    s->top = -1;
}

bool isOperator(char x) {
    switch (x) {
        case '+':
        case '-':
        case '/':
        case '*':
        case '^':
        case '%':
            return true;
    }
    return false;
}

void push(struct Stack *s, char elem[]) {
    if (s->top < STACK_SIZE) {
        strcpy(s->items[++(s->top)], elem);
    } else {
        printf("Stack Overflow!\n");
        exit(1);
    }
}

char* pop(struct Stack *s) {
    if (s->top >= 0) {
        return s->items[(s->top)--];
    } else {
        printf("Stack Underflow!\n");
        exit(1);
    }
}

char* preToInfix(char* pre_exp) {
    struct Stack s;
    initialize(&s);
    
    int length = strlen(pre_exp);

    for (int i = length - 1; i >= 0; i--) {
        if (isOperator(pre_exp[i])) {
            char* op1 = pop(&s);
            char* op2 = pop(&s);
            
            char operatorChar = pre_exp[i];
            char temp[STACK_SIZE];

            snprintf(temp, STACK_SIZE, "(%s%c%s)", op1, operatorChar, op2);

            push(&s, temp);
        } else {
            char temp[2] = { pre_exp[i], '\0' };
            push(&s, temp);
        }
    }

    char* output = pop(&s);
    char* result = (char*)malloc(strlen(output) + 1);
    strcpy(result, output);

    return result;
}

int main() {
    char pre_exp[] = "*-A/BC-/AKL";
    char* infix = preToInfix(pre_exp);

    printf("Infix: %s\n", infix);

    free(infix);

    return 0;
}
