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
programa: Token_PROGRAM Token_ID Token_LPAREN OU_ID Token_RPAREN Token_SEMICOLON BLOCO Token_PERIOD {printf("Aceito\n");}

BLOCO: PARTE_DECLARACAO_ROTULOS
     | PARTE_DECLARACAO_VARIAVEIS

PARTE_DECLARACAO_ROTULOS: Token_LABEL OU_NUMEROS Token_SEMICOLON

PARTE_DECLARACAO_VARIAVEIS:Token_VAR OU_DECLARACAO_VARIAIVEIS 

OU_DECLARACAO_VARIAIVEIS: OU_DECLARACAO_VARIAIVEIS Token_SEMICOLON DECLARACAO_VARIAVEIS
                        | DECLARACAO_VARIAVEIS

DECLARACAO_VARIAVEIS: OU_ID Token_COLON TIPO

TIPO:Token_ID

OU_NUMEROS: OU_NUMEROS Token_COMMA Token_NUMBER
           | Token_NUMBER
           ;

OU_ID: OU_ID Token_COMMA Token_ID
       | Token_ID
       ;

PARTE_DECLARACAO_SUBROTINAS: DECLARACAO_PROCEDIMENTO
                           | DECLARACAO_FUNCAO
                           |
                           ;

DECLARACAO_PROCEDIMENTO: Token_PROCEDURE Token_ID Token_LPAREN PARAMETROS_FORMAIS Token_RPAREN BLOCO

DECLARACAO_FUNCAO: Token_FUNCTION Token_ID PARAMETROS_FORMAIS Token_COLON Token_ID Token_SEMICOLON BLOCO

PARAMETROS_FORMAIS: OU_SECAO_PARAMETROS_FORMAIS

OU_SECAO_PARAMETROS_FORMAIS: OU_SECAO_PARAMETROS_FORMAIS Token_SEMICOLON SECAO_PARAMETROS_FORMAIS
                           | SECAO_PARAMETROS_FORMAIS
                           ;

SECAO_PARAMETROS_FORMAIS: Token_VAR OU_ID Token_COLON Token_ID

COMANDO_COMPOSTO: Token_BEGIN OU_COMANDO Token_END

OU_COMANDO: OU_COMANDO Token_SEMICOLON COMANDO
          | COMANDO
          ;

COMANDO: Token_NUMBER Token_COLON COMANDO_SEM_ROTULO

COMANDO_SEM_ROTULO: ATRIBUICAO
                  | CHAMADA_PROCEDIMENTO
                  | DESVIO
                  | COMANDO_COMPOSTO
                  | COMANDO_CONDICIONAL
                  | COMANDO_REPETITIVO

ATRIBUICAO: VARIAVEL Token_ASSIGN EXPRESSAO

CHAMADA_PROCEDIMENTO: Token_ID Token_LPAREN OU_EXPRESSOES Token_RPAREN

DESVIO: Token_GOTO Token_NUMBER

COMANDO_CONDICIONAL: Token_IF EXPRESSAO Token_THEN COMANDO_SEM_ROTULO
                   | Token_IF EXPRESSAO Token_THEN COMANDO_SEM_ROTULO Token_ELSE COMANDO_SEM_ROTULO

COMANDO_REPETITIVO: Token_WHILE EXPRESSAO Token_DO COMANDO_SEM_ROTULO

OU_EXPRESSOES: OU_EXPRESSOES Token_COMMA EXPRESSAO
             | EXPRESSAO

EXPRESSAO: EXPRESSAO_SIMPLES RELACAO EXPRESSAO_SIMPLES
         | EXPRESSAO_SIMPLES

RELACAO: Token_EQ
       | Token_NE
       | Token_LT
       | Token_LE
       | Token_GE
       | Token_GT
       ;

EXPRESSAO_SIMPLES: Token_PLUS TERMO OU_TERMO
                 | Token_MINUS TERMO OU_TERMO

OU_TERMO: OU_TERMO Token_PLUS TERMO
        | OU_TERMO Token_MINUS TERMO
        | OU_TERMO Token_OR TERMO
        | Token_PLUS TERMO
        | Token_MINUS TERMO
        | Token_OR TERMO
        ;

TERMO: FATOR OU_FATOR

OU_FATOR: OU_FATOR Token_MULT FATOR
        | OU_FATOR Token_DIV FATOR
        | OU_FATOR Token_AND FATOR
        | Token_MULT FATOR
        | Token_DIV FATOR
        | Token_AND FATOR
        ;

FATOR: VARIAVEL
     | Token_NUMBER
     | CHAMADA_DE_FUNCAO
     | Token_LPAREN EXPRESSAO Token_RPAREN
     | Token_NOT FATOR

VARIAVEL: Token_ID

CHAMADA_DE_FUNCAO: Token_ID OU_EXPRESSOES






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
