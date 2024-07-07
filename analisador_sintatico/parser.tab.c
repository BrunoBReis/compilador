/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

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

#line 112 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_Token_AND = 3,                  /* Token_AND  */
  YYSYMBOL_Token_ARRAY = 4,                /* Token_ARRAY  */
  YYSYMBOL_Token_BEGIN = 5,                /* Token_BEGIN  */
  YYSYMBOL_Token_DIV = 6,                  /* Token_DIV  */
  YYSYMBOL_Token_DO = 7,                   /* Token_DO  */
  YYSYMBOL_Token_ELSE = 8,                 /* Token_ELSE  */
  YYSYMBOL_Token_END = 9,                  /* Token_END  */
  YYSYMBOL_Token_FUNCTION = 10,            /* Token_FUNCTION  */
  YYSYMBOL_Token_GOTO = 11,                /* Token_GOTO  */
  YYSYMBOL_Token_IF = 12,                  /* Token_IF  */
  YYSYMBOL_Token_LABEL = 13,               /* Token_LABEL  */
  YYSYMBOL_Token_NOT = 14,                 /* Token_NOT  */
  YYSYMBOL_Token_OF = 15,                  /* Token_OF  */
  YYSYMBOL_Token_OR = 16,                  /* Token_OR  */
  YYSYMBOL_Token_PROCEDURE = 17,           /* Token_PROCEDURE  */
  YYSYMBOL_Token_PROGRAM = 18,             /* Token_PROGRAM  */
  YYSYMBOL_Token_THEN = 19,                /* Token_THEN  */
  YYSYMBOL_Token_TYPE = 20,                /* Token_TYPE  */
  YYSYMBOL_Token_VAR = 21,                 /* Token_VAR  */
  YYSYMBOL_Token_WHILE = 22,               /* Token_WHILE  */
  YYSYMBOL_Token_READ = 23,                /* Token_READ  */
  YYSYMBOL_Token_WRITE = 24,               /* Token_WRITE  */
  YYSYMBOL_Token_WRITELN = 25,             /* Token_WRITELN  */
  YYSYMBOL_Token_ASSIGN = 26,              /* Token_ASSIGN  */
  YYSYMBOL_Token_LE = 27,                  /* Token_LE  */
  YYSYMBOL_Token_GE = 28,                  /* Token_GE  */
  YYSYMBOL_Token_NE = 29,                  /* Token_NE  */
  YYSYMBOL_Token_PLUS = 30,                /* Token_PLUS  */
  YYSYMBOL_Token_MINUS = 31,               /* Token_MINUS  */
  YYSYMBOL_Token_MULT = 32,                /* Token_MULT  */
  YYSYMBOL_Token_DIVIDE = 33,              /* Token_DIVIDE  */
  YYSYMBOL_Token_LT = 34,                  /* Token_LT  */
  YYSYMBOL_Token_GT = 35,                  /* Token_GT  */
  YYSYMBOL_Token_EQ = 36,                  /* Token_EQ  */
  YYSYMBOL_Token_LPAREN = 37,              /* Token_LPAREN  */
  YYSYMBOL_Token_RPAREN = 38,              /* Token_RPAREN  */
  YYSYMBOL_Token_LBRACKET = 39,            /* Token_LBRACKET  */
  YYSYMBOL_Token_RBRACKET = 40,            /* Token_RBRACKET  */
  YYSYMBOL_Token_SEMICOLON = 41,           /* Token_SEMICOLON  */
  YYSYMBOL_Token_COLON = 42,               /* Token_COLON  */
  YYSYMBOL_Token_COMMA = 43,               /* Token_COMMA  */
  YYSYMBOL_Token_PERIOD = 44,              /* Token_PERIOD  */
  YYSYMBOL_Token_ID = 45,                  /* Token_ID  */
  YYSYMBOL_Token_NUMBER = 46,              /* Token_NUMBER  */
  YYSYMBOL_token_INTEGER = 47,             /* token_INTEGER  */
  YYSYMBOL_token_WRITE = 48,               /* token_WRITE  */
  YYSYMBOL_token_WRITELN = 49,             /* token_WRITELN  */
  YYSYMBOL_token_READ = 50,                /* token_READ  */
  YYSYMBOL_token_BOOL = 51,                /* token_BOOL  */
  YYSYMBOL_YYACCEPT = 52,                  /* $accept  */
  YYSYMBOL_programa = 53,                  /* programa  */
  YYSYMBOL_TIPO = 54,                      /* TIPO  */
  YYSYMBOL_BLOCO = 55,                     /* BLOCO  */
  YYSYMBOL_PARTE_DECLARACAO_SUBROTINAS = 56, /* PARTE_DECLARACAO_SUBROTINAS  */
  YYSYMBOL_OU_DECLARA_FUNCAO = 57,         /* OU_DECLARA_FUNCAO  */
  YYSYMBOL_DECLARA_FUNCAO = 58,            /* DECLARA_FUNCAO  */
  YYSYMBOL_PARAMETROS_FORMAIS = 59,        /* PARAMETROS_FORMAIS  */
  YYSYMBOL_SECAO_PARAMETROS_FORMAIS = 60,  /* SECAO_PARAMETROS_FORMAIS  */
  YYSYMBOL_OU_PARAMETROS_FORMAIS = 61,     /* OU_PARAMETROS_FORMAIS  */
  YYSYMBOL_OU_DECLARA_PROCEDIMENTO = 62,   /* OU_DECLARA_PROCEDIMENTO  */
  YYSYMBOL_DECLARACAO_PROCEDIMENTO = 63,   /* DECLARACAO_PROCEDIMENTO  */
  YYSYMBOL_PARTE_DECLARACAO_VARIAVEIS = 64, /* PARTE_DECLARACAO_VARIAVEIS  */
  YYSYMBOL_OU_DECLARACAO_VARIAVEIS = 65,   /* OU_DECLARACAO_VARIAVEIS  */
  YYSYMBOL_DECLARACAO_VARIAVEIS = 66,      /* DECLARACAO_VARIAVEIS  */
  YYSYMBOL_OU_ID = 67,                     /* OU_ID  */
  YYSYMBOL_COMANDO_COMPOSTO = 68,          /* COMANDO_COMPOSTO  */
  YYSYMBOL_OU_COMANDO = 69,                /* OU_COMANDO  */
  YYSYMBOL_COMANDO = 70,                   /* COMANDO  */
  YYSYMBOL_COMANDO_SEM_ROTULO = 71,        /* COMANDO_SEM_ROTULO  */
  YYSYMBOL_PARAMETROS_WRITE = 72,          /* PARAMETROS_WRITE  */
  YYSYMBOL_ATRIBUICAO_OU_CHAMADA = 73,     /* ATRIBUICAO_OU_CHAMADA  */
  YYSYMBOL_DECIDE = 74,                    /* DECIDE  */
  YYSYMBOL_ATRIBUICAO = 75,                /* ATRIBUICAO  */
  YYSYMBOL_COMANDO_REPETITIVO = 76,        /* COMANDO_REPETITIVO  */
  YYSYMBOL_COMANDO_CONDICIONAL = 77,       /* COMANDO_CONDICIONAL  */
  YYSYMBOL_CHAMADA_PROCEDIMENTO = 78,      /* CHAMADA_PROCEDIMENTO  */
  YYSYMBOL_CHAMADA_FUNCAO = 79,            /* CHAMADA_FUNCAO  */
  YYSYMBOL_FUNCAO_OU_VARIAVEL = 80,        /* FUNCAO_OU_VARIAVEL  */
  YYSYMBOL_FUNCAO_OU_NADA = 81,            /* FUNCAO_OU_NADA  */
  YYSYMBOL_OU_EXPRESSOES = 82,             /* OU_EXPRESSOES  */
  YYSYMBOL_EXPRESSAO = 83,                 /* EXPRESSAO  */
  YYSYMBOL_RELACAO = 84,                   /* RELACAO  */
  YYSYMBOL_EXPRESSAO_SIMPLES = 85,         /* EXPRESSAO_SIMPLES  */
  YYSYMBOL_TERMO = 86,                     /* TERMO  */
  YYSYMBOL_FATOR = 87                      /* FATOR  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   117

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  145

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   306


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    63,    63,    73,    77,    80,    81,    82,    85,    86,
      89,    92,    93,    96,    97,   100,   101,   105,   106,   109,
     110,   114,   115,   118,   119,   122,   127,   131,   136,   139,
     140,   143,   146,   147,   148,   149,   150,   151,   152,   155,
     159,   162,   165,   166,   169,   180,   183,   184,   187,   188,
     191,   194,   205,   206,   209,   210,   213,   214,   217,   218,
     219,   220,   221,   222,   225,   226,   227,   228,   231,   232,
     233,   234,   237,   238,   239,   240
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "Token_AND",
  "Token_ARRAY", "Token_BEGIN", "Token_DIV", "Token_DO", "Token_ELSE",
  "Token_END", "Token_FUNCTION", "Token_GOTO", "Token_IF", "Token_LABEL",
  "Token_NOT", "Token_OF", "Token_OR", "Token_PROCEDURE", "Token_PROGRAM",
  "Token_THEN", "Token_TYPE", "Token_VAR", "Token_WHILE", "Token_READ",
  "Token_WRITE", "Token_WRITELN", "Token_ASSIGN", "Token_LE", "Token_GE",
  "Token_NE", "Token_PLUS", "Token_MINUS", "Token_MULT", "Token_DIVIDE",
  "Token_LT", "Token_GT", "Token_EQ", "Token_LPAREN", "Token_RPAREN",
  "Token_LBRACKET", "Token_RBRACKET", "Token_SEMICOLON", "Token_COLON",
  "Token_COMMA", "Token_PERIOD", "Token_ID", "Token_NUMBER",
  "token_INTEGER", "token_WRITE", "token_WRITELN", "token_READ",
  "token_BOOL", "$accept", "programa", "TIPO", "BLOCO",
  "PARTE_DECLARACAO_SUBROTINAS", "OU_DECLARA_FUNCAO", "DECLARA_FUNCAO",
  "PARAMETROS_FORMAIS", "SECAO_PARAMETROS_FORMAIS",
  "OU_PARAMETROS_FORMAIS", "OU_DECLARA_PROCEDIMENTO",
  "DECLARACAO_PROCEDIMENTO", "PARTE_DECLARACAO_VARIAVEIS",
  "OU_DECLARACAO_VARIAVEIS", "DECLARACAO_VARIAVEIS", "OU_ID",
  "COMANDO_COMPOSTO", "OU_COMANDO", "COMANDO", "COMANDO_SEM_ROTULO",
  "PARAMETROS_WRITE", "ATRIBUICAO_OU_CHAMADA", "DECIDE", "ATRIBUICAO",
  "COMANDO_REPETITIVO", "COMANDO_CONDICIONAL", "CHAMADA_PROCEDIMENTO",
  "CHAMADA_FUNCAO", "FUNCAO_OU_VARIAVEL", "FUNCAO_OU_NADA",
  "OU_EXPRESSOES", "EXPRESSAO", "RELACAO", "EXPRESSAO_SIMPLES", "TERMO",
  "FATOR", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-90)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       7,   -17,    32,     4,   -90,   -11,   -90,    20,    28,    33,
      56,   -90,   -11,    35,     9,   -11,   -90,   -26,   -90,    36,
      38,    75,    74,   -90,    68,   -90,   -90,    41,    -3,   -12,
      -2,   -90,   -90,   -90,   -90,    46,    43,   -90,    47,    49,
      29,    56,    50,   -10,   -10,   -14,    57,    58,    59,   -90,
      -4,   -90,   -90,   -90,   -90,   -90,   -90,    31,    41,    -3,
      41,    48,    60,    56,   -10,   -10,    61,   -90,   -90,    78,
      26,    14,     8,    92,   -10,   -10,   -90,   -90,   -90,    11,
      11,    11,   -90,    -2,    41,    62,   -90,   -90,   -90,   -90,
      63,   -90,    64,   -10,   -90,   -90,    -2,   -90,   -90,   -90,
     -90,   -90,   -90,   -10,   -10,   -10,   -10,   -10,   -10,   -10,
      -2,   -90,    21,   -90,   -90,   -90,    67,    69,    70,   -90,
     -90,    56,   -90,   -90,    27,    98,   -90,   -90,   -90,   -90,
     -90,   -90,   -90,   -90,   -90,   -10,   -90,   -90,   -90,    71,
     -90,    -2,   -90,   -90,   -90
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,    27,     0,     0,     0,
      22,    26,     0,     0,     7,    21,    24,     0,     2,     0,
       0,     0,     6,     9,     5,    18,    23,     0,     0,     0,
       0,     4,     8,    17,     3,     0,     0,    16,     0,    12,
       0,    22,     0,     0,     0,    49,     0,     0,     0,    35,
       0,    30,    31,    32,    33,    34,    25,     0,     0,     0,
       0,     0,     0,    22,     0,     0,    53,    73,    72,     0,
      57,    67,    71,     0,     0,     0,    41,    42,    43,     0,
       0,     0,    28,     0,     0,     0,    11,    13,    15,    20,
       0,    75,     0,     0,    52,    51,     0,    61,    62,    59,
      60,    63,    58,     0,     0,     0,     0,     0,     0,     0,
       0,    44,     0,    55,    39,    40,     0,     0,     0,    29,
      14,    22,    19,    74,     0,    47,    56,    64,    66,    65,
      68,    69,    70,    45,    48,     0,    36,    37,    38,     0,
      50,     0,    54,    10,    46
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -90,   -90,   -45,   -39,   -90,   -90,    87,   -21,   -90,    77,
     -90,    76,   -90,   -90,    95,   106,    93,   -90,    34,   -89,
      -5,   -90,   -90,   -90,   -90,   -90,   -90,   -90,   -90,   -90,
      22,   -43,   -90,    13,   -38,   -58
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,    35,    13,    21,    22,    23,    38,    39,    40,
      24,    25,    14,    15,    16,    17,    49,    50,    51,    52,
     116,    53,    76,    77,    54,    55,    78,    94,    68,    95,
     112,   113,   103,    70,    71,    72
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      69,    73,    62,    30,    64,    82,    91,   125,    42,    36,
      43,   107,    74,    85,   108,    87,    27,     9,    36,    19,
      44,   133,    92,    75,    90,     1,    20,    65,     3,    41,
     104,   111,     4,    37,     6,    66,    67,    83,    86,   120,
     109,     5,    37,    45,   105,   106,    46,    47,    48,   130,
     131,   132,   144,    97,    98,    99,   114,   115,     8,   134,
     100,   101,   102,     9,   135,   140,   127,   128,   129,    10,
     135,    60,    61,    84,    61,   117,   118,    12,    11,    18,
      30,    28,   139,    29,    19,    20,    34,    56,    37,    58,
      59,    63,   142,    88,    79,    80,    81,    96,    93,   110,
      33,    89,   123,   121,   122,   136,   141,   137,   138,    32,
      26,     7,   143,    57,    31,   124,   126,   119
};

static const yytype_uint8 yycheck[] =
{
      43,    44,    41,     5,    14,     9,    64,    96,    29,    21,
      12,     3,    26,    58,     6,    60,    42,    43,    21,    10,
      22,   110,    65,    37,    63,    18,    17,    37,    45,    41,
      16,    74,     0,    45,    45,    45,    46,    41,    59,    84,
      32,    37,    45,    45,    30,    31,    48,    49,    50,   107,
     108,   109,   141,    27,    28,    29,    45,    46,    38,    38,
      34,    35,    36,    43,    43,    38,   104,   105,   106,    41,
      43,    42,    43,    42,    43,    80,    81,    21,    45,    44,
       5,    45,   121,    45,    10,    17,    45,    41,    45,    42,
      41,    41,   135,    45,    37,    37,    37,    19,    37,     7,
      24,    41,    38,    41,    41,    38,     8,    38,    38,    22,
      15,     5,    41,    36,    21,    93,   103,    83
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    18,    53,    45,     0,    37,    45,    67,    38,    43,
      41,    45,    21,    55,    64,    65,    66,    67,    44,    10,
      17,    56,    57,    58,    62,    63,    66,    42,    45,    45,
       5,    68,    58,    63,    45,    54,    21,    45,    59,    60,
      61,    41,    59,    12,    22,    45,    48,    49,    50,    68,
      69,    70,    71,    73,    76,    77,    41,    61,    42,    41,
      42,    43,    55,    41,    14,    37,    45,    46,    80,    83,
      85,    86,    87,    83,    26,    37,    74,    75,    78,    37,
      37,    37,     9,    41,    42,    54,    59,    54,    45,    41,
      55,    87,    83,    37,    79,    81,    19,    27,    28,    29,
      34,    35,    36,    84,    16,    30,    31,     3,     6,    32,
       7,    83,    82,    83,    45,    46,    72,    72,    72,    70,
      54,    41,    41,    38,    82,    71,    85,    86,    86,    86,
      87,    87,    87,    71,    38,    43,    38,    38,    38,    55,
      38,     8,    83,    41,    71
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    52,    53,    54,    55,    56,    56,    56,    57,    57,
      58,    59,    59,    60,    60,    61,    61,    62,    62,    63,
      63,    64,    64,    65,    65,    66,    67,    67,    68,    69,
      69,    70,    71,    71,    71,    71,    71,    71,    71,    72,
      72,    73,    74,    74,    75,    76,    77,    77,    78,    78,
      79,    80,    81,    81,    82,    82,    83,    83,    84,    84,
      84,    84,    84,    84,    85,    85,    85,    85,    86,    86,
      86,    86,    87,    87,    87,    87
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     8,     1,     3,     1,     1,     0,     2,     1,
       8,     3,     1,     3,     4,     3,     1,     2,     1,     6,
       5,     2,     0,     2,     1,     4,     3,     1,     3,     3,
       1,     1,     1,     1,     1,     1,     4,     4,     4,     1,
       1,     2,     1,     1,     2,     4,     6,     4,     3,     0,
       3,     2,     1,     0,     3,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     3,     1,     3,     3,
       3,     1,     1,     1,     3,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* programa: Token_PROGRAM Token_ID Token_LPAREN OU_ID Token_RPAREN Token_SEMICOLON BLOCO Token_PERIOD  */
#line 63 "parser.y"
                                                                                                   { 
    if(tem_erro == 0){
        printf("Aceito\n");
    }else
    {
        printf("Rejeito \n", tem_erro);
    }
}
#line 1296 "parser.tab.c"
    break;

  case 25: /* DECLARACAO_VARIAVEIS: OU_ID Token_COLON TIPO Token_SEMICOLON  */
#line 122 "parser.y"
                                                             {
                    
}
#line 1304 "parser.tab.c"
    break;

  case 26: /* OU_ID: OU_ID Token_COMMA Token_ID  */
#line 127 "parser.y"
                                  {
                         
                        adiciona_simbolo((yyvsp[0].sval), (yyvsp[0].sval));
                        }
#line 1313 "parser.tab.c"
    break;

  case 27: /* OU_ID: Token_ID  */
#line 131 "parser.y"
               {        
                        adiciona_simbolo((yyvsp[0].sval), (yyvsp[0].sval));
                        }
#line 1321 "parser.tab.c"
    break;

  case 39: /* PARAMETROS_WRITE: Token_ID  */
#line 155 "parser.y"
                           {
                if(!declarado((yyvsp[0].sval))){
                    tem_erro = 1;
                }}
#line 1330 "parser.tab.c"
    break;

  case 44: /* ATRIBUICAO: Token_ASSIGN EXPRESSAO  */
#line 169 "parser.y"
                                   {
        
        if(!declarado((yyvsp[-1].sval))){
            tem_erro++;

        }
    
    }
#line 1343 "parser.tab.c"
    break;

  case 51: /* FUNCAO_OU_VARIAVEL: Token_ID FUNCAO_OU_NADA  */
#line 194 "parser.y"
                                            {
    if((yyvsp[0].sval) == NULL)
    {
        if(!declarado((yyvsp[-1].sval)))
        {
            tem_erro =1;
        }
    }
}
#line 1357 "parser.tab.c"
    break;


#line 1361 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 243 "parser.y"

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
