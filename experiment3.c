#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isKeyword(char buffer[]) {
    char keywords[5][10] = {"int", "float", "if", "else", "return"};
    for (int i = 0; i < 5; ++i) {
        if (strcmp(keywords[i], buffer) == 0)
            return 1;
    }
    return 0;
}

int main() {
    char ch, buffer[15], operators[] = "+-*/=";
    char str[] = "int a = b + 10;";
    int i = 0, j = 0;

    printf("Input: %s\n\nTokens:\n", str);

    while ((ch = str[i++]) != '\0') {
        // Check operators
        for (int k = 0; k < 5; ++k) {
            if (ch == operators[k])
                printf("%c : Operator\n", ch);
        }

        // Check alphanumeric identifiers/keywords
        if (isalnum(ch)) {
            buffer[j++] = ch;
        } else if ((ch == ' ' || ch == ';' || ch == '\n') && (j != 0)) {
            buffer[j] = '\0';
            j = 0;

            if (isKeyword(buffer))
                printf("%s : Keyword\n", buffer);
            else if (isdigit(buffer[0]))
                printf("%s : Constant\n", buffer);
            else
                printf("%s : Identifier\n", buffer);
        }

        // Check delimiter
        if (ch == ';')
            printf("; : Delimiter\n");
    }

    return 0;
}
