#include <stdio.h> 
#include <math.h>  
#define _CRT_SECURE_NO_WARNINGS 

int isPrime(int x) {
	if (x == 2) {
		return 1;
	}
	else if (x > 2) {
		for (int i = 2; i <= sqrt(x); ++i) {
			if ((x % i) == 0) {
				return 0;
			}
		}
		return 1;
	}
	else {
		return 0;
	}
}

int main() {
	int number = 0;
	printf("Enter the number: ");
    scanf("%d", &number);
	if (number <= 0) {
		printf("Invalid number");
	}
	else {
		for (int i = 1; i <= number; ++i) {
			int result = isPrime(i);
			if (result == 1) {
				printf("%d ", i);
			}
        }
	}
	return 0;
}