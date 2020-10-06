#include <stdio.h>

int main()
{
	int array[28];
	
	for (int i = 0; i <= 27; i++) {
		array[i] = 0;
	}
	for (int i = 0; i <= 999; i++) {
		int sum; 
		if (i < 10) {
			sum = i;
		}
		else if (i < 100) {
			sum = (i % 10) + (i / 10);
		}
		else {
			sum = (i % 10) + (i / 10) % 10 + (i / 100);
		}
		array[sum] += 1;
	}
	int amount = 0;
	for (int i = 0; i <= 27; i++) {
		amount += array[i] * array[i];
	}
	printf("Amount of lucky tickets: %d\n", amount);
	return 0;
}