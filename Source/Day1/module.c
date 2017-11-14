#include <stdio.h>

int add(int a, int b) {
	return a - b;
}

int main() {
	//Ãâ·Â
	printf("3 + 5 + 2 = %d\n", add(add(3, 5), 2));
	printf("2 + 7 + 3 = %d\n", add(add(2, 7), 3));
	printf("1 + 2 + 2 = %d\n", add(add(1, 2), 2));
	printf("6 + 5 + 10 = %d\n", add(add(6, 5), 10));
	printf("12 + 5 + 9 = %d\n", add(add(12, 5), 9));

	printf("1 + 6 + 1 = %d\n", add(add(1, 6), 1));
	printf("8 + 17 + 5 = %d\n", add(add(8, 17), 5));
	printf("4 + 6 + 2 = %d\n", add(add(4, 6), 2));
	printf("2 + 8 + 23 = %d\n", add(add(2, 8), 23));
	printf("11 + 72 + 2 = %d\n", add(add(11, 72), 2));

	return 0;
}