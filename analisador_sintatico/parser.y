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

%token Token_AND Token_ARRAY Token_BEGIN Token_DIV Token_DO Token_ELSE Token_END Token_FUNCTION
%token Token_GOTO Token_IF Token_LABEL Token_NOT Token_OF Token_OR Token_PROCEDURE Token_PROGRAM
%token Token_THEN Token_TYPE Token_VAR Token_WHILE Token_READ Token_WRITE Token_WRITELN Token_ASSIGN Token_LE
%token Token_GE Token_NE Token_PLUS Token_MINUS Token_MULT Token_DIVIDE Token_LT Token_GT Token_EQ
%token Token_LPAREN Token_RPAREN Token_LBRACKET Token_RBRACKET Token_SEMICOLON Token_COLON Token_COMMA Token_PERIOD
%token Token_ID Token_NUMBER token_INTEGER token_WRITE token_WRITELN token_READ token_BOOL
%token Token_TESTE

%type <sval> Token_ID
%type <ival> Token_NUMBER



%%
PROGRAMA:
    Token_PROGRAM IDENTIFICADOR Token_LPAREN LISTA_DE_IDENTIFICADORES Token_RPAREN Token_SEMICOLON BLOCO Token_PERIOD { printf("Aceito\n"); }
;

IDENTIFICADOR:
    Token_ID
;

LISTA_DE_IDENTIFICADORES:
    IDENTIFICADOR Token_COMMA LISTA_DE_IDENTIFICADORES
    | IDENTIFICADOR 
;

BLOCO:
    COMANDO_COMPOSTO
;

COMANDO_COMPOSTO:
    Token_BEGIN COMANDOS Token_END
;

COMANDOS:
    COMANDO Token_SEMICOLON COMANDOS
    | COMANDO
;

COMANDO:
    Token_NUMBER Token_COLON COMANDO_SEM_ROTULO
    | COMANDO_SEM_ROTULO
;

COMANDO_SEM_ROTULO:
    ATRIBUICAO
;

ATRIBUICAO:
    VARIAVEL Token_ASSIGN EXPRESSAO
;

VARIAVEL:
    IDENTIFICADOR
;

EXPRESSAO:
    EXPRESSAO_SIMPLES RELACAO EXPRESSAO_SIMPLES
    | EXPRESSAO_SIMPLES
;

RELACAO:
    Token_EQ
    | Token_NE
    | Token_LT
    | Token_LE
    | Token_GE
    | Token_GT
;

EXPRESSAO_SIMPLES:
    Token_PLUS TERMOS
    | Token_MINUS TERMOS
    | TERMOS
;

TERMOS:
    TERMO Token_PLUS TERMOS
    | TERMO Token_MINUS TERMOS
    | TERMO Token_OR TERMOS
    | TERMO
;

TERMO:
    FATOR Token_MULT TERMO
    | FATOR Token_DIV TERMO
    | FATOR Token_AND TERMO
    | FATOR
;

FATOR:
    VARIAVEL
    | Token_NUMBER
    | Token_LPAREN EXPRESSAO Token_RPAREN
    | Token_NOT FATOR

%%
void yyerror(const char *s) {
    fprintf(stderr, "Rejeito\n");
}

int main(int argc, char **argv) {
    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (!file) {
            
            return 1;
        }
        yyin = file;
    }
    yyparse();
    return 0;
}
