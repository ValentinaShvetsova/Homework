#include <stdio.h>

int recursiveFibonacci(int n) {
	if (n <= 0) {
		return -1;
	}else if (n <= 2) {
		return 1;
	}

	return recursiveFibonacci(n - 1) + recursiveFibonacci(n - 2);
}

int test() {
	if (recursiveFibonacci(0) == -1 && recursiveFibonacci(1) == 1 && recursiveFibonacci(5) == 5 &&
		recursiveFibonacci(-5) == -1 && recursiveFibonacci(7) == 13) {
		return 1;
	}
	else {
		return 0;
	}
}


int main() {
	
	if (!test()) {
		printf("Test failed\n");
		return 1;
	}
	return 0;

	int n = 0;
	printf("Enter the number: ");
	scanf("%i", &n);
	
	for (int i = 1; i <= n; ++i) {
		printf("%i ", recursiveFibonacci(i));
	}
	return 0;
}