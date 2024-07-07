%{
#include <stdio.h>
#include <string.h>
#include "SyntaxTree.h"
#include "MemoryTest.h"
#include "y.tab.h"
extern YYSTYPE yylval;

extern int start_token;
%}

%%
%{
  if (start_token)
    {
      int t = start_token;
      start_token = 0;
      return t;
    }
%}


"while" return TWHILE;
"if" return TIF;
"else" return TELSE;
"fun" return TFUN;
\; return TSEMICOLON;
\{ return TLBRC;
\} return TRBRC;
"||" return TOR;
"&&" return TAND;
"+" return TADD;
"-" return TSUB;
"*" return TMUL;
"/" return TDIV;
"%" return TMOD;
"<=" return TLE;
"<" return TLT;
">=" return TGE;
">" return TGT;
"==" return TEQ;
"!=" return TNEQ;
"=" return TASSIGN;
"(" return TLPAR;
")" return TRPAR;
[0-9]+ {
  yylval.nr = atoi(yytext);
  return TINTEGER;
}


X[0-9]([0-9])?  {
yylval.nr = yytext[1]-'0';
if (strlen(yytext)>2){
yylval.nr = yylval.nr*10+(yytext[2]-'0');

}
return TVAR;
}

[a-zA-Z]([a-zA-Z0-9])* {
     yylval.id = strdup(yytext);
   //  speicherAlloc++;
     return TIDENT;      
}
 

[ \t]+                  /* ignore whitespace */;
%%
