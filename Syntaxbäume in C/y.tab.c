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
#line 1 "ll.y"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "SyntaxTree.h"


Expr* e;

//FunDef* funs;
//int funsNr;
Program p;
 
int start_token;

int paramsNr;
int* params;
 
int argsNr;
Expr** args;


int yylex();
void yyerror(const char *s);

 

#line 100 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    TFUN = 258,                    /* TFUN  */
    TSEMICOLON = 259,              /* TSEMICOLON  */
    TLBRC = 260,                   /* TLBRC  */
    TRBRC = 261,                   /* TRBRC  */
    TOR = 262,                     /* TOR  */
    TAND = 263,                    /* TAND  */
    TADD = 264,                    /* TADD  */
    TSUB = 265,                    /* TSUB  */
    TMUL = 266,                    /* TMUL  */
    TDIV = 267,                    /* TDIV  */
    TMOD = 268,                    /* TMOD  */
    TLE = 269,                     /* TLE  */
    TLT = 270,                     /* TLT  */
    TGE = 271,                     /* TGE  */
    TGT = 272,                     /* TGT  */
    TEQ = 273,                     /* TEQ  */
    TNEQ = 274,                    /* TNEQ  */
    TASSIGN = 275,                 /* TASSIGN  */
    TLPAR = 276,                   /* TLPAR  */
    TRPAR = 277,                   /* TRPAR  */
    TWHILE = 278,                  /* TWHILE  */
    TIF = 279,                     /* TIF  */
    TELSE = 280,                   /* TELSE  */
    TINTEGER = 281,                /* TINTEGER  */
    TVAR = 282,                    /* TVAR  */
    TIDENT = 283,                  /* TIDENT  */
    START_PROGRAM = 284,           /* START_PROGRAM  */
    START_STATEMENT = 285          /* START_STATEMENT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define TFUN 258
#define TSEMICOLON 259
#define TLBRC 260
#define TRBRC 261
#define TOR 262
#define TAND 263
#define TADD 264
#define TSUB 265
#define TMUL 266
#define TDIV 267
#define TMOD 268
#define TLE 269
#define TLT 270
#define TGE 271
#define TGT 272
#define TEQ 273
#define TNEQ 274
#define TASSIGN 275
#define TLPAR 276
#define TRPAR 277
#define TWHILE 278
#define TIF 279
#define TELSE 280
#define TINTEGER 281
#define TVAR 282
#define TIDENT 283
#define START_PROGRAM 284
#define START_STATEMENT 285

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 50 "ll.y"

  long int nr;
  long int* params;
  Expr* expr;
  FunDef funDef;
  FunCallExpr funCall;
  Program prog;
  char* id;
  ParseResult start;

#line 224 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TFUN = 3,                       /* TFUN  */
  YYSYMBOL_TSEMICOLON = 4,                 /* TSEMICOLON  */
  YYSYMBOL_TLBRC = 5,                      /* TLBRC  */
  YYSYMBOL_TRBRC = 6,                      /* TRBRC  */
  YYSYMBOL_TOR = 7,                        /* TOR  */
  YYSYMBOL_TAND = 8,                       /* TAND  */
  YYSYMBOL_TADD = 9,                       /* TADD  */
  YYSYMBOL_TSUB = 10,                      /* TSUB  */
  YYSYMBOL_TMUL = 11,                      /* TMUL  */
  YYSYMBOL_TDIV = 12,                      /* TDIV  */
  YYSYMBOL_TMOD = 13,                      /* TMOD  */
  YYSYMBOL_TLE = 14,                       /* TLE  */
  YYSYMBOL_TLT = 15,                       /* TLT  */
  YYSYMBOL_TGE = 16,                       /* TGE  */
  YYSYMBOL_TGT = 17,                       /* TGT  */
  YYSYMBOL_TEQ = 18,                       /* TEQ  */
  YYSYMBOL_TNEQ = 19,                      /* TNEQ  */
  YYSYMBOL_TASSIGN = 20,                   /* TASSIGN  */
  YYSYMBOL_TLPAR = 21,                     /* TLPAR  */
  YYSYMBOL_TRPAR = 22,                     /* TRPAR  */
  YYSYMBOL_TWHILE = 23,                    /* TWHILE  */
  YYSYMBOL_TIF = 24,                       /* TIF  */
  YYSYMBOL_TELSE = 25,                     /* TELSE  */
  YYSYMBOL_TINTEGER = 26,                  /* TINTEGER  */
  YYSYMBOL_TVAR = 27,                      /* TVAR  */
  YYSYMBOL_TIDENT = 28,                    /* TIDENT  */
  YYSYMBOL_START_PROGRAM = 29,             /* START_PROGRAM  */
  YYSYMBOL_START_STATEMENT = 30,           /* START_STATEMENT  */
  YYSYMBOL_31_ = 31,                       /* ','  */
  YYSYMBOL_YYACCEPT = 32,                  /* $accept  */
  YYSYMBOL_meta_start = 33,                /* meta_start  */
  YYSYMBOL_program = 34,                   /* program  */
  YYSYMBOL_fundef = 35,                    /* fundef  */
  YYSYMBOL_36_1 = 36,                      /* $@1  */
  YYSYMBOL_params = 37,                    /* params  */
  YYSYMBOL_paramsLoop = 38,                /* paramsLoop  */
  YYSYMBOL_main = 39,                      /* main  */
  YYSYMBOL_statement = 40,                 /* statement  */
  YYSYMBOL_block = 41,                     /* block  */
  YYSYMBOL_expr = 42,                      /* expr  */
  YYSYMBOL_logicExpr = 43,                 /* logicExpr  */
  YYSYMBOL_cmpExpr = 44,                   /* cmpExpr  */
  YYSYMBOL_mulExpr = 45,                   /* mulExpr  */
  YYSYMBOL_addExpr = 46,                   /* addExpr  */
  YYSYMBOL_atom = 47,                      /* atom  */
  YYSYMBOL_args = 48,                      /* args  */
  YYSYMBOL_argsLoop = 49,                  /* argsLoop  */
  YYSYMBOL_whileStat = 50,                 /* whileStat  */
  YYSYMBOL_ifStat = 51                     /* ifStat  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  25
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   80

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  47
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  89

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   285


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
       2,     2,     2,     2,    31,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    64,    64,    65,    69,    70,    74,    74,    79,    80,
      84,    85,    90,    91,    95,    96,    97,    98,   102,   106,
     107,   111,   112,   113,   118,   119,   120,   121,   122,   123,
     124,   128,   129,   130,   131,   136,   137,   138,   143,   144,
     145,   146,   151,   152,   156,   157,   161,   164
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
  "\"end of file\"", "error", "\"invalid token\"", "TFUN", "TSEMICOLON",
  "TLBRC", "TRBRC", "TOR", "TAND", "TADD", "TSUB", "TMUL", "TDIV", "TMOD",
  "TLE", "TLT", "TGE", "TGT", "TEQ", "TNEQ", "TASSIGN", "TLPAR", "TRPAR",
  "TWHILE", "TIF", "TELSE", "TINTEGER", "TVAR", "TIDENT", "START_PROGRAM",
  "START_STATEMENT", "','", "$accept", "meta_start", "program", "fundef",
  "$@1", "params", "paramsLoop", "main", "statement", "block", "expr",
  "logicExpr", "cmpExpr", "mulExpr", "addExpr", "atom", "args", "argsLoop",
  "whileStat", "ifStat", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-69)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      22,     8,     4,    29,    -9,     8,   -69,     4,     4,    41,
      42,   -69,    35,    43,    61,   -69,   -69,   -69,    46,    19,
      34,    47,   -69,   -69,   -69,   -69,    45,   -69,    12,    -2,
       4,     4,     4,     4,     4,   -14,   -14,   -14,   -14,   -14,
     -14,   -14,   -14,   -14,   -14,   -14,   -14,   -14,   -69,   -69,
     -69,    -1,     0,   -69,    61,    48,    36,   -69,   -69,    19,
      19,    47,    47,    47,    47,    47,    47,   -69,   -69,   -69,
      34,    34,    44,    63,    63,   -69,     4,   -69,    50,    49,
     -69,    51,    61,    63,    52,    63,   -69,   -69,   -69
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     2,     4,     0,     0,     0,
       0,    39,    38,     0,     3,    12,    17,    16,    20,    21,
      35,    24,    31,    14,    15,     1,     0,     5,     0,     0,
       0,     0,     0,    42,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     6,    18,
      40,     0,     0,    19,    44,     0,    43,    13,    38,    22,
      23,    25,    27,    26,    28,    29,    30,    32,    33,    34,
      36,    37,     8,     0,     0,    41,     0,    10,     0,     9,
      46,     0,    45,     0,     0,     0,     7,    11,    47
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -69,   -69,   -69,    68,   -69,   -69,   -69,    -7,   -24,   -68,
     -69,   -69,    23,    14,     2,     5,   -69,   -69,   -69,   -69
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     5,     6,    72,    78,    79,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    55,    56,    23,    24
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      28,    29,    34,    34,    34,    80,    81,     8,    53,     7,
      57,     4,    11,    58,    13,    86,    34,    88,    49,    26,
      50,    73,    74,    51,    52,     8,    54,     9,    10,    25,
      11,    12,    13,    37,    38,    39,    40,    41,    42,    61,
      62,    63,    64,    65,    66,    43,    44,    45,    67,    68,
      69,     1,     2,    35,    36,    32,    46,    47,    59,    60,
      70,    71,    30,    31,    33,    34,    48,    76,     7,    82,
      75,    77,    83,    27,     0,     0,    85,     0,     0,    87,
      84
};

static const yytype_int8 yycheck[] =
{
       7,     8,     4,     4,     4,    73,    74,    21,    32,     5,
      34,     3,    26,    27,    28,    83,     4,    85,     6,    28,
      22,    22,    22,    30,    31,    21,    33,    23,    24,     0,
      26,    27,    28,    14,    15,    16,    17,    18,    19,    37,
      38,    39,    40,    41,    42,    11,    12,    13,    43,    44,
      45,    29,    30,     7,     8,    20,     9,    10,    35,    36,
      46,    47,    21,    21,    21,     4,    21,    31,     5,    76,
      22,    27,    22,     5,    -1,    -1,    25,    -1,    -1,    27,
      31
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    29,    30,    33,     3,    34,    35,     5,    21,    23,
      24,    26,    27,    28,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    50,    51,     0,    28,    35,    39,    39,
      21,    21,    20,    21,     4,     7,     8,    14,    15,    16,
      17,    18,    19,    11,    12,    13,     9,    10,    21,     6,
      22,    39,    39,    40,    39,    48,    49,    40,    27,    44,
      44,    46,    46,    46,    46,    46,    46,    47,    47,    47,
      45,    45,    36,    22,    22,    22,    31,    27,    37,    38,
      41,    41,    39,    22,    31,    25,    41,    27,    41
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    32,    33,    33,    34,    34,    36,    35,    37,    37,
      38,    38,    39,    39,    40,    40,    40,    40,    41,    42,
      42,    43,    43,    43,    44,    44,    44,    44,    44,    44,
      44,    45,    45,    45,    45,    46,    46,    46,    47,    47,
      47,    47,    48,    48,    49,    49,    50,    51
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     1,     2,     0,     7,     0,     1,
       1,     3,     1,     3,     1,     1,     1,     1,     3,     3,
       1,     1,     3,     3,     1,     3,     3,     3,     3,     3,
       3,     1,     3,     3,     3,     1,     3,     3,     1,     1,
       3,     4,     0,     1,     1,     3,     5,     7
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
  case 2: /* meta_start: START_PROGRAM program  */
#line 64 "ll.y"
                         {(yyval.start).prog.funs = p.funs;(yyval.start).prog.funsNr=p.funsNr;}
#line 1303 "y.tab.c"
    break;

  case 3: /* meta_start: START_STATEMENT main  */
#line 65 "ll.y"
                       {e=(yyvsp[0].expr);(yyval.start).expr = (yyvsp[0].expr);}
#line 1309 "y.tab.c"
    break;

  case 4: /* program: fundef  */
#line 69 "ll.y"
          {p.funs[p.funsNr++] = (yyvsp[0].funDef);}
#line 1315 "y.tab.c"
    break;

  case 5: /* program: program fundef  */
#line 70 "ll.y"
                  {p.funs[p.funsNr++]=(yyvsp[0].funDef);}
#line 1321 "y.tab.c"
    break;

  case 6: /* $@1: %empty  */
#line 74 "ll.y"
                  {paramsNr=0;params=malloc(10*sizeof(long int));}
#line 1327 "y.tab.c"
    break;

  case 7: /* fundef: TFUN TIDENT TLPAR $@1 params TRPAR block  */
#line 75 "ll.y"
  {(yyval.funDef).args = params; (yyval.funDef).argsNr = paramsNr; (yyval.funDef).name = (yyvsp[-5].id) ;(yyval.funDef).body = (yyvsp[0].expr);}
#line 1333 "y.tab.c"
    break;

  case 10: /* paramsLoop: TVAR  */
#line 84 "ll.y"
     {params[paramsNr++] = (yyvsp[0].nr);}
#line 1339 "y.tab.c"
    break;

  case 11: /* paramsLoop: paramsLoop ',' TVAR  */
#line 85 "ll.y"
                      {params[paramsNr++] = (yyvsp[0].nr);}
#line 1345 "y.tab.c"
    break;

  case 12: /* main: statement  */
#line 90 "ll.y"
            {(yyval.expr) = (yyvsp[0].expr);}
#line 1351 "y.tab.c"
    break;

  case 13: /* main: main TSEMICOLON statement  */
#line 91 "ll.y"
                            {(yyval.expr) = newSeqExpr((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 1357 "y.tab.c"
    break;

  case 14: /* statement: whileStat  */
#line 95 "ll.y"
            {(yyval.expr) = (yyvsp[0].expr);}
#line 1363 "y.tab.c"
    break;

  case 15: /* statement: ifStat  */
#line 96 "ll.y"
            {(yyval.expr) = (yyvsp[0].expr);}
#line 1369 "y.tab.c"
    break;

  case 16: /* statement: expr  */
#line 97 "ll.y"
            {(yyval.expr) = (yyvsp[0].expr);}
#line 1375 "y.tab.c"
    break;

  case 17: /* statement: block  */
#line 98 "ll.y"
            {(yyval.expr) = (yyvsp[0].expr);}
#line 1381 "y.tab.c"
    break;

  case 18: /* block: TLBRC main TRBRC  */
#line 102 "ll.y"
                   {(yyval.expr) = (yyvsp[-1].expr);}
#line 1387 "y.tab.c"
    break;

  case 19: /* expr: TVAR TASSIGN statement  */
#line 106 "ll.y"
                        {(yyval.expr) = newAssignExpr((yyvsp[-2].nr),(yyvsp[0].expr));}
#line 1393 "y.tab.c"
    break;

  case 20: /* expr: logicExpr  */
#line 107 "ll.y"
             {(yyval.expr) = (yyvsp[0].expr);}
#line 1399 "y.tab.c"
    break;

  case 21: /* logicExpr: cmpExpr  */
#line 111 "ll.y"
          {(yyval.expr) = (yyvsp[0].expr);}
#line 1405 "y.tab.c"
    break;

  case 22: /* logicExpr: logicExpr TOR cmpExpr  */
#line 112 "ll.y"
                         {(yyval.expr) = newOrExpr((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 1411 "y.tab.c"
    break;

  case 23: /* logicExpr: logicExpr TAND cmpExpr  */
#line 113 "ll.y"
                         {(yyval.expr) = newAndExpr((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 1417 "y.tab.c"
    break;

  case 24: /* cmpExpr: addExpr  */
#line 118 "ll.y"
           {(yyval.expr) = (yyvsp[0].expr);}
#line 1423 "y.tab.c"
    break;

  case 25: /* cmpExpr: cmpExpr TLE addExpr  */
#line 119 "ll.y"
                       {(yyval.expr) = newLeExpr((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 1429 "y.tab.c"
    break;

  case 26: /* cmpExpr: cmpExpr TGE addExpr  */
#line 120 "ll.y"
                       {(yyval.expr) = newGeExpr((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 1435 "y.tab.c"
    break;

  case 27: /* cmpExpr: cmpExpr TLT addExpr  */
#line 121 "ll.y"
                       {(yyval.expr) = newLtExpr((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 1441 "y.tab.c"
    break;

  case 28: /* cmpExpr: cmpExpr TGT addExpr  */
#line 122 "ll.y"
                       {(yyval.expr) = newGtExpr((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 1447 "y.tab.c"
    break;

  case 29: /* cmpExpr: cmpExpr TEQ addExpr  */
#line 123 "ll.y"
                       {(yyval.expr) = newEqExpr((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 1453 "y.tab.c"
    break;

  case 30: /* cmpExpr: cmpExpr TNEQ addExpr  */
#line 124 "ll.y"
                        {(yyval.expr) = newNeqExpr((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 1459 "y.tab.c"
    break;

  case 31: /* mulExpr: atom  */
#line 128 "ll.y"
        {(yyval.expr) = (yyvsp[0].expr);}
#line 1465 "y.tab.c"
    break;

  case 32: /* mulExpr: mulExpr TMUL atom  */
#line 129 "ll.y"
                     {(yyval.expr) = newMultExpr((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 1471 "y.tab.c"
    break;

  case 33: /* mulExpr: mulExpr TDIV atom  */
#line 130 "ll.y"
                     {(yyval.expr) = newDivExpr((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 1477 "y.tab.c"
    break;

  case 34: /* mulExpr: mulExpr TMOD atom  */
#line 131 "ll.y"
                     {(yyval.expr) = newModExpr((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 1483 "y.tab.c"
    break;

  case 35: /* addExpr: mulExpr  */
#line 136 "ll.y"
          {(yyval.expr) = (yyvsp[0].expr);}
#line 1489 "y.tab.c"
    break;

  case 36: /* addExpr: addExpr TADD mulExpr  */
#line 137 "ll.y"
                       {(yyval.expr) = newAddExpr((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 1495 "y.tab.c"
    break;

  case 37: /* addExpr: addExpr TSUB mulExpr  */
#line 138 "ll.y"
                       {(yyval.expr) = newSubExpr((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 1501 "y.tab.c"
    break;

  case 38: /* atom: TVAR  */
#line 143 "ll.y"
       {(yyval.expr) = newVariableExpr((yyvsp[0].nr));}
#line 1507 "y.tab.c"
    break;

  case 39: /* atom: TINTEGER  */
#line 144 "ll.y"
            {(yyval.expr) = newLiteralExpr((yyvsp[0].nr));}
#line 1513 "y.tab.c"
    break;

  case 40: /* atom: TLPAR main TRPAR  */
#line 145 "ll.y"
                    {(yyval.expr) = (yyvsp[-1].expr);}
#line 1519 "y.tab.c"
    break;

  case 41: /* atom: TIDENT TLPAR args TRPAR  */
#line 146 "ll.y"
                         {(yyval.expr) = newFunCallExpr((yyvsp[-3].id),(yyvsp[-1].funCall).args,(yyvsp[-1].funCall).argsNr);}
#line 1525 "y.tab.c"
    break;

  case 42: /* args: %empty  */
#line 151 "ll.y"
          {(yyval.funCall).argsNr=0;(yyval.funCall).args=malloc(1*sizeof(Expr*));}
#line 1531 "y.tab.c"
    break;

  case 43: /* args: argsLoop  */
#line 152 "ll.y"
           {(yyval.funCall) = (yyvsp[0].funCall);}
#line 1537 "y.tab.c"
    break;

  case 44: /* argsLoop: main  */
#line 156 "ll.y"
         {(yyval.funCall).args=malloc(10*sizeof(Expr*)); (yyval.funCall).args[(yyval.funCall).argsNr++] = (yyvsp[0].expr);}
#line 1543 "y.tab.c"
    break;

  case 45: /* argsLoop: argsLoop ',' main  */
#line 157 "ll.y"
                     {(yyval.funCall)=(yyvsp[-2].funCall); (yyval.funCall).args[(yyval.funCall).argsNr++] = (yyvsp[0].expr);}
#line 1549 "y.tab.c"
    break;

  case 46: /* whileStat: TWHILE TLPAR main TRPAR block  */
#line 161 "ll.y"
                                         {(yyval.expr) = newWhileExpr((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 1555 "y.tab.c"
    break;

  case 47: /* ifStat: TIF TLPAR main TRPAR block TELSE block  */
#line 164 "ll.y"
                                                {(yyval.expr) = newIfElseExpr((yyvsp[-4].expr),(yyvsp[-2].expr),(yyvsp[0].expr));}
#line 1561 "y.tab.c"
    break;


#line 1565 "y.tab.c"

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

#line 168 "ll.y"


 
void yyerror(const char *str)
{
        fprintf(stderr,"error: %s\n",str);
}
 
int yywrap()
{
        return 1;
} 

extern FILE *yyin;

#ifndef YY_TYPEDEF_YY_BUFFER_STATE
#define YY_TYPEDEF_YY_BUFFER_STATE
typedef struct yy_buffer_state *YY_BUFFER_STATE;
#endif
 
extern YY_BUFFER_STATE yy_scan_string ( const char *yy_str  );
extern void yy_delete_buffer(YY_BUFFER_STATE buffer);
int yylex_destroy ( void );

long int* env;

Program parseProgram(char* prog) {
  p.funsNr = 0;
  p.funs = malloc(100*sizeof(FunDef));
  env = malloc(100*sizeof(long int));

  FILE*  fh = fopen(prog, "r");
  printf("parsing file %s\n",prog);
  yyin = fh;
  start_token = START_PROGRAM;
  yyparse();
  //  Program result = {funs,funsNr};
  yylex_destroy();
  return p;
}


Program parseProgramStr(char* prog) {
  p.funsNr = 0;
  p.funs = malloc(100*sizeof(FunDef));
  env = malloc(100*sizeof(long int));
  YY_BUFFER_STATE buffer = yy_scan_string(prog);
  start_token = START_PROGRAM;
  yyparse();
  yy_delete_buffer(buffer);
  //Program result = {funs,funsNr};
  yylex_destroy();
  return p;
}


void createEnv() {
  p.funsNr = 0;
  p.funs = malloc(1*sizeof(FunDef));
  env = malloc(100*sizeof(long int));
}

void finishProgram(){
  int i;
  for (i=0;i<p.funsNr;i++){
    deleteExpr(p.funs[i].body);
    free(p.funs[i].name);
    free(p.funs[i].args);
  }
  free(p.funs);
  free(env);
}


long int evalString(char* str){
  YY_BUFFER_STATE buffer = yy_scan_string(str);

  start_token = START_STATEMENT;
  yyparse();
  yy_delete_buffer(buffer);
  int result = e?eval(e, env,p):-1;
  yylex_destroy();
  deleteExpr(e);
  return result;
}
