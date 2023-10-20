#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double derivative(double (*foo)(double), double x);

int main(int argc, char* argv[argc + 1]) {
  double d = derivative(cos, 1.0);
  printf("%lf\n", d);
  return EXIT_SUCCESS;
}

double derivative(double (*foo)(double), double x) {
  const double delta = 1.0e-9;
  double x1 = x - delta;
  double x2 = x + delta;
  double y1 = foo(x1);
  double y2 = foo(x2);
  return (y2 - y1) / (x2 - x1);
}

