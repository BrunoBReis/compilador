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
%token Token_ID Token_NUMBER

%type <sval> Token_ID
%type <ival> Token_NUMBER



%%
programa: Token_PROGRAM Token_ID Token_LPAREN OU_ID Token_RPAREN Token_SEMICOLON BLOCO Token_PERIOD{ printf("Aceito\n"); }
        ;


TIPO: Token_ID
    ;

BLOCO: PARTE_DECLARACAO_SUBROTINAS
     | PARTE_DECLARACAO_VARIAVEIS
     | COMANDO_COMPOSTO
     |
     ;

PARTE_DECLARACAO_SUBROTINAS: DECLARACAO_PROCEDIMENTO
                           |
                           ;
DECLARACAO_PROCEDIMENTO: Token_PROCEDURE Token_ID Token_SEMICOLON BLOCO
                        ;


PARTE_DECLARACAO_VARIAVEIS: Token_VAR OU_DECLARACAO_VARIAVEIS Token_SEMICOLON
    ;

OU_DECLARACAO_VARIAVEIS: OU_DECLARACAO_VARIAVEIS Token_SEMICOLON DECLARACAO_VARIAVEIS
                       | DECLARACAO_VARIAVEIS
                       ;
DECLARACAO_VARIAVEIS: OU_ID Token_COLON TIPO
        ;
        
OU_ID: OU_ID Token_COMMA Token_ID
     | Token_ID
     ;

COMANDO_COMPOSTO: Token_BEGIN OU_COMANDO Token_END
                | Token_BEGIN OU_COMANDO Token_END Token_SEMICOLON BLOCO
                ;

OU_COMANDO: OU_COMANDO Token_SEMICOLON COMANDO
          | COMANDO
          ;

COMANDO: COMANDO_SEM_ROTULO
    ;
COMANDO_SEM_ROTULO: ATRIBUICAO
                  | CHAMADA_PROCEDIMENTO
                  | COMANDO_COMPOSTO
                  | COMANDO_CONDICIONAL
                  | COMANDO_REPETITIVO
                  ;
COMANDO_REPETITIVO: Token_WHILE EXPRESSAO Token_DO COMANDO_SEM_ROTULO
                ;

COMANDO_CONDICIONAL: Token_IF EXPRESSAO Token_THEN COMANDO_SEM_ROTULO Token_ELSE COMANDO_SEM_ROTULO
                   | Token_IF EXPRESSAO Token_THEN COMANDO_SEM_ROTULO
                   ;

ATRIBUICAO: Token_ID Token_ASSIGN EXPRESSAO
          ;

CHAMADA_PROCEDIMENTO: Token_ID Token_LPAREN OU_EXPRESSOES Token_RPAREN
                    | Token_ID
                    ;

OU_EXPRESSOES: OU_EXPRESSOES Token_COMMA EXPRESSAO
             | EXPRESSAO
             ;

EXPRESSAO: EXPRESSAO_SIMPLES RELACAO EXPRESSAO_SIMPLES
         | EXPRESSAO_SIMPLES
         ;

RELACAO: Token_EQ
       | Token_NE
       | Token_LT
       | Token_LE
       | Token_GE
       | Token_GT
       ;
       
EXPRESSAO_SIMPLES: TERMO Token_OR TERMO
                 | TERMO Token_MINUS TERMO
                 | TERMO Token_PLUS TERMO
                 | TERMO
                 ;

TERMO: FATOR Token_AND FATOR
     | FATOR Token_DIV FATOR
     | FATOR Token_MULT FATOR
     | FATOR
     ;

FATOR: Token_ID
     | Token_NUMBER
     | Token_LPAREN EXPRESSAO Token_RPAREN
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
