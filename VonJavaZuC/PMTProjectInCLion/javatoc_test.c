#include "JavaToC.h"
#include "CUnit.h"
#include <stdlib.h>

int main(){
  const char *ZUFALL1 = "zufall 1";
  const char *ZUFALL2 = "zufall 2";
  const char *ZUFALL3 = "zufall 3";
  const char *ZUFALL105 = "zufall 105";
  const char *FGOTO0 = "fGoTo 0";
  const char *FGOTO1 = "fGoTo 1";
  const char *FGOTO2 = "fGoTo 2";
  const char *FGOTO3 = "fGoTo 3";
  const char *KREISUMFANG1 = "kreisUmfang 1";
  const char *KREISFLAECHE = "kreisFlaeche";
  const char *COMPLADD1 = "complex add 1";
  const char *COMPLSUB1 = "complex sub 1";
  const char *COMPLMULT1 = "complex mult 1";
  const char *COMPLDIV1 = "complex div 1";
  const char *NORM1 = "norm 1";
  const char *NORM2 = "norm 2";
  const char *SCHWELLE1 = "schwelle 1";
  const char *SCHWELLE2 = "schwelle 2";

  testDeclare(ZUFALL1);
  testDeclare(ZUFALL2);
  testDeclare(ZUFALL3);
  testDeclare(ZUFALL105);
  testDeclare(FGOTO0);
  testDeclare(FGOTO1);
  testDeclare(FGOTO2);
  testDeclare(FGOTO3);
  testDeclare(KREISUMFANG1);
  testDeclare(KREISFLAECHE);
  testDeclare(COMPLADD1);
  testDeclare(COMPLSUB1);
  testDeclare(COMPLMULT1);
  testDeclare(COMPLDIV1);
  testDeclare(NORM1);
  testDeclare(NORM2);
  testDeclare(SCHWELLE1);
  testDeclare(SCHWELLE2);

  testStart(ZUFALL1);
  assertIntEq("zufall()",99,zufall());

  testStart(ZUFALL2);
  assertIntEq("zufall()",96,zufall());

  testStart(ZUFALL3);
  assertIntEq("zufall()",33,zufall());

  testStart(ZUFALL105);
  int i;
  for (i=0;i<100;i++)zufall();
  assertIntEq("zufall()",10,zufall());

  testStart(FGOTO0);
  assertIntEq("fGoTo(0,1,0)",0,fGoTo(0,1,0));

  testStart(FGOTO1);
  assertIntEq("fGoTo(0,1,5)",5,fGoTo(0,1,5));

  testStart(FGOTO2);
  assertIntEq("fGoTo(0,1,10)",55,fGoTo(0,1,10));

  testStart(FGOTO3);
  assertIntEq("fGoTo(0,1,40)",102334155,fGoTo(0,1,40));

  testStart(KREISUMFANG1);
  assertDoubleEq("kreisUmfang(10)",62.83185307179586231996,kreisUmfang(10));
  
  testStart(KREISFLAECHE);
  assertDoubleEq("kreisFlaeche(10)",314.15926535897932581065,kreisFlaeche(10));
  
  testStart(COMPLADD1);
  Complex c1 = {1,2};
  Complex c2 = {3,4};
  Complex c3 = add(c1,c2);
  assertDoubleEq("falscher Realanteil bei Addition",4,c3.real);
  assertDoubleEq("falscher Realanteil bei Addition",6,c3.imag);

  testStart(COMPLSUB1);
  c3 = sub(c1,c2);
  assertDoubleEq("falscher Realanteil bei Subtraktion",-2,c3.real);
  assertDoubleEq("falscher Realanteil bei Subtraktion",-2,c3.imag);

  testStart(COMPLMULT1);
  c3 = mult(c1,c2);
  assertDoubleEq("falscher Realanteil bei Multiplikation",-5,c3.real);
  assertDoubleEq("falscher Realanteil bei Multiplikation",10,c3.imag);

  testStart(COMPLDIV1);
  c3 = divC(c1,c2);
  assertDoubleEq("falscher Realanteil bei Division",0.44,c3.real);
  assertDoubleEq("falscher Realanteil bei Division",0.08,c3.imag);

  testStart(NORM1);
  assertDoubleEq("falsche Norm",5,norm(c1));

  testStart(NORM2);
  assertDoubleEq("falsche Norm",25,norm(c2));

  testStart(SCHWELLE1);
  assertDoubleEq("falsche schwelle",4,schwelle(c1,10679.78));

  testStart(SCHWELLE2);
  Complex c4 = {0.1,0.6};
  assertDoubleEq("falsche schwelle",2,schwelle(c4,0.5));
  
  printDual(42);
  printDual(-42);
  
  shutdown();
  return EXIT_SUCCESS;
}
