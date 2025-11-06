#include "timestep.h"
#include <stdio.h>
#define NCELLS 10000000
static double H[NCELLS], U[NCELLS], V[NCELLS], dx[NCELLS], dy[NCELLS];
static int celltype[NCELLS];

int main(int argc, char *argv[]) {
  double g = 9.80, sigma = 0.95;
  double mymindt, mymindt1, mymindt2, mymindt3;
  for (int ic = 0; ic < NCELLS; ic++) {
    H[ic] = 10.0;
    U[ic] = 0.0;
    V[ic] = 0.0;
    dx[ic] = 0.5;
    dy[ic] = 0.5;
    celltype[ic] = REAL_CELL;
  }
  H[NCELLS / 2] = 20.0;

  mymindt = timestep(NCELLS, g, sigma, celltype, H, U, V, dx, dy);
  mymindt1 = timestep1(NCELLS, g, sigma, celltype, H, U, V, dx, dy);
  mymindt2 = timestep2(NCELLS, g, sigma, celltype, H, U, V, dx, dy);
  mymindt3 = timestep3(NCELLS, g, sigma, celltype, H, U, V, dx, dy);

  printf("Minimum dt is %lf\n", mymindt);
  printf("Minimum dt for timestep1 is %lf\n", mymindt1);
  printf("Minimum dt for timestep2 is %lf\n", mymindt2);
  printf("Minimum dt for timestep3 is %lf\n", mymindt3);
}
