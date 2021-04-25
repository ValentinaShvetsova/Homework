#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "HashTable.h"
#include "List.h"

bool tests() {
	FILE* file = fopen("Test.txt", "r");
	if (!file) {
		printf("File not found");
		return false;
	}

	struct HashTable* table = createHashTable();
	while (!feof(file)) {
		char word[50] = { 0 };
		fscanf(file, "%s", &word);
		addValueToTable(table, word);
	}
	fclose(file);
	if (maximumListLength(table) != 2) {
		deleteTable(table);
		return false;
	}
	char value[] = "horse";
	if (!tableContainsValue(table, value)) {
		return false;
	}
	float realloadFactor = 0.128571436;
	float tableLoadFactor = loadFactor(table);
	if (realloadFactor != tableLoadFactor) {
		return false;
	}
	deleteTable(table);
	return true;
}

int main() {
	if (!tests()) {
		return 1;
	}
	FILE* file = fopen("input.txt", "r");
	if (!file) {
		printf("File not found");
		return 1;
	}

	struct HashTable* table = createHashTable();
	while (!feof(file)) {
		char word[50] = { 0 };
		fscanf(file, "%s", &word);
		addValueToTable(table, word);
	}
	fclose(file);

	printf("Words:\n");
	printTable(table);

	printf("\nLoad factor: %f", loadFactor(table));
	printf("\nMaximum list length: %d", maximumListLength(table));
	printf("\nAverage list length: %f\n", averageListLength(table));

	deleteTable(table);
	return 0;
}