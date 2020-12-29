#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>
#include <malloc.h>

struct Record {
	char name[30];
	char phone[30];
};

struct Record* readFromFile(char* fileName, int* recordsCount) {
	FILE* file = fopen("database.txt", "r");
	struct Record* buffer = calloc(100, sizeof(struct Record));

	while (!feof(file)) {
		fscanf(file, "%s %s", &buffer[*recordsCount].name, &buffer[*recordsCount].phone);
		(*recordsCount)++;
	}
	fclose(file);
	return buffer;
}

void addRecord(struct Record records[], int *amountOfRecords) {
	if (*amountOfRecords < 100) {
		printf("������� ���: ");
		scanf("%s", &records[*amountOfRecords].name);
		printf("������� ����� ��������: ");
		scanf("%s", &records[*amountOfRecords].phone);
		(*amountOfRecords)++;
	}
	else {
		printf("���� ���������\n");
	}
}

void printRecords(struct Record records[], const int amountOfRecords) {
	for (int i = 0; i < amountOfRecords; ++i) {
		printf("%s %s\n", records[i].name, records[i].phone);
	}
}

const char* findNumber(struct Record records[], int amountOfRecords, const char name[]) {
	const char *exit = "Number not found";
	for (int i = 0; i < amountOfRecords; ++i) {
		if (strcmp(records[i].name, name) == 0) {
			return records[i].phone;
		}
	}
	return exit;
}

const char* findName(struct Record records[], const int amountOfRecords, const char number[]) {
	const char *exit = "Name not found";
	for (int i = 0; i < amountOfRecords; ++i) {
		if (strcmp(records[i].phone, number) == 0) {
			return records[i].name;
		}
	}
	return exit;
}

void addToFile(struct Record records[], const int amountOfRecords, const char name[]) {
	FILE* file = fopen(name, "w");
	if (file == NULL) {
		printf("���� �� ������� �������.\n");
		return;
	}
	for (int i = 0; i < amountOfRecords; ++i) {
		fprintf(file, "%s %s\n", records[i].name, records[i].phone);
	}
	fclose(file);
}

bool testFindingName() {
	int recordsCount = 0;
	struct Record* records = readFromFile("database.txt", &recordsCount);
	char number[] = "34567";
	return strcmp(findName(records, recordsCount, number), "Helga") == 0;
}

bool testFindingNumber() {
	int recordsCount = 0;
	struct Record* records = readFromFile("database.txt", &recordsCount);
	const char name[5] = "Oleg";
	return strcmp(findNumber(records, recordsCount, name), "345678") == 0;
}

int main() {
	if (!testFindingNumber() || !testFindingName()) {
		return 1;
	}
	setlocale(LC_ALL, "");
	
	int recordsCount = 0;
	struct Record* records = readFromFile("database.txt", &recordsCount);

	printf("\n�������� �������:\n 0 - �����\n");
	printf(" 1 - �������� ��� � �������\n");
	printf(" 2 - ����������� ��� ��������� ������\n");
	printf(" 3 - ����� ����� �������� �� �����\n");
	printf(" 4 - ����� ��� �� ������ ��������\n");
	printf(" 5 - ��������� ������� ������\n");

	bool shouldGoOut = false;
	while (!shouldGoOut) {
		int command = 0;
		scanf("%d", &command);
		if (command > 5 || command < 0) {
			printf("����� ������� ���.");
		}
		if (command == 0) {
			shouldGoOut = true;
		}
		else if (command == 1) {
			addRecord(records, &recordsCount);
		}
		else if (command == 2) {
			printRecords(records, recordsCount);
		}
		else if (command == 3) {
			char name[30];
			printf("������� ���: \n");
			scanf("%s", &name);
			printf("%s", findNumber(records, recordsCount, name));
			recordsCount++;
		}
		else if (command == 4) {
			char number[30];
			printf("������� �����: \n");
			scanf("%s", &number);
			printf("%s", findName(records, recordsCount, number));
		}
		else if (command == 5) {
			addToFile(records, recordsCount, "database.txt");
		}
	}
	free(records);
	return 0;
}