#include <string.h>
#include <ctype.h>
#include "lexer.h"
#include <stdbool.h>

bool lexer(char* string) {
	const int length = strlen(string);
	int state = 0;
	for (int i = 0; i < length + 1; ++i) {
		switch (state) {
		case 0:
			if (isdigit(string[i])) {
				state = 1;
				break;
			}
			return false;
		case 1:
			if (isdigit(string[i])) {
				state = 1;
				break;
			}
			if (string[i] == '.')
			{
				state = 2;
				break;
			}
			if (string[i] == 'E')
			{
				state = 4;
				break;
			}
			return string[i] == '\0';
		case 2:
			if (isdigit(string[i]))
			{
				state = 3;
				break;
			}
			return false;
		case 3:
			if (isdigit(string[i]))
			{
				state = 3;
				break;
			}
			if (string[i] == 'E')
			{
				state = 4;
				break;
			}
			return string[i] == '\0';
		case 4:
			if (isdigit(string[i]))
			{
				state = 6;
				break;
			}
			if (string[i] == '+' || string[i] == '-')
			{
				state = 5;
				break;
			}
			return false;
		case 5:
			if (isdigit(string[i]))
			{
				state = 6;
				break;
			}
			return false;
		case 6:
			if (isdigit(string[i]))
			{
				state = 6;
				break;
			}
			return string[i] == '\0';
		}
	}
}