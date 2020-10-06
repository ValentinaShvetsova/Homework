#include <stdio.h>

int iterativeFibonacci(int number) {
	if (number <= 0) {
		return -1;
	}
	int leftNumber = 1;
	int rightNumber = 1;
	int summ = 0;
	if (number < 3) {
		rightNumber = 1;
	}
	else {
		for (int i = 3; i <= number; ++i) {
			summ = leftNumber + rightNumber;
			leftNumber = rightNumber;
			rightNumber = summ;
		}
	}
	return rightNumber;
}

int test() {
	if (iterativeFibonacci(0) == -1 && iterativeFibonacci(1) == 1 && iterativeFibonacci(5) == 5
		&& iterativeFibonacci(7) == 13 && iterativeFibonacci(-2) == -1) {
		return 1;
	}
	else {
		return 0;
	}
}

int main() {
	int testing = test();
	if (testing == 0) {
		printf("Test failed\n");
		return 0;
	}
	int number = 0;
	printf("Enter Fibonacci number: ");
	scanf("%d", &number);
	
	int result = iterativeFibonacci(number);
	printf("Result is %d", result);
	return 0;
}