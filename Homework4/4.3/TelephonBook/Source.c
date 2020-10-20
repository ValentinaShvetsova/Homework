#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>

struct Record {
	char name[30];
	char phone[30];
};

void addRecord(struct Record records[], int amountOfRecords) {
	if (amountOfRecords < 100) {
		printf("Введите имя: ");
		scanf("%s", &records[amountOfRecords].name);
		printf("Введите номер телефона: ");
		scanf("%s", &records[amountOfRecords].phone);
		(amountOfRecords)++;
	}
	else {
		printf("База заполнена\n");
	}
}

void printRecords(struct Record records[], const int amountOfRecords) {
	for (int i = 0; i < amountOfRecords; ++i) {
		printf("%s %s\n", records[i].name, records[i].phone);
	}
}

char* findNumber(struct Record records[], int amountOfRecords, const char name[]) {
	const char exit[] = "Number not found";
	for (int i = 0; i < amountOfRecords; ++i) {
		if (strcmp(records[i].name, name) == 0) {
			return records[i].phone;
		}
	}
	return exit;
}

char* findName(struct Record records[], const int amountOfRecords, const char number[]) {
	const char exit[] = "Name not found";
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
		printf("Файл не удалось открыть.\n");
		return;
	}
	for (int i = 0; i < amountOfRecords; ++i) {
		fprintf(file, "%s %s\n", records[i].name, records[i].phone);
	}
	fclose(file);
}

int main() {
	char* locale = setlocale(LC_ALL, "");
	FILE* file = fopen("database.txt", "r");
	if (file == NULL) {
		printf("Файл не удалось открыть.\n");
		return 1;
	}
	struct Record buffer[100];
	int recordsCount = 0;

	while (!feof(file)) {
		fscanf(file, "%s %s", &buffer[recordsCount].name, &buffer[recordsCount].phone);
		recordsCount++;
	}

	printf("\nВыберите команду:\n 0 - выйти\n");
	printf(" 1 - добавить имя и телефон\n");
	printf(" 2 - распечатать все имеющиеся записи\n");
	printf(" 3 - найти номер телефона по имени\n");
	printf(" 4 - найти имя по номеру телефона\n");
	printf(" 5 - сохранить текущие данные\n");

	bool shouldGoOut = false;
	while (!shouldGoOut) {
		int command = 0;
		scanf("%d", &command);
		if (command > 5 || command < 0) {
			printf("Такой команды нет.");
		}
		if (command == 0) {
			shouldGoOut = true;
			return 0;
		}
		else if (command == 1) {
			addRecord(buffer, recordsCount);
		}
		else if (command == 2) {
			printRecords(buffer, recordsCount);
		}
		else if (command == 3) {
			char name[30];
			printf("Введите имя: \n");
			scanf("%s", &name);
			printf("%s", findNumber(buffer, recordsCount, name));
			recordsCount++;
		}
		else if (command == 4) {
			char number[30];
			printf("Введите номер: \n");
			scanf("%s", &number);
			printf("%s", findName(buffer, recordsCount, number));
		}
		else if (command == 5) {
			fclose(file);
			addToFile(buffer, recordsCount, "database.txt");
		}
	}
	return 0;
}