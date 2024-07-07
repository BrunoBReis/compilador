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

%type <sval> Token_ID
%type <ival> Token_NUMBER



%%
programa:
  Token_PROGRAM Token_ID Token_LPAREN OU_ID Token_RPAREN Token_SEMICOLON BLOCO Token_PERIOD {printf("Aceito\n");}
;

BLOCO:PARTE_DECLARACAO_VARIAVEIS 
     |PARTE_DECLARACAO_SUBROTINAS 
     |COMANDO_COMPOSTO
     ;

PARTE_DECLARACAO_VARIAVEIS:
  Token_VAR OU_DECLARACAO_VARIAVEIS Token_SEMICOLON
  |
;

OU_DECLARACAO_VARIAVEIS: 
  OU_DECLARACAO_VARIAVEIS Token_SEMICOLON DECLARACAO_VARIAVEIS
  | DECLARACAO_VARIAVEIS
;

DECLARACAO_VARIAVEIS:
  OU_ID Token_COLON TIPO
;

OU_ID:
  OU_ID Token_COMMA Token_ID
  | Token_ID
;

TIPO: Token_ID
;

PARTE_DECLARACAO_SUBROTINAS: DECLARACAO_PROCEDIMENTO_NADA 
                           | DECLARA_FUNCOES_NADA
                           ;

DECLARACAO_PROCEDIMENTO_NADA:
  DECLARACAO_PROCEDIMENTO
  |
;

DECLARA_FUNCOES_NADA:
  DECLARA_FUNCOES
  |
;

DECLARACAO_PROCEDIMENTOS:
  DECLARACAO_PROCEDIMENTO DECLARACAO_PROCEDIMENTOS
  | DECLARACAO_PROCEDIMENTO
;

DECLARACAO_PROCEDIMENTO:
  Token_PROCEDURE Token_ID PARAMETROS_FORMAIS_NADA Token_SEMICOLON BLOCO Token_SEMICOLON
;

DECLARA_FUNCOES:
  DECLARA_FUNCAO DECLARA_FUNCOES
  | DECLARA_FUNCAO
;

DECLARA_FUNCAO:
  Token_FUNCTION Token_ID PARAMETROS_FORMAIS_NADA Token_COLON TIPO_FUNC Token_SEMICOLON BLOCO Token_SEMICOLON
;

TIPO_FUNC:
  token_INTEGER
  | token_BOOL
  | Token_ID
;

PARAMETROS_FORMAIS_NADA:
  Token_LPAREN PARAMETROS_FORMAIS Token_RPAREN
  |
;

PARAMETROS_FORMAIS:
  SECAO_PARAMETROS_FORMAIS Token_SEMICOLON PARAMETROS_FORMAIS
  | SECAO_PARAMETROS_FORMAIS
;

SECAO_PARAMETROS_FORMAIS:
  OU_PARAMETROS_FORMAIS Token_COLON TIPO_FORMAL
  | Token_VAR OU_PARAMETROS_FORMAIS Token_COLON TIPO_FORMAL
;

OU_PARAMETROS_FORMAIS:
  OU_PARAMETROS_FORMAIS Token_COMMA Token_ID
  | Token_ID
;

TIPO_FORMAL:
  token_INTEGER
  | token_BOOL
  | Token_ID
;

COMANDO_COMPOSTO:Token_BEGIN COMANDOS Token_END
                | Token_BEGIN Token_END
;

COMANDOS: COMANDO Token_SEMICOLON COMANDOS
        | COMANDO
        | COMANDO Token_SEMICOLON
;

COMANDO:
  ROTULO COMANDO_SEM_ROTULO
;

ROTULO:
  Token_NUMBER Token_COLON
  |
;

COMANDO_SEM_ROTULO:
  ATRIBUICAO_CHAMADA_PROCEDIMENTO
  | COMANDO_REPETITIVO
  | COMANDO_CONDICIONAL
  | COMANDO_COMPOSTO
  | token_READ Token_LPAREN params_read Token_RPAREN
  | token_WRITE Token_LPAREN params_write Token_RPAREN
  | token_WRITELN Token_LPAREN params_write Token_RPAREN
;

ATRIBUICAO_CHAMADA_PROCEDIMENTO:
  Token_ID ATRIBUICAO_OU_CHAMADA
;

ATRIBUICAO_OU_CHAMADA:
  ATRIBUICAO
  | CHAMADA_PROCEDIMENTO
;

ATRIBUICAO:
  Token_ASSIGN EXPRESSAO
;

CHAMADA_PROCEDIMENTO:
  Token_LPAREN OU_EXPRESSOES Token_RPAREN
  | Token_LPAREN Token_RPAREN
  |
;

OU_EXPRESSOES:
  EXPRESSAO Token_COMMA OU_EXPRESSOES
  | EXPRESSAO
;

params_read:
  params_read Token_COMMA Token_ID
  | Token_ID
;

params_write:
  params_write Token_COMMA Token_ID
  | Token_ID
  | Token_NUMBER
;

COMANDO_REPETITIVO:
  Token_WHILE EXPRESSAO Token_DO COMANDO_SEM_ROTULO
;

COMANDO_CONDICIONAL:
  if_then cond_else
;

if_then:
  Token_IF EXPRESSAO Token_THEN COMANDO_SEM_ROTULO
;

cond_else:
  Token_ELSE COMANDO_SEM_ROTULO
;

RELACAO_E_EXPRESSAO_SIMPLES:
  Token_EQ EXPRESSAO_SIMPLES
  | Token_NE EXPRESSAO_SIMPLES
  | Token_LT EXPRESSAO_SIMPLES
  | Token_LE EXPRESSAO_SIMPLES
  | Token_GT EXPRESSAO_SIMPLES
  | Token_GE EXPRESSAO_SIMPLES
;

EXPRESSAO:
  EXPRESSAO_SIMPLES
  | EXPRESSAO_SIMPLES RELACAO_E_EXPRESSAO_SIMPLES
;

termo_com_sinal_opcional:
  Token_MINUS TERMO
  | Token_PLUS TERMO
  | TERMO
;

EXPRESSAO_SIMPLES:
  termo_com_sinal_opcional OP.BASICAS
  | termo_com_sinal_opcional
;

OP.BASICAS:
  operacao_basica OP.BASICAS
  | operacao_basica
;

operacao_basica:
  Token_PLUS TERMO
  | Token_PLUS TERMO
  | Token_OR TERMO
;

TERMO:
  FATOR Token_MULT FATOR
  | FATOR Token_DIV FATOR
  | FATOR Token_AND FATOR
  | FATOR
;

FATOR:
  variavel_ou_funcao
  | Token_NUMBER
  | Token_LPAREN EXPRESSAO Token_RPAREN
  | Token_NOT FATOR
;

variavel_ou_funcao:
  Token_ID funcao_ou_nada
;

funcao_ou_nada:
  chamada_funcao
  |
;

chamada_funcao:
    Token_LPAREN
    OU_EXPRESSOES
    Token_RPAREN
  | Token_LPAREN  Token_RPAREN
;

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
