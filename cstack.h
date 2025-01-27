//cstack implemenation in C using array
//cstack.h
//generative AI via google search



#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack {
    int data[MAX_SIZE];
    int top;
};

void initStack(struct Stack *s) {
    s->top = -1;
}

int isEmpty(struct Stack *s) {
    return s->top == -1;
}

int isFull(struct Stack *s) {
    return s->top == MAX_SIZE - 1;
}

void push(struct Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack overflow!\n");
        return;
    }
    s->top++;
    s->data[s->top] = value;
}

int pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow!\n");
        return -1; // Or any other appropriate error value
    }
    int value = s->data[s->top];
    s->top--;
    return value;
}

int peek(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return -1; // Or any other appropriate error value
    }
    return s->data[s->top];
}
