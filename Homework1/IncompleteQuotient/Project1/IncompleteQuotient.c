#include <stdio.h>
#include <stdlib.h>

int incompleteQuotient(int x, int y) {
	int res = 0;
	x = abs(x);
	y = abs(y);
	while (x >= y) {
		x -= y;
		res += 1;
	}
	return res;
}

int main()
{
	int divident = 0;
	int divider = 0;

	printf("Enter the divident:\n");
	scanf("%d", &divident);
	printf("Enter the divider:\n");
	scanf("%d", &divider);

	if (divider == 0) {
		printf("Divider can not be zero!");
		return 0;
	}

	int result = incompleteQuotient(divident, divider);
	if ((divident) <= 0 && (divider) > 0) {
		result = (-1) * result - 1;
	}
	else if ((divident) >= 0 && (divider) < 0) {
		result = -result;
	}
	else if ((divident) <= 0 && (divider) < 0) {
		result += 1;
	}
	printf("%d", result);
	return 0;
}

