#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define STACK_SIZE 100

typedef int element; // 스택 원소(element)의 자료형을 int형로 정의

element stack[STACK_SIZE];
int top = -1;

int isEmpty() {
	if (top == -1) return 1;
	else return 0;
}

int isFull() {
	if (top == STACK_SIZE - 1) return 1;
	else return 0;
}

void push(element item) {
	if (isFull()) {
		printf("\n\n Stack is Full!! \n");
		return;
	}
	else {
		top += 1;
		stack[top] = item; //stack[++top]도 가능
	}
}

element pop() {
	if (isEmpty()) {
		printf("\n\n Stack is Empty!! \n");
		return;
	}
	else return stack[top--];
}

element peek() {
	if (isEmpty()) {
		printf("\n\n Stack is Empty!! \n");
		exit(1);
	}
	else return stack[top];
}

void printStack() {
	printf("\n STACK [ ");
	for (int i = 0; i <= top; i++) 
		printf("%d ", stack[i]);
	printf("]");
}

void main() {
	element item;
	printf("\n** 순차 스택 연산 **\n");
	printStack();
	push(1); printStack();
	push(2); printStack();
	push(3); printStack();

	item = peek(); printStack();
	printf("peek => %d", item);

	item = pop(); printStack();
	printf("\t pop => %d", item);

	item = pop(); printStack();
	printf("\t pop => %d", item);

	item = pop(); printStack();
	printf("\t pop => %d", item);

	getchar();
}
