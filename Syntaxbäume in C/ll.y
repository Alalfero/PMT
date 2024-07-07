%{
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

 
%}

%token TFUN TSEMICOLON TLBRC TRBRC TOR TAND TADD TSUB TMUL TDIV TMOD TLE TLT TGE TGT TEQ TNEQ TASSIGN TLPAR TRPAR TWHILE TIF TELSE  

%token <nr> TINTEGER TVAR
%token <id> TIDENT


%type<prog> program
%type<start> meta_start
%type<funDef> fundef

%type<expr> block statement main expr logicExpr cmpExpr mulExpr addExpr atom whileStat ifStat

%type<funCall> args argsLoop

%token START_PROGRAM
%token START_STATEMENT

%start meta_start


%union{
  long int nr;
  long int* params;
  Expr* expr;
  FunDef funDef;
  FunCallExpr funCall;
  Program prog;
  char* id;
  ParseResult start;
}

%%

meta_start:
  START_PROGRAM program  {$$.prog.funs = p.funs;$$.prog.funsNr=p.funsNr;}
| START_STATEMENT main {e=$2;$$.expr = $2;}
;

program :
   fundef {p.funs[p.funsNr++] = $1;}
  |program fundef {p.funs[p.funsNr++]=$2;}
;

fundef :
TFUN TIDENT TLPAR {paramsNr=0;params=malloc(10*sizeof(long int));} params TRPAR block
  {$$.args = params; $$.argsNr = paramsNr; $$.name = $2 ;$$.body = $7;}
;

params:
    %empty
    | paramsLoop
    ;

paramsLoop:
TVAR {params[paramsNr++] = $1;}
 |paramsLoop ',' TVAR {params[paramsNr++] = $3;}
;


main:
  statement {$$ = $1;}
 |main TSEMICOLON statement {$$ = newSeqExpr($1,$3);}
;

statement:
  whileStat {$$ = $1;}
 |ifStat    {$$ = $1;}
 |expr      {$$ = $1;}
 |block     {$$ = $1;}
;

block:
  TLBRC main TRBRC {$$ = $2;}
  ;

expr:
TVAR TASSIGN statement  {$$ = newAssignExpr($1,$3);}
  |logicExpr {$$ = $1;}
;

logicExpr:
  cmpExpr {$$ = $1;}
 |logicExpr TOR cmpExpr  {$$ = newOrExpr($1,$3);}
 |logicExpr TAND cmpExpr {$$ = newAndExpr($1,$3);}
 
;

cmpExpr:
   addExpr {$$ = $1;}
  |cmpExpr TLE addExpr {$$ = newLeExpr($1,$3);}
  |cmpExpr TGE addExpr {$$ = newGeExpr($1,$3);}
  |cmpExpr TLT addExpr {$$ = newLtExpr($1,$3);}
  |cmpExpr TGT addExpr {$$ = newGtExpr($1,$3);}
  |cmpExpr TEQ addExpr {$$ = newEqExpr($1,$3);}
  |cmpExpr TNEQ addExpr {$$ = newNeqExpr($1,$3);}
;

mulExpr:
   atom {$$ = $1;}
  |mulExpr TMUL atom {$$ = newMultExpr($1,$3);}
  |mulExpr TDIV atom {$$ = newDivExpr($1,$3);}
  |mulExpr TMOD atom {$$ = newModExpr($1,$3);}
;


addExpr:
  mulExpr {$$ = $1;}
 |addExpr TADD mulExpr {$$ = newAddExpr($1,$3);}
 |addExpr TSUB mulExpr {$$ = newSubExpr($1,$3);}
;


atom:
  TVAR {$$ = newVariableExpr($1);}
  |TINTEGER {$$ = newLiteralExpr($1);}
  |TLPAR main TRPAR {$$ = $2;}
|TIDENT TLPAR args TRPAR {$$ = newFunCallExpr($1,$3.args,$3.argsNr);}
;


args:
  %empty  {$$.argsNr=0;$$.args=malloc(1*sizeof(Expr*));}
| argsLoop {$$ = $1;}
 ;

argsLoop:
    main {$$.args=malloc(10*sizeof(Expr*)); $$.args[$$.argsNr++] = $1;}
  |argsLoop ',' main {$$=$1; $$.args[$$.argsNr++] = $3;}
;


whileStat: TWHILE TLPAR main TRPAR block {$$ = newWhileExpr($3,$5);}
;

ifStat: TIF TLPAR main TRPAR block TELSE  block {$$ = newIfElseExpr($3,$5,$7);}
;


%%

 
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
