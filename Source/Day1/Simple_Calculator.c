#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 1000
char stack[SIZE];
int st[SIZE];
int tos = -1;

char postfix[SIZE];

void push(char x);
char pop();
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);
int isEmpty();
void convertToPostfix(char *str);
int compute(char *str);

int main() {
	int val = 0;
	char expression[SIZE];
	scanf("%s", &expression);
	convertToPostfix(expression);
	printf("%d\n", compute(postfix));
	return 0;
}
int compute(char *str) {
	int len = strlen(str);
	int idx = 0;
	char a, b;
	int x, y, ret, val;
	memset(stack, '\0', sizeof(stack));
	for (int i = 0; i < len; i++) {
		if (48 <= str[i] && str[i] <= 57) {
			st[idx++] = (int)str[i] - 48;
		}
		else {
			x = st[--idx];
			y = st[--idx];
			switch (str[i])
			{
			case '+':
				val = add(x, y);
				st[idx++] = val;
				break;
			case '-':
				val = subtract(x, y);
				st[idx++] = val;
				break;
			case '*':
				val = multiply(x, y);
				st[idx++] = val;
				break;
			case '/':
				val = divide(x, y);
				st[idx++] = val;
				break;
			default:
				break;
			}
		}
	}
	return st[--idx];
}
void convertToPostfix(char *str) {
	int len = strlen(str);
	int idx = 0;
	for (int i = 0; i < len; i++) {
		if (48 <= str[i] && str[i] <= 57) {
			postfix[idx++] = str[i];
		}
		else if(str[i] == '(') {
			push(str[i]);
		}
		else if (str[i] == ')') {
			int c;
			while (1) {
				if (!isEmpty()) {
					c = pop();
					if (c == '(')
						break;
					else
						postfix[idx++] = c;
				}
				else
					break;
			}
		}
		else {
			push(str[i]);
		}
	}
}

int add(int a, int b) {
	return a + b;
}

int subtract(int a, int b) {
	return a - b;
}

int multiply(int a, int b) {
	return a*b;
}

int divide(int a, int b) {
	return a / b;
}

char pop() {
	char c = stack[tos];
	stack[tos--] = '\0';
	return c;
}

void push(char x) {
	stack[++tos] = x;
}

int isEmpty() {
	if (tos == -1)
		return 1;
	else
		return 0;
}