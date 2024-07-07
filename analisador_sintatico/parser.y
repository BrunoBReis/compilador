%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct simbolo
{
    char *name;
    int type;
}simbolo;

simbolo Lista_simbolo[1000];
int num_simbolos = 0;
int tem_erro=0;

void adiciona_simbolo(char *name, int tipo)
{
    Lista_simbolo[num_simbolos].name = strdup(name);
    Lista_simbolo[num_simbolos].type = tipo;
    num_simbolos++;
}

int declarado(char *name)
{
    for(int i = 0; i< num_simbolos;i++)
    {
        if(strcmp(Lista_simbolo[i].name, name)==0){
            return 1;
        }
    }
    return 0;
}


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
%type <sval> TIPO
%type <sval> Token_ASSIGN
%type <ival> Token_NUMBER
%type <sval> OU_ID
%type <sval> FUNCAO_OU_NADA


%%
programa : Token_PROGRAM Token_ID Token_LPAREN OU_ID Token_RPAREN Token_SEMICOLON BLOCO Token_PERIOD {
    if (tem_erro == 0) {
        printf("Aceito\n");
    } else {
        printf("Rejeito, %d erros\n", tem_erro);
    }
}
         ;

TIPO : Token_ID
     ;

BLOCO : PARTE_DECLARACAO_ROTULOS PARTE_DECLARACAO_VARIAVEIS PARTE_DECLARACAO_SUBROTINAS COMANDO_COMPOSTO
      ;

PARTE_DECLARACAO_ROTULOS : Token_LABEL OU_NUMEROS Token_SEMICOLON
                         |
                         ;

OU_NUMEROS : Token_NUMBER Token_COMMA OU_NUMEROS
           | Token_NUMBER
           ;

DESVIO : Token_GOTO Token_NUMBER
       ;

PARTE_DECLARACAO_SUBROTINAS : OU_DECLARA_PROCEDIMENTO
                            | OU_DECLARA_FUNCAO
                            |
                            ;

OU_DECLARA_FUNCAO : OU_DECLARA_FUNCAO DECLARA_FUNCAO
                  | DECLARA_FUNCAO
                  ;

DECLARA_FUNCAO : Token_FUNCTION Token_ID PARAMETROS_FORMAIS_NADA Token_COLON TIPO Token_SEMICOLON BLOCO Token_SEMICOLON
              ;

PARAMETROS_FORMAIS : SECAO_PARAMETROS_FORMAIS Token_SEMICOLON PARAMETROS_FORMAIS
                   | SECAO_PARAMETROS_FORMAIS
                   ;

SECAO_PARAMETROS_FORMAIS : OU_PARAMETROS_FORMAIS Token_COLON TIPO
                         | Token_VAR OU_PARAMETROS_FORMAIS Token_COLON TIPO
                         ;

OU_PARAMETROS_FORMAIS : OU_PARAMETROS_FORMAIS Token_COMMA Token_ID
                      | Token_ID {adiciona_simbolo($1, $1);}
                      ;


OU_DECLARA_PROCEDIMENTO : OU_DECLARA_PROCEDIMENTO DECLARACAO_PROCEDIMENTO
                        | DECLARACAO_PROCEDIMENTO
                        ;

DECLARACAO_PROCEDIMENTO : Token_PROCEDURE Token_ID PARAMETROS_FORMAIS_NADA Token_SEMICOLON BLOCO Token_SEMICOLON
                         ;
PARAMETROS_FORMAIS_NADA: Token_LPAREN PARAMETROS_FORMAIS Token_RPAREN
                       |
                       ;

PARTE_DECLARACAO_VARIAVEIS : Token_VAR OU_DECLARACAO_VARIAVEIS
                           |
                           ;

OU_DECLARACAO_VARIAVEIS : OU_DECLARACAO_VARIAVEIS DECLARACAO_VARIAVEIS
                        | DECLARACAO_VARIAVEIS
                        ;

DECLARACAO_VARIAVEIS : OU_ID Token_COLON TIPO Token_SEMICOLON {
                            adiciona_simbolo($1, $3);
                      }
                     ;

OU_ID : OU_ID Token_COMMA Token_ID {
            adiciona_simbolo($3, $1);
       }
      | Token_ID {
            adiciona_simbolo($1, $1);
       }
      ;

COMANDO_COMPOSTO : Token_BEGIN OU_COMANDO Token_END
                 ;

OU_COMANDO : OU_COMANDO Token_SEMICOLON COMANDO
           | COMANDO
           ;

COMANDO : ROTULO COMANDO_SEM_ROTULO
       ;

ROTULO : Token_NUMBER Token_COLON
       |
       ;

COMANDO_SEM_ROTULO : ATRIBUICAO_OU_CHAMADA
                   | DESVIO
                   | COMANDO_REPETITIVO
                   | COMANDO_CONDICIONAL
                   | COMANDO_COMPOSTO
                   | token_WRITE Token_LPAREN OU_EXPRESSOES Token_RPAREN
                   | token_WRITELN Token_LPAREN OU_EXPRESSOES Token_RPAREN
                   | token_READ Token_LPAREN OU_EXPRESSOES Token_RPAREN
                   ;

PARAMETROS_WRITE : Token_ID {
                        if (!declarado($1)) {
                            tem_erro++;
                        }
                   }
                 | Token_NUMBER
                 ;

ATRIBUICAO_OU_CHAMADA : Token_ID DECIDE
                       ;

DECIDE : ATRIBUICAO
       | CHAMADA_PROCEDIMENTO
       ;

ATRIBUICAO : Token_ASSIGN EXPRESSAO {
                    if (!declarado($1)) {
                        tem_erro++;
                    }
               }
           ;


COMANDO_REPETITIVO : Token_WHILE EXPRESSAO Token_DO COMANDO_SEM_ROTULO
                   ;

COMANDO_CONDICIONAL : Token_IF EXPRESSAO Token_THEN COMANDO_SEM_ROTULO Token_ELSE COMANDO_SEM_ROTULO
                    | Token_IF EXPRESSAO Token_THEN COMANDO_SEM_ROTULO
                    ;

CHAMADA_PROCEDIMENTO : Token_LPAREN OU_EXPRESSOES Token_RPAREN
                     | 
                     ;

CHAMADA_FUNCAO : Token_LPAREN OU_EXPRESSOES Token_RPAREN
               ;

FUNCAO_OU_VARIAVEL : Token_ID FUNCAO_OU_NADA {
                        if ($2 == NULL) {
                            if (!declarado($1)) {
                                tem_erro = 1;
                            }
                        }
                    }
                   ;

FUNCAO_OU_NADA : CHAMADA_FUNCAO
               |
               ;

OU_EXPRESSOES : EXPRESSAO
              | OU_EXPRESSOES Token_COMMA EXPRESSAO 
              ;

EXPRESSAO : EXPRESSAO_SIMPLES RELACAO EXPRESSAO_SIMPLES
          | EXPRESSAO_SIMPLES
          ;

RELACAO : Token_EQ
        | Token_NE
        | Token_LT
        | Token_LE
        | Token_GE
        | Token_GT
        ;

TERMO_SINAL_OPCIONAL: Token_MINUS TERMO
                    | Token_PLUS TERMO
                    | TERMO
                    ;

EXPRESSAO_SIMPLES : TERMO_SINAL_OPCIONAL OPS_BASICAS
                  | TERMO_SINAL_OPCIONAL
                  ;

OPS_BASICAS: OP_BASICO OPS_BASICAS
           | OP_BASICO
           ;

OP_BASICO: Token_PLUS TERMO
         | Token_MINUS TERMO
         | Token_OR TERMO
         ;


TERMO : FATOR Token_AND FATOR
      | FATOR Token_DIV FATOR
      | FATOR Token_MULT FATOR
      | FATOR
      ;

FATOR : FUNCAO_OU_VARIAVEL
      | Token_NUMBER
      | Token_LPAREN EXPRESSAO Token_RPAREN
      | Token_NOT FATOR
      ;

%%
void yyerror(const char *s) {
    fprintf(stderr, "Rejeito\n");
}

int main(int argc, char **argv) {
    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (!file) {
            perror("Erro ao abrir arquivo");
            return 1;
        }
        yyin = file;
    }
    yyparse();
    return 0;
}
