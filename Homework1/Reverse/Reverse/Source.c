#include <stdio.h>

void reverse(int a[], int left, int right)
{
	for (int i = (left - 1); i < (right + left) / 2; i++) {
		const int temp = a[i];
		a[i] = a[right + left - i - 2];
		a[right + left - i - 2] = temp;
	}
}


int main() {
	int border = 3;
	int size = 10;
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	
	reverse(array, 1, border);
	reverse(array, border + 1, size);
	reverse(array, 1, size);
	
	for (int i = 0; i < size; ++i) {
		printf("%d ", array[i]);
	}
	return 0;
}