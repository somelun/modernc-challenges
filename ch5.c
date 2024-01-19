#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <complex.h>

double derivative(double complex (*foo)(double complex), double complex x);

// void foo(double complex x);

int main(int argc, char* argv[argc + 1]) {
  double d = derivative(ccos, 1.0);
  printf("%lf\n", d);
  return EXIT_SUCCESS;
}

double derivative(double complex (*foo)(double complex), double complex x) {
  const double delta = 1.0e-9;

  double x1 = x - delta;
  double x2 = x + delta;

  double y1 = foo(x1);
  double y2 = foo(x2);

  return (y2 - y1) / (x2 - x1);
}

