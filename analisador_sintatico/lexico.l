%{
#include "parser.tab.h"
%}

%%
"program"       { return Token_PROGRAM; }
"begin"         { return Token_BEGIN; }
"end"           { return Token_END; }
"write"         { return Token_WRITE; }
"read"          { return Token_READ; }
"var"           { return Token_VAR; }
"integer"       { return Token_INTEGER; }
"procedure"     { return Token_PROCEDURE; }
"if"            { return Token_IF; }
"then"          { return Token_THEN; }
"else"          { return Token_ELSE; }
"while"         { return Token_WHILE; }
"do"            { return Token_DO; }
":="            { return Token_ASSIGN; }
"<="            { return Token_LE; }
">="            { return Token_GE; }
"<>"            { return Token_NE; }
"<"             { return Token_LT; }
">"             { return Token_GT; }
"="             { return Token_EQ; }
"div"           { return Token_DIV; }
"+"             { return Token_PLUS; }
"-"             { return Token_MINUS; }
"*"             { return Token_MULT; }
"/"             { return Token_DIVIDE; }
"("             { return Token_LPAREN; }
")"             { return Token_RPAREN; }
":"             { return Token_COLON; }
";"             { return Token_SEMICOLON; }
","             { return Token_COMMA; }
"."             { return Token_DOT; }
[a-zA-Z][a-zA-Z0-9]* { yylval.sval = strdup(yytext); return Token_ID; }
[0-9]+          { yylval.ival = atoi(yytext); return Token_NUMBER; }
[ \t\n]         { }
\(\*([^*]|\*+[^)])*\*+\) { }
.               { fprintf(stderr, "Caractere inválido: %s\n", yytext); }
%%

int yywrap() {
    return 1;
}
