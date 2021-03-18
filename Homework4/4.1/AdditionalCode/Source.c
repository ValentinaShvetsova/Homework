#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

const int size = sizeof(int) * 8;

void convertToAdditional(int number, bool binaryNumber[]) {
	for (int i = size - 1; i >= 0; --i) {
		binaryNumber[i] = number & 1;
		number >>= 1;
	}
}

void sumOfBinary(bool firstBinaryNumber[], bool secondBinaryNumber[], bool binarySum[]) {
	int carryover = 0;
	for (int i = size - 1; i >= 0; --i) {
		binarySum[i] = firstBinaryNumber[i] ^ secondBinaryNumber[i] ^ carryover;
		carryover = (firstBinaryNumber[i] & secondBinaryNumber[i]) || (firstBinaryNumber[i] & carryover) || (secondBinaryNumber[i] & carryover);
	}
}

int convertToDecimal(bool sum[]) {
	int decimal = 0;
	int powerOfTwo = 1;
	for (int i = size - 1; i >= 0; --i) {
		decimal |= (sum[i] * powerOfTwo);
		powerOfTwo <<= 1;
	}
	return decimal;
}

bool checkBinaryNumber(bool binaryNumber[], bool answer[]) {
	for (int i = 0; i < size; i++) {
		if (binaryNumber[i] != answer[i]) {
			return false;
		}
	}
	return true;
}

bool testConvertToBinary() {
	int number = 15;
	bool binaryNumber[32] = { 0 };
	convertToAdditional(number, binaryNumber);
	bool answer[32] = { 0 };
	answer[28] = 1;
	answer[29] = 1;
	answer[30] = 1;
	answer[31] = 1;
	return checkBinaryNumber(binaryNumber, answer);
}

bool chekSum() {
	int number1 = 10;
	int number2 = 15;
	int number3 = -7;
	int number4 = -10;
	
	bool firstNumber[32] = { 0 };
	bool secondNumber[32] = { 0 };
	bool thirdNumber[32] = { 0 };
	bool fourthNumber[32] = { 0 };

	convertToAdditional(number1, firstNumber);
	convertToAdditional(number2, secondNumber);
	convertToAdditional(number3, thirdNumber);
	convertToAdditional(number4, fourthNumber);

	bool sum1[32] = { 0 };
	bool sum2[32] = { 0 };
	bool sum3[32] = { 0 };
	bool sum4[32] = { 0 };

	sumOfBinary(firstNumber, secondNumber, sum1);
	sumOfBinary(firstNumber, thirdNumber, sum2);
	sumOfBinary(thirdNumber, fourthNumber, sum3);
	sumOfBinary(firstNumber, fourthNumber, sum4);

	int result1 = convertToDecimal(sum1);
	int result2 = convertToDecimal(sum2);
	int result3 = convertToDecimal(sum3);
	int result4 = convertToDecimal(sum4);

	return ((result1 == 25) & (result2 == 3) & (result3 == -17) & (result4 == 0));
}

int main() {
	setlocale(LC_ALL, "");
	if (!testConvertToBinary() || !chekSum()) {
		printf("Тесты не пройдены.\n");
		return 1;
	}
	
	printf("Введите первое целое число: ");
	int firstNumber = 0;
	scanf("%d", &firstNumber);
	bool firstBinaryNumber[32] = {0};
	
	convertToAdditional(firstNumber, firstBinaryNumber);
	printf("Двоичное представление первого числа в дополнительном коде: \n");
	for (int i = 0; i < 32; ++i) {
		printf("%d", firstBinaryNumber[i]);
	}

	printf("\nВведите второе целое число: ");
	int secondNumber = 0;
	scanf("%d", &secondNumber);
	bool secondBinaryNumber[32] = {0};
	
	convertToAdditional(secondNumber, secondBinaryNumber);
	printf("Двоичное представление второго числа в дополнительном коде: \n");
	for (int i = 0; i < 32; ++i) {
		printf("%d", secondBinaryNumber[i]);
	}

	bool binarySum[32] = {0};
	
	sumOfBinary(firstBinaryNumber, secondBinaryNumber, binarySum);
	int result = convertToDecimal(binarySum);

	printf("\nРезультат: %d ", result);
}