#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

const int size = sizeof(int) * 8;

void convertToAdditional(int number, int binaryNumber[])
{
	int modNumber = abs(number);
	for (int i = size - 1; i > 0; --i) {
		binaryNumber[i] = modNumber % 2;
		modNumber /= 2;
	}
	if (number < 0) {
		for (int i = 0; i < size; ++i) {
			if (binaryNumber[i] == 0) {
				binaryNumber[i] = 1;
			}
			else {
				binaryNumber[i] = 0;
			}
		}
		int i = size - 1;
		while (binaryNumber[i] != 0) {
			binaryNumber[i] = 0;
			i--;
		}
		binaryNumber[i] = 1;
	}
}

void summOfBinary(int firstBinaryNumber[], int secondBinaryNumber[], int binarySumm[]) {
	int carryover = 0;
	for (int i = size - 1; i >= 0; --i) {
		if ((firstBinaryNumber[i] + secondBinaryNumber[i] + carryover) == 0) {
			binarySumm[i] = 0;
			carryover = 0;
		}
		else if ((firstBinaryNumber[i] + secondBinaryNumber[i] + carryover) == 1) {
			binarySumm[i] = 1;
			carryover = 0;
		}
		else if ((firstBinaryNumber[i] + secondBinaryNumber[i] + carryover) == 2) {
			binarySumm[i] = 0;
			carryover = 1;
		}
		else if ((firstBinaryNumber[i] + secondBinaryNumber[i] + carryover) == 3) {
			binarySumm[i] = 1;
			carryover = 1;
		}
	}
	if (binarySumm[0] == 1) {
		for (int i = 1; i < size; ++i) {
			if (binarySumm[i] == 1) {
				binarySumm[i] = 0;
			}
			else {
				binarySumm[i] = 1;
			}
		}
		int i = size - 1;
		while (binarySumm[i] != 0) {
			binarySumm[i] = 0;
			i--;
		}
		binarySumm[i] = 1;
	}
}

int convertToDecimal(int summ[])
{
	int decimalNumber = 0;
	int powerOfTwo = 1;
	for (int i = size - 1; i > 0; i--)
	{
		decimalNumber += powerOfTwo * summ[i];
		powerOfTwo *= 2;
	}
	if (summ[0] == 1) {
		decimalNumber = -decimalNumber;
	}
	return decimalNumber;
}

int main() {
	char* locale = setlocale(LC_ALL, "");
	
	printf("¬ведите первое целое число: ");
	int firstNumber = 0;
	scanf("%d", &firstNumber);
	int firstBinaryNumber[32];
	for (int i = 0; i < 32; ++i) {
		firstBinaryNumber[i] = 0;
	}
	convertToAdditional(firstNumber, firstBinaryNumber);

	printf("¬ведите второе целое число: ");
	int secondNumber = 0;
	scanf("%d", &secondNumber);
	int secondBinaryNumber[32];
	for (int i = 0; i < 32; ++i) {
		secondBinaryNumber[i] = 0;
	}
	convertToAdditional(secondNumber, secondBinaryNumber);

	int binarySumm[32];
	for (int i = 0; i < 32; ++i) {
		binarySumm[i] = 0;
	}
	summOfBinary(firstBinaryNumber, secondBinaryNumber, binarySumm);
	int result = convertToDecimal(binarySumm);

	printf("–езультат: %d ", result);
}