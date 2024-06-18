#include "JavaToC.h"
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int zufall(){
    static int a = 21;
    static int c = 17;
    static int m = 100;
    static int x = 42;
    x = (a * x + c) % m;
    return x;
}

int f(int x, int y, int n){
  if (n<=0) return x;
  return  f(y, x+y,n-1);
}

int fGoTo(int x, int y, int n){
    start:
    if (n <= 0) return x;
    int temp = x;
    x = y;
    y = temp + y;
    n--;
    goto start;
}

double kreisUmfang(double radius){
    return 2 * M_PI * radius;
}
double kreisFlaeche(double radius){
    return M_PI * radius * radius;

}
void printDual(int i){
    for (int bit = sizeof(i) * 8 - 1; bit >= 0; --bit) putchar((i & (1 << bit)) ? '1' : '0');
    putchar('\n');
}

Complex add(Complex x, Complex y) {
    Complex result;
    result.real = x.real + y.real;
    result.imag = x.imag + y.imag;
    return result;
}

Complex sub(Complex x, Complex y) {
    Complex result;
    result.real = x.real - y.real;
    result.imag = x.imag - y.imag;
    return result;
}

Complex mult(Complex x, Complex y) {
    Complex result;
    result.real = x.real * y.real - x.imag * y.imag;
    result.imag = x.real * y.imag + x.imag * y.real;
    return result;
}

Complex divC(Complex x, Complex y) {
    Complex result;
    double det = y.real * y.real + y.imag * y.imag;
    result.real = (x.real * y.real + x.imag * y.imag) / det;
    result.imag = (x.imag * y.real - x.real * y.imag) / det;
    return result;
}

double norm(Complex x) {
    return x.real * x.real + x.imag * x.imag;
}

unsigned int schwelle(Complex c, double schwellwert) {
    Complex z = {0, 0};
    unsigned int n = 0;

    while (norm(z) <= schwellwert) {
        z = add(mult(z, z), c);
        n++;
    }

    return n;
}