// 202310302 �迵��

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 200

typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

// ���� �ʱ�ȭ �Լ�
void init_stack(StackType* s) {
	s->top = -1;
}

// ���� ���� ���� �Լ�
int is_empty(StackType* s) {
	return (s->top == -1);
}
// ��ȭ ���� ���� �Լ�
int is_full(StackType* s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}

// ���� �Լ�
void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "���� overflow\n");
		return;
	}
	else s->data[++(s->top)] = item;
}
// ���� �Լ�
element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "���� underflow\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

int main(void) {
	int infinity = 987654321;
	int problem_num = 0;
	scanf("%d", &problem_num);
	for (int problem = 0; problem < problem_num; problem++) {
		int query_num = 0;
		scanf("%d", &query_num);

		StackType min_stack;
		StackType max_stack;
		init_stack(&min_stack);
		init_stack(&max_stack);
		push(&min_stack, infinity);
		push(&max_stack, -infinity);

		for (int query = 0; query < query_num; query++) {
			int input1, input2, new_block = 0;
			scanf("%d", &input1);
			switch (input1) {
			case 1:
				scanf("%d", input2);
				new_block = input2;
				// �ּҰ� ������ �� ���� ���� ���ؼ�,
				// �� ��ϰ�, ������ �� �� �� ���� ���� ����
				if (min_stack.data[min_stack.top] > new_block)
					push(&min_stack, new_block);
				else
					push(&min_stack, min_stack.data[min_stack.top]);
				// �ִ밪 ������ �� ���� ���� ���ؼ�, �� ��ϰ� ������ �� �� �� ū ���� ����
				if (max_stack.data[max_stack.top] < new_block)
					push(&max_stack, new_block);
				else
					push(&max_stack, max_stack.data[max_stack.top]);
				printf("%d %d\n", min_stack.data[min_stack.top], max_stack.data[max_stack.top]);
				break;
			case 2:
				// �ּҰ� ����, �ִ밪 ������ �� ���� ���� ����
				if (min_stack.top != infinity)
					pop(&min_stack);
				if (max_stack.top != -infinity)
					pop(&max_stack);
				break;
			}
		}
	}
}