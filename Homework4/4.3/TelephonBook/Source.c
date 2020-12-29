#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>

struct Record {
	char name[30];
	char phone[30];
};

struct Record* readFromFile(char* fileName, int* recordsCount) {
	FILE* file = fopen("database.txt", "r");
	struct Record buffer[100];

	while (!feof(file)) {
		fscanf(file, "%s %s", &buffer[*recordsCount].name, &buffer[*recordsCount].phone);
		(*recordsCount)++;
	}
	fclose(file);
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
	return strcmp(findName(records, recordsCount, number), "Helga");
}

bool testFindingNumber() {
	int recordsCount = 0;
	struct Record* records = readFromFile("database.txt", &recordsCount);
	const char name[5] = "Oleg";
	return strcmp(findNumber(records, recordsCount, name), "345678");
}

bool writingDownTest() {
	int recordsCount = 0;
	struct Recors* records = readFromFile("database.txt", &recordsCount);
	const char name[5] = "Oleg";
	const char number[6] = "345678";
	return strcmp(findName(records, recordsCount, name), name);
}

int main() {
	if (!testFindingNumber() || !testFindingName() || !writingDownTest()) {
		return 1;
	}
	setlocale(LC_ALL, "");
	
	int recordsCount = 0;
	struct Record* records = readFromFile("database.txt", &recordsCounting);

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
			addRecord(buffer, &recordsCount);
		}
		else if (command == 2) {
			printRecords(buffer, recordsCount);
		}
		else if (command == 3) {
			char name[30];
			printf("������� ���: \n");
			scanf("%s", &name);
			printf("%s", findNumber(buffer, recordsCount, name));
			recordsCount++;
		}
		else if (command == 4) {
			char number[30];
			printf("������� �����: \n");
			scanf("%s", &number);
			printf("%s", findName(buffer, recordsCount, number));
		}
		else if (command == 5) {
			addToFile(buffer, recordsCount, "database.txt");
		}
	}
	return 0;
}