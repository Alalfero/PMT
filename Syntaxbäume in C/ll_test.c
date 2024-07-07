#include "CUnit.h"
#include "SyntaxTree.h"
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"
#include "MemoryTest.h"

extern long int evalString(char* str);
extern Program parseProgramStr(char* prog);
extern void finishProgram();
extern void createEnv();

void testProg(char* testName, char* prog,char* expr,long int expected){
  testStart(testName);
  parseProgramStr(prog);
  long int result = evalString(expr);
  assertIntEq("evaluiert zum falschen Ergebnis.",expected,result);
  finishProgram();
}

void testExpr(char* testName, char* expr,long int expected){
  testStart(testName);
  createEnv();
  long int result = evalString(expr);
  assertIntEq("evaluiert zum falschen Ergebnis.",expected,result);
  finishProgram();
}


int main(){
  long int env [] = {0,0,0,0,0,0,0,0,0,0,0};

  const char *TEST1 = "Test 1";
  const char *TEST2 = "Test 2";
  const char *TEST3 = "Test 3";
  const char *TEST4 = "Test 4";
  const char *TEST5 = "Test 5";
  const char *TEST6 = "Test 6";
  const char *EXPR1 = "1+1";
  const char *EXPR2 = "17+4*2";
  const char *EXPR3 = "(17+4)*2";
  const char *EXPR4 = "X1=1;X2=5;while(X2){X1=X1*X2;X2=X2-1};X1";
  const char *PROG1 = "fac(5)";
  const char *PROG2 = "fib(7)";
  const char *PROG3 = "facIt(7)";

  testDeclare(TEST1);
  testDeclare(TEST2);
  testDeclare(TEST3);
  testDeclare(TEST4);
  testDeclare(TEST5);
  testDeclare(TEST6);
  testDeclare(EXPR1);
  testDeclare(EXPR2);
  testDeclare(EXPR3);
  testDeclare(EXPR4);
  testDeclare(PROG1);
  testDeclare(PROG2);
  testDeclare(PROG3);


  testStart(TEST1);
  Expr* e1  = newLiteralExpr(42);
  Program p = {NULL,0};
  assertIntEq("Literal 42 evaluiert zum falschen Ergebnis.",42,eval(e1,env,p));
  deleteExpr(e1);

  testStart(TEST2);
  Expr* e2 = newMultExpr(newLiteralExpr(2),newAddExpr(newLiteralExpr(17),newLiteralExpr(4)));
  assertIntEq("Addition mit Multiplikation von (2*(17+4)) evaluiert zum falschen Ergebnis.",42,eval(e2,env,p));
  deleteExpr(e2);
  
  testStart(TEST3);
  Expr* e3
    = newSeqExpr
    (newAssignExpr(0,newAddExpr(newLiteralExpr(17),newLiteralExpr(4)))
    ,newMultExpr(newVariableExpr(0),newLiteralExpr(2)));

  assertIntEq("Assigment und Variablenzugriff fürt zum falschen Ergebnis. x0 = 17 +4; return x0*2",42,eval(e3,env,p));
  deleteExpr(e3);

  testStart(TEST4);

  Expr* e4 = 
    newSeqExpr(newAssignExpr(0,newLiteralExpr(1))
	       ,newSeqExpr(newAssignExpr(1,newLiteralExpr(5))
			   ,newSeqExpr(
				       newWhileExpr(newGeExpr(newVariableExpr(1),newLiteralExpr(1))
						    ,newSeqExpr(newAssignExpr(0,newMultExpr(newVariableExpr(0),newVariableExpr(1))),newAssignExpr(1,newSubExpr(newVariableExpr(1),newLiteralExpr(1)))))
				       ,newVariableExpr(0))));

  assertIntEq("While zur Fakultät funktioniert nicht: x0 = 1; x1 = 5; while(x1>=1){x0=x0*x1;x1=x1-1;};return x0",120,eval(e4,env,p));
  deleteExpr(e4);

  testStart(TEST5);
  Expr* e5 = newIfElseExpr(newGtExpr(newLiteralExpr(4),newLiteralExpr(0)),newLiteralExpr(42),newDivExpr(newLiteralExpr(1),newLiteralExpr(0)));
  assertIntEq("Fehler bei if Ausdruck für: if (4>1) 42 else (1/0);",42,eval(e5,env,p));
  deleteExpr(e5);

  testStart(TEST6);
  Expr* e6 = newOrExpr(newGtExpr(newLiteralExpr(4),newLiteralExpr(0)),newDivExpr(newLiteralExpr(1),newLiteralExpr(0))); 
  assertIntEq("Fehler bei Or Ausdruck für: 4>0 || (1/0);",1,eval(e6,env,p));
  deleteExpr(e6);

  testExpr(EXPR1,"1+1",2);
  testExpr(EXPR2,"17+4*2",25);
  testExpr(EXPR3,"(17+4)*2",42);
  testExpr(EXPR4,"X1=1;X2=5;while(X2){X1=X1*X2;X2=X2-1};X1",120);

  testProg(PROG1,"fun fac(X1){if(X1<=1){1}else{X1*fac(X1-1)}}","fac(5)",120);
  testProg(PROG2,"fun fib(X1){if(X1<=1){X1}else{fib(X1-2)+fib(X1-1)}}","fib(7)",13);
  testProg(PROG3,"fun facIt(X2){X1=1;while(X2){X1=X1*X2;X2=X2-1};X1}","facIt(7)",5040);
  
  shutdown();
  return EXIT_SUCCESS;
}
