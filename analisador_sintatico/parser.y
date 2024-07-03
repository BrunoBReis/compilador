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

%token Token_PROGRAM Token_BEGIN Token_END Token_WRITE Token_READ Token_VAR Token_INTEGER Token_PROCEDURE Token_IF Token_THEN Token_ELSE Token_WHILE Token_DO
%token Token_COLON Token_SEMICOLON Token_COMMA Token_DOT Token_LPAREN Token_RPAREN Token_ASSIGN Token_DIV Token_PLUS Token_MINUS Token_MULT Token_DIVIDE
%token Token_LT Token_LE Token_GT Token_GE Token_NE Token_EQ
%token Token_ID Token_NUMBER

%type <ival> expression

%%
program: Token_PROGRAM Token_ID Token_LPAREN identifier_list Token_RPAREN Token_SEMICOLON block Token_DOT
       {
           printf("Aceito\n");
       }
       ;

identifier_list: Token_ID
               | identifier_list Token_COMMA Token_ID
               ;

block: var_declaration_part procedure_declaration_part statement_part
     ;

var_declaration_part: Token_VAR var_declaration_list Token_SEMICOLON
                    | /* empty */
                    ;

var_declaration_list: var_declaration
                    | var_declaration_list Token_SEMICOLON var_declaration
                    ;

var_declaration: identifier_list Token_COLON type
               ;

type: Token_INTEGER
    ;

procedure_declaration_part: procedure_declaration_list
                          | /* empty */
                          ;

procedure_declaration_list: procedure_declaration
                          | procedure_declaration_list procedure_declaration
                          ;

procedure_declaration: Token_PROCEDURE Token_ID Token_SEMICOLON block Token_SEMICOLON
                     ;

statement_part: Token_BEGIN statement_sequence Token_END
              ;

statement_sequence: statement
                  | statement_sequence Token_SEMICOLON statement
                  ;

statement: assignment_statement
         | procedure_statement
         | compound_statement
         | if_statement
         | while_statement
         | read_statement
         | write_statement
         ;

assignment_statement: Token_ID Token_ASSIGN expression
                    ;

procedure_statement: Token_ID
                   ;

compound_statement: Token_BEGIN statement_sequence Token_END
                  ;

if_statement: Token_IF expression Token_THEN statement
            | Token_IF expression Token_THEN statement Token_ELSE statement
            ;

while_statement: Token_WHILE expression Token_DO statement
               ;

read_statement: Token_READ Token_LPAREN Token_ID Token_RPAREN
              ;

write_statement: Token_WRITE Token_LPAREN expression Token_RPAREN
               ;

expression: expression Token_PLUS term
          | expression Token_MINUS term
          | expression Token_LT term
          | expression Token_LE term
          | expression Token_GT term
          | expression Token_GE term
          | expression Token_NE term
          | expression Token_EQ term
          | term
          ;

term: term Token_MULT factor
    | term Token_DIVIDE factor
    | term Token_DIV factor
    | factor
    ;

factor: Token_ID
      | Token_NUMBER
      | Token_LPAREN expression Token_RPAREN
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
