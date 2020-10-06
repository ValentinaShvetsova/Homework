#include <stdio.h> 
#include <string.h> 

int main(void)
{
	int subcount = 0;   
	int letterCounter = 0;

	char string[1000];
	char substring[1000];

	printf("Enter the string: ");
	scanf("%s", string);
	printf("Enter the substring: ");
	scanf("%s", substring);

	const int stringLength = strlen(string);
	const int substringLength = strlen(substring);

	for (int i = 0; i <= (stringLength - substringLength); ++i)
	{
		int j = 0;
		if (string[i] == substring[0])
		{
			j = i;
			while (1)
			{
				++letterCounter;
				if (string[j + 1] == substring[letterCounter])
				{
					++j;

					if (letterCounter == substringLength - 1)
					{
						++subcount;
						break;
					}
				}
				else
				{
					break;
				}

			}
		}
		j = 0;
		letterCounter = 0;
	}
	printf("Result is %d", subcount);
}