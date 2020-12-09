#pragma once
#include <stdbool.h>

struct HashTable;

// This function creates table
struct HashTable* createHashTable();

// This function adds value to the table
void addValueToTable(struct HashTable* table, char* value);

// This function checks if value in the table or not
bool tableContainsValue(struct HashTable* table, char* value);

// This function prints table
void printTable(struct HashTable* table);

// This function gets maximum list length
int maximumListLength(struct HashTable* table);

// This function counts average list length
float averageListLength(struct HashTable* table);

// This function gets load factor of table
float loadFactor(struct HashTable* table);

// This function deletes tree
void deleteTable(struct HashTable* table);