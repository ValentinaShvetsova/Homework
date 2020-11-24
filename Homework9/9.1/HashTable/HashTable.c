#include "HashTable.h"
#include "List.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct HashTable
{
	int size;
	int amountOfElements;
	float loadFactor;
	struct List** lists;
};

void createLists(struct HashTable* table) {
	table->lists = calloc(table->size, sizeof(struct List*));
	for (int i = 0; i < table->size; ++i) {
		table->lists[i] = createList();
	}
}

struct HashTable* createHashTable() {
	struct HashTable* newHashTable = calloc(1, sizeof(struct HashTable));
	newHashTable->size = 70;
	createLists(newHashTable);
	return newHashTable;
}

int hashFunction(char* value, int size)
{
	int result = 0;
	for (int i = 0; value[i] != '\0'; ++i) {
		result = (result + value[i]) % size;
	}
	return result;
}

void addToTable(struct HashTable* table, char* value, int amount) {
	const bool elementAdded = addNewValueToList(table->lists[hashFunction(value, table->size)], value, amount);
	if (elementAdded) {
		table->amountOfElements++;
		table->loadFactor = 1.0 * table->amountOfElements / table->size;
	}
}

bool tableContainsValue(struct HashTable* table, char* value) {
	return contains(table->lists[hashFunction(value, table->size)], value);
}

void printTable(struct HashTable* table) {
	for (int i = 0; i < table->size; ++i) {
		printList(table->lists[i]);
	}
}

float loadFactor(struct HashTable* table) {
	return table->loadFactor;
}

struct List* helpList(struct HashTable* table) {
	struct List* helpList = createList();
	for (int i = 0; i < table->size; ++i) {
		while (!isEmpty(table->lists[i])) {
			char* value = returnValueFromHead(table->lists[i]);
			addNewValueToList(helpList, value, quantityOfValuesFromHead(table->lists[i]));
			deleteValueFromHead(table->lists[i], returnValueFromHead(table->lists[i]));
		}
		deleteList(table->lists[i]);
	}
	return helpList;
}

void rehashing(struct HashTable* table) {
	struct List* tempList = helpList(table);
	free(table->lists);
	table->size *= 2;
	table->amountOfElements = 0;
	createLists(table);

	while (!isEmpty(tempList)) {
		char* value = returnValueFromHead(tempList);
		addToTable(table, value, quantityOfValuesFromHead(tempList));
		deleteValueFromHead(tempList, returnValueFromHead(tempList));
	}
	deleteList(tempList);
}

void addValueToTable(struct HashTable* table, char* value) {
	addToTable(table, value, 1);

	if (table->loadFactor > 1) {
		rehashing(table);
	}
}

int maximumListLength(struct HashTable* table) {
	int maxLength = 0;
	for (int i = 0; i < table->size; ++i) {
		const int currentListLength = listLength(table->lists[i]);
		if (currentListLength > maxLength) {
			maxLength = currentListLength;
		}
	}
	return maxLength;
}

float averageListLength(struct HashTable* table)
{
	int sumOfAllLengths = 0;
	int numberOfLists = 0;
	for (int i = 0; i < table->size; ++i) {
		if (!isEmpty(table->lists[i])) {
			sumOfAllLengths += listLength(table->lists[i]);
			numberOfLists++;
		}
	}
	if (numberOfLists != 0) {
		return 1.0 * sumOfAllLengths / numberOfLists;
	}
	else {
		return 0;
	}
}

void deleteTable(struct HashTable* table) {

	for (int i = 0; i < table->size; ++i) {
		deleteList(table->lists[i]);
	}
	free(table->lists);
	free(table);
}