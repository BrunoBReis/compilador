%{
#include "parser.tab.h"
%}

%%
"and"           { return Token_AND; }
"array"         { return Token_ARRAY; }
"begin"         { return Token_BEGIN; }
"div"           { return Token_DIV; }
"do"            { return Token_DO; }
"else"          { return Token_ELSE; }
"end"           { return Token_END; }
"function"      { return Token_FUNCTION; }
"goto"          { return Token_GOTO; }
"if"            { return Token_IF; }
"label"         { return Token_LABEL; }
"not"           { return Token_NOT; }
"of"            { return Token_OF; }
"or"            { return Token_OR; }
"procedure"     { return Token_PROCEDURE; }
"program"       { return Token_PROGRAM; }
"then"          { return Token_THEN; }
"type"          { return Token_TYPE; }
"var"           { return Token_VAR; }
"while"         { return Token_WHILE; }
"integer"       { return token_INTEGER; }
"bool"          { return token_BOOL; }
"write"         { return token_WRITE; }
"writeln"         { return token_WRITELN; }
"read"         { return token_READ; }
":="            { return Token_ASSIGN; }
"<="            { return Token_LE; }
">="            { return Token_GE; }
"<>"            { return Token_NE; }
"+"             { return Token_PLUS; }
"-"             { return Token_MINUS; }
"*"             { return Token_MULT; }
"/"             { return Token_DIVIDE; }
"<"             { return Token_LT; }
">"             { return Token_GT; }
"="             { return Token_EQ; }
"("             { return Token_LPAREN; }
")"             { return Token_RPAREN; }
"["             { return Token_LBRACKET; }
"]"             { return Token_RBRACKET; }
";"             { return Token_SEMICOLON; }
":"             { return Token_COLON; }
","             { return Token_COMMA; }
"."             { return Token_PERIOD; }    
[a-zA-Z][a-zA-Z0-9]* { yylval.sval = strdup(yytext); return Token_ID; }
[[0-9]+(\.[0-9]+)?   { yylval.ival = atoi(yytext); return Token_NUMBER; }
[ \t\n]         { }
\(\*([^*]|\*+[^)])*\*+\) { }
.               { fprintf(stderr, "Caractere inválido: %s\n", yytext); }
%%

int yywrap() {
    return 1;
}
