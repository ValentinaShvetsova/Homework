#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

const int size = sizeof(int) * 8;

void convertToAdditional(int number, bool binaryNumber[])
{
	for (int i = size - 1; i >= 0; --i) {
		binaryNumber[i] = number & 1;
		number >>= 1;
    }
	
}

void summOfBinary(bool firstBinaryNumber[], bool secondBinaryNumber[], bool binarySumm[]) {
	int carryover = 0;
	for (int i = size - 1; i >= 0; --i) {
		binarySumm[i] = firstBinaryNumber[i] ^ secondBinaryNumber[i] ^ carryover;
		carryover = (firstBinaryNumber[i] & secondBinaryNumber[i]) || (firstBinaryNumber[i] & carryover) || (secondBinaryNumber[i] & carryover);
	}
}

int convertToDecimal(bool summ[])
{
	int decimal = 0;
	int powerOfTwo = 1;
	for (int i = size - 1; i >= 0; --i) {
		decimal |= (summ[i] * powerOfTwo);
		powerOfTwo <<= 1;
	}
	return decimal;
}

int main() {
	char* locale = setlocale(LC_ALL, "");
	
	printf("¬ведите первое целое число: ");
	int firstNumber = 0;
	scanf("%d", &firstNumber);
	bool firstBinaryNumber[32] = {0};
	
	convertToAdditional(firstNumber, firstBinaryNumber);

	printf("¬ведите второе целое число: ");
	int secondNumber = 0;
	scanf("%d", &secondNumber);
	bool secondBinaryNumber[32] = {0};
	
	convertToAdditional(secondNumber, secondBinaryNumber);

	bool binarySumm[32] = {0};
	
	summOfBinary(firstBinaryNumber, secondBinaryNumber, binarySumm);
	int result = convertToDecimal(binarySumm);

	printf("–езультат: %d ", result);
}