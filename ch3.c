#include <stdlib.h>
#include <stdio.h>
#include <time.h>

double estimate_pi();

int main(int argc, char* argv[argc + 1]) {
  double pi = estimate_pi();
  printf("Pi: %f\n", pi);

  return EXIT_SUCCESS;
}

double estimate_pi() {
    int num_points_inside_circle = 0;
    int total_points = 10000000;

    srand(time(NULL));

    for (size_t i = 0; i < total_points; i++) {
        double x = (double)rand() / RAND_MAX;
        double y = (double)rand() / RAND_MAX;

        if (x * x + y * y <= 1) {
            num_points_inside_circle++;
        }
    }

    return 4.0 * (double)num_points_inside_circle / total_points;
}

