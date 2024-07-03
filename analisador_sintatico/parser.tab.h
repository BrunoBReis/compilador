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
    Token_PROGRAM = 258,           /* Token_PROGRAM  */
    Token_BEGIN = 259,             /* Token_BEGIN  */
    Token_END = 260,               /* Token_END  */
    Token_WRITE = 261,             /* Token_WRITE  */
    Token_READ = 262,              /* Token_READ  */
    Token_VAR = 263,               /* Token_VAR  */
    Token_INTEGER = 264,           /* Token_INTEGER  */
    Token_PROCEDURE = 265,         /* Token_PROCEDURE  */
    Token_IF = 266,                /* Token_IF  */
    Token_THEN = 267,              /* Token_THEN  */
    Token_ELSE = 268,              /* Token_ELSE  */
    Token_WHILE = 269,             /* Token_WHILE  */
    Token_DO = 270,                /* Token_DO  */
    Token_COLON = 271,             /* Token_COLON  */
    Token_SEMICOLON = 272,         /* Token_SEMICOLON  */
    Token_COMMA = 273,             /* Token_COMMA  */
    Token_DOT = 274,               /* Token_DOT  */
    Token_LPAREN = 275,            /* Token_LPAREN  */
    Token_RPAREN = 276,            /* Token_RPAREN  */
    Token_ASSIGN = 277,            /* Token_ASSIGN  */
    Token_DIV = 278,               /* Token_DIV  */
    Token_PLUS = 279,              /* Token_PLUS  */
    Token_MINUS = 280,             /* Token_MINUS  */
    Token_MULT = 281,              /* Token_MULT  */
    Token_DIVIDE = 282,            /* Token_DIVIDE  */
    Token_LT = 283,                /* Token_LT  */
    Token_LE = 284,                /* Token_LE  */
    Token_GT = 285,                /* Token_GT  */
    Token_GE = 286,                /* Token_GE  */
    Token_NE = 287,                /* Token_NE  */
    Token_EQ = 288,                /* Token_EQ  */
    Token_ID = 289,                /* Token_ID  */
    Token_NUMBER = 290             /* Token_NUMBER  */
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

#line 104 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
