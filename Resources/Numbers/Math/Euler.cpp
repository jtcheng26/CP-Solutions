#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <cmath>

#define EPSILON 1e-9

using namespace std;

bool equal(double a, double b) {
  return abs(a - b) < EPSILON;
}

double dydx(double x, double y) {
  return asin(x*y);
}

double euler_method(double x, double y, double dx, double goal) {
  if (equal(x, goal)) return y;
  double dy_dx = dydx(x, y);
  double x2 = x + dx;
  double dy = dx * dy_dx;
  double y2 = y + dy;
  printf("(%0.3f, %0.3f%-10s%-10.3f%-10.3f%-10.3f(%0.3f, %0.3f%-10s\n", x, y, ")", dy_dx, dx, dy, x2, y2, ")");
  return euler_method(x2, y2, dx, goal);
}

int main() {
  double x1, y1, dx, goal;
  cout << "x1: " << "\n";
  cin >> x1;
  cout << "y1: " << "\n";
  cin >> y1;
  cout << "step: " << "\n";
  cin >> dx;
  cout << "goal x: " << "\n";
  cin >> goal;
  cout << setprecision(4);
  cout << euler_method(x1, y1, dx, goal) << "\n";
  return 0;
}
