#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <iomanip>

#define INF 1000000001
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

int n;
double x, y;
double dx;

double dydx(double x, double y) {
  return y + dx * (sin(x) / x);
}

double euler_method(double x, double y, double dx, int iter) {
  if (iter == n) return y;
  double dy_dx = dydx(x, y);
  double x2 = x + dx;
  double y2 = dy_dx;
  //printf("(%0.3f, %0.3f%-10s%-10.3f%-10.3f%-10.3f(%0.3f, %0.3f%-10s\n", x, y, ")", dy_dx, dx, dy, x2, y2, ")");
  return euler_method(x2, y2, dx, iter + 1);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  //cout << fixed;
  //cout << setprecision(3);
  while (t--) {
    cin >> x >> y >> dx >> n;
    cout << round(euler_method(x, y, dx, 0) * 1000) / 1000 << "\n";
  }
  return 0;
}