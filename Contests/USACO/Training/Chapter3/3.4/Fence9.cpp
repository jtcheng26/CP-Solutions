/*
   LANG: C++11
   PROG: fence9
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

#define mp make_pair
#define pb push_back
#define F first
#define S second

typedef long long ll;

using namespace std;

struct slope {
  int rise, run;
};

int n, m, p;

int solve() {
  int res;
  slope leftSlope;
  leftSlope.rise = m;
  leftSlope.run = n;
  slope rightSlope;
  rightSlope.rise = m;
  rightSlope.run = -1 * (p - n);
  int lbound = 0;
  int rbound = max(n, p);
  res = (rbound - 1) * (m - 1);
  int remove; // points outside of triangle to be removed
  // loop through x coordinates at every integer increment of y
  for (int i=1;i<m;i++) {
    remove = (leftSlope.run * i) / leftSlope.rise; // floored distance from origin
    //cout << remove << endl;
    res -= remove;
  }
  // other side
  for (int i=1;i<m;i++) {
    if (rightSlope.run <= 0)
      remove = -1 * ((rightSlope.run * i) / rightSlope.rise);
    else {
      remove = rbound - (p + (rightSlope.run * i + rightSlope.rise - 1) / rightSlope.rise);
    }
    //cout << remove << endl;
    res -= remove;
  }
  return res;
}

int main() {
  ofstream cout ("fence9.out");
  ifstream cin ("fence9.in");
  cin >> n >> m >> p;
  cout << solve() << endl;
  return 0;
}
