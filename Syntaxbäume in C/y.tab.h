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

#line 138 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
