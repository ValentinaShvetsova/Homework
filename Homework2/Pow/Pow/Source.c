#include <stdio.h>
#include <stdbool.h>

int binaryPower(int number, int power) {
	if (power == 0) {
		return 1;
	} else if (power % 2 == 1) {
		return binaryPower(number, power - 1) * number;
	}
	else {
		int halfPower = binaryPower(number, power / 2);
		return halfPower * halfPower;
	}
}

int slowPower(int number, int power) {
	if (power == 0) {
		return 1;
	}
	else {
		return slowPower(number, power - 1) * number;
	}
}

int testBinaryPower() {
	if (binaryPower(3, 4) == 81 && binaryPower(1, 1) == 1 && binaryPower(0, 9) == 0 && 
		binaryPower(9, 0) == 1) {
		return 1;
	} 
	return 0;
}

int testSlowPower() {
	if (slowPower(3, 4) == 81 && slowPower(1, 1) == 1 && slowPower(0, 9) == 0 &&
		slowPower(9, 0) == 1) {
		return 1;
	}
	return 0;
}

bool test() {
	if (!testBinaryPower() || !testSlowPower()) {
		return false;
	}
	return true;
}

int main() {
	if (!test()) {
		return 1;
	}
	return 0;

	int number = 0;
	int power = 0;
	
	printf("Enter the number: ");
	scanf("%d", &number);
	printf("Enter the natural power: ");
	scanf("%d", &power);

	if (power < 0) {
		printf("Power is not natural");
		return 0;
	}

	int result1 = binaryPower(number, power);
	printf("Result is %d\n", result1);
	int result2 = slowPower(number, power);
	printf("Result is %d", result2);

	return 0;
}