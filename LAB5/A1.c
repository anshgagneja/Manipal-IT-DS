//Write a program to implement queue data structure using stack.
#include <stdio.h>
#include <stdlib.h>

#define MAX 50

int top1 = -1;
int top2 = -1;
int stack1[MAX];
int stack2[MAX];

void push1(int x) {
    if (top1 == MAX - 1) {
        printf("Queue overflow!\n");
        return;
    }
    stack1[++top1] = x;
}

void push2(int x) {
    if (top2 == MAX - 1) {
        printf("Queue overflow!\n");
        return;
    }
    stack2[++top2] = x;
}

int pop1() {
    if (top1 == -1) {
        printf("Queue underflow!\n");
        return 0;
    }
    return stack1[top1--];
}

int pop2() {
    if (top2 == -1) {
        printf("Queue underflow!\n");
        return 0;
    }
    return stack2[top2--];
}

int isEmpty1() {
    return top1 == -1;
}

int isEmpty2() {
    return top2 == -1;
}

void enqueue(int x) {
    push1(x);
}

void dequeue() {
    while (!isEmpty1()) {
        push2(pop1());
    }
    printf("\nDequeued element is: %d\n", pop2());
    while (!isEmpty2()) {
        push1(pop2());
    }
}

void display() {
    if (isEmpty1()) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = 0; i <= top1; i++) {
        printf("%d\t", stack1[i]);
    }
    printf("\n");
}

int main() {
    int choice, element;

    while (1) {
        printf("\nQueue using Stacks Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &element);
                enqueue(element);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting the program!!!!\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }
    return 0;
}
