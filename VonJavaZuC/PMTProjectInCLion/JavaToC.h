#ifndef JAVA_TO_C_H__
#define JAVA_TO_C_H__



int zufall();



int fGoTo(int x, int y, int n);


double kreisUmfang(double radius);

double kreisFlaeche(double radius);

void printDual(int i);


typedef struct{
  double real;
  double imag;
} Complex;


void printComplex(Complex c);


Complex add(Complex x,Complex y);
Complex sub(Complex x,Complex y);
Complex mult(Complex x,Complex y);
Complex divC(Complex x,Complex y);


double norm(Complex x);


unsigned int schwelle(Complex c,double schwellwert);

#endif

