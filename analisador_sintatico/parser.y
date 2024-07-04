%{
#include <stdio.h>
#include <stdlib.h>

extern int yylex();
extern int yyparse();
extern FILE *yyin;

void yyerror(const char *s);
%}

%union {
    int ival;
    char *sval;
}

%token Token_AND Token_ARRAY Token_BEGIN Token_DIV Token_DO Token_ELSE Token_END Token_FUNCTION Token_GOTO Token_IF Token_LABEL Token_NOT Token_OF Token_OR Token_PROCEDURE Token_PROGRAM Token_THEN Token_TYPE Token_VAR Token_WHILE Token_READ Token_WRITE Token_ID Token_NUMBER
%token Token_ASSIGN Token_LE Token_GE Token_NE Token_PLUS Token_MINUS Token_MULT Token_DIVIDE Token_LT Token_GT Token_EQ Token_LPAREN Token_RPAREN Token_LBRACKET Token_RBRACKET Token_SEMICOLON Token_COLON Token_COMMA Token_PERIOD



%type <ival> expression
/*Token_PROGRAM Token_ID Token_LPAREN8*/
%%
programa: Token_PROGRAM Token_ID Token_LPAREN LISTA_ID Token_RPAREN Token_SEMICOLON BLOCO Token_PERIOD {printf("Aceito\n");}

BLOCO: DECLARACAO_ROTULOS
     | 

DECLARACAO_ROTULOS: Token_LABEL LISTA_NUMEROS Token_SEMICOLON

LISTA_NUMEROS: LISTA_NUMEROS Token_COMMA Token_NUMBER
           | Token_NUMBER
           ;

LISTA_ID: LISTA_ID Token_COMMA Token_ID
       | Token_ID
       ;
%%
void yyerror(const char *s) {
    fprintf(stderr, "Rejeito\n");
}

int main(int argc, char **argv) {
    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (!file) {
            fprintf(stderr, "Não foi possível abrir o arquivo %s\n", argv[1]);
            return 1;
        }
        yyin = file;
    }
    yyparse();
    return 0;
}
