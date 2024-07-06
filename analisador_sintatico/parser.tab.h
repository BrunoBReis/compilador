/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    Token_AND = 258,               /* Token_AND  */
    Token_ARRAY = 259,             /* Token_ARRAY  */
    Token_BEGIN = 260,             /* Token_BEGIN  */
    Token_DIV = 261,               /* Token_DIV  */
    Token_DO = 262,                /* Token_DO  */
    Token_ELSE = 263,              /* Token_ELSE  */
    Token_END = 264,               /* Token_END  */
    Token_FUNCTION = 265,          /* Token_FUNCTION  */
    Token_GOTO = 266,              /* Token_GOTO  */
    Token_IF = 267,                /* Token_IF  */
    Token_LABEL = 268,             /* Token_LABEL  */
    Token_NOT = 269,               /* Token_NOT  */
    Token_OF = 270,                /* Token_OF  */
    Token_OR = 271,                /* Token_OR  */
    Token_PROCEDURE = 272,         /* Token_PROCEDURE  */
    Token_PROGRAM = 273,           /* Token_PROGRAM  */
    Token_THEN = 274,              /* Token_THEN  */
    Token_TYPE = 275,              /* Token_TYPE  */
    Token_VAR = 276,               /* Token_VAR  */
    Token_WHILE = 277,             /* Token_WHILE  */
    Token_READ = 278,              /* Token_READ  */
    Token_WRITE = 279,             /* Token_WRITE  */
    Token_WRITELN = 280,           /* Token_WRITELN  */
    Token_ASSIGN = 281,            /* Token_ASSIGN  */
    Token_LE = 282,                /* Token_LE  */
    Token_GE = 283,                /* Token_GE  */
    Token_NE = 284,                /* Token_NE  */
    Token_PLUS = 285,              /* Token_PLUS  */
    Token_MINUS = 286,             /* Token_MINUS  */
    Token_MULT = 287,              /* Token_MULT  */
    Token_DIVIDE = 288,            /* Token_DIVIDE  */
    Token_LT = 289,                /* Token_LT  */
    Token_GT = 290,                /* Token_GT  */
    Token_EQ = 291,                /* Token_EQ  */
    Token_LPAREN = 292,            /* Token_LPAREN  */
    Token_RPAREN = 293,            /* Token_RPAREN  */
    Token_LBRACKET = 294,          /* Token_LBRACKET  */
    Token_RBRACKET = 295,          /* Token_RBRACKET  */
    Token_SEMICOLON = 296,         /* Token_SEMICOLON  */
    Token_COLON = 297,             /* Token_COLON  */
    Token_COMMA = 298,             /* Token_COMMA  */
    Token_PERIOD = 299,            /* Token_PERIOD  */
    Token_ID = 300,                /* Token_ID  */
    Token_NUMBER = 301             /* Token_NUMBER  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 12 "parser.y"

    int ival;
    char *sval;

#line 115 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
