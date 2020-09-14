#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INFI 1e18+7
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long ll;

using namespace std;

int n;
int loc[2];
int a, b, c, d;
int xLeft, yBot, xRight, yTop;

int solve() {
  int res = 0;
  if (xRight == xLeft && (a >= 1 || b >= 1)) return false;
  if (yTop == yBot && (c >= 1 || d >= 1)) return false;
  if (a > b) {
    a -= b;
    b = 0;
  } else {
    b -= a;
    a = 0;
  }
  if (c > d) {
    c -= d;
    d = 0;
  } else {
    d -= c;
    c = 0;
  }
  return (loc[0] - a >= xLeft && b + loc[0] <= xRight && loc[1] - c >= yBot && d + loc[1] <= yTop);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> a >> b >> c >> d;
    cin >> loc[0] >> loc[1] >> xLeft >> yBot >> xRight >> yTop;
    cout << (solve() ? "Yes" : "No") << endl;
  }
  return 0;
}
