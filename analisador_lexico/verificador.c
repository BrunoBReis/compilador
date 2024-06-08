#include <stdio.h>
#include <stdlib.h>

const char *palavras_reservadas[19] = {
    "program", "label", "type", "array", "of", "var",
    "procedure", "function", "begin", "end", "if", "then",
    "else", "while", "do", "or", "and", "div", "not"
};

int main(void)
{
    // alocando o tamnho do arquivo
    int tamanho = 22;
    char *palavras = (char *)malloc(sizeof(char) * tamanho);

    // se tiver problema no null
    if (palavras == NULL) 
    {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // coleta dos dados formatada
    char format[20];
    snprintf(format, sizeof(format), "%%%ds", tamanho - 1);

    scanf(format, palavras);

    int i = 0;
    while (palavras[i] != '\0')
    {
        if (palavras[i] == ' ')
        {
            printf(" ");
            i++;
            continue;
        }
        else
        {
            printf("%c", palavras[i]);
            i++;
        }
    }

    free(palavras);

    return 0;
}
