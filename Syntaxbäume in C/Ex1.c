#include "SyntaxTree.h"
#include <stdio.h>

int main(){
  long int env[] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
  Program p = {NULL,0};

  Expr* e1  = newLiteralExpr(42);
  printf("%ld\n",eval(e1,env,p));
  deleteExpr(e1);
  
  Expr* e5 = newIfElseExpr(newGtExpr(newLiteralExpr(4),newLiteralExpr(0))
                          ,newLiteralExpr(42)
                          ,newDivExpr(newLiteralExpr(1),newLiteralExpr(0))); 
  printf("%ld\n",eval(e5,env,p));
  deleteExpr(e5);
}


