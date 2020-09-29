#include <stdio.h>
#include <string.h>

int main()
{
    char str[10000];
    printf("Enter a string of brackets: ");
    scanf("%s", &str);

    int opened = 0;

    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '(')
        {
            opened++;
        }
        else 
        {
            if (opened == 0) {
                printf("Brackets are not balanced.");
                return 0;
            }
            else {
                opened--;
            }
            
        }
    }
    if (opened == 0) {
        printf("Brackets are balanced.");
    } else {
        printf("Brackets are not balanced.");
    }
    return 0;
}