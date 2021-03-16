#include <string.h>
#include <ctype.h>
#include "lexer.h"
#include <stdbool.h>

enum Condition {
	start,
	digitPointOrE,
	digit,
	digitEOrEnd,
	digitOrSign,
	digitAfterSign,
	digitWithoutChoice,
};

bool lexer(char* string) {
	const int length = strlen(string);
	enum Condution state = 0;
	for (int i = 0; i < length + 1; ++i) {
		switch (state) {
		case start:
			if (isdigit(string[i])) {
				state = digitPointOrE;
				break;
			}
			return false;
		case digitPointOrE:
			if (isdigit(string[i])) {
				state = digitPointOrE;
				break;
			}
			if (string[i] == '.')
			{
				state = digit;
				break;
			}
			if (string[i] == 'E')
			{
				state = digitOrSign;
				break;
			}
			return string[i] == '\0';
		case digit:
			if (isdigit(string[i]))
			{
				state = digitEOrEnd;
				break;
			}
			return false;
		case digitEOrEnd:
			if (isdigit(string[i]))
			{
				state = digitEOrEnd;
				break;
			}
			if (string[i] == 'E')
			{
				state = digitOrSign;
				break;
			}
			return string[i] == '\0';
		case digitOrSign:
			if (isdigit(string[i]))
			{
				state = digitWithoutChoice;
				break;
			}
			if (string[i] == '+' || string[i] == '-')
			{
				state = digitAfterSign;
				break;
			}
			return false;
		case digitAfterSign:
			if (isdigit(string[i]))
			{
				state = digitWithoutChoice;
				break;
			}
			return false;
		case digitWithoutChoice:
			if (isdigit(string[i]))
			{
				state = digitWithoutChoice;
				break;
			}
			return string[i] == '\0';
		}
	}
}