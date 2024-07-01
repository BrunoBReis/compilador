%{
#include <stdio.h>
#include <string.h>


int keyword_count = 0;
int identifier_count = 0;
int number_count = 0;
int operator_count = 0;
int compound_operator_count = 0;
int delimiter_count = 0;
int comments_count = 0;
int unknown_count = 0;



%}

%option noyywrap

IDENTIFIER          [a-zA-Z][a-zA-Z0-9]*
NUMBER              [0-9]+(\.[0-9]+)?
KEYWORD             "and"|"array"|"begin"|"div"|"do"|"else"|"end"|"function"|"goto"|"if"|"label"|"not"|"of"|"or"|"procedure"|"program"|"then"|"type"|"var"|"while"|"read"|"write"
COMPOUND_OPERATOR   ":="|"<="|">="|"<>"
OPERATOR            "+"|"-"|"*"|"/"|"<"|">"|"="
DELIMITER           "("|")"|"["|"]"|";"|":"|","|"."
COMMENT             \(\*([^*]|\*+[^)])*\*+\)

%%

{KEYWORD} { keyword_count++; }
{COMPOUND_OPERATOR} { compound_operator_count++; }
{OPERATOR} { operator_count++; }
{IDENTIFIER} { identifier_count++; }
{NUMBER} { number_count++; }
{COMMENT} { comments_count++; }
{DELIMITER} { delimiter_count++; }
[ \t\n]  { /* Ignorar espa�os em branco */ }
. { unknown_count++; }

%%


int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <inputfile>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror(argv[1]);
        return 1;
    }

    yyin = file;
    yylex();
    fclose(file);

    printf("KEYWORD: %d\n", keyword_count);
    printf("IDENTIFIER: %d\n", identifier_count);
    printf("NUMBER: %d\n", number_count);
    printf("OPERATOR: %d\n", operator_count);
    printf("COMPOUND OPERATOR: %d\n", compound_operator_count);
    printf("DELIMITER: %d\n", delimiter_count);
    printf("COMMENTS: %d\n", comments_count);
    printf("UNKNOWN: %d\n", unknown_count);

    return 0;
}
