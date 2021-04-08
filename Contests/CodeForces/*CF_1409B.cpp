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

ll a, b, x, y, n;

ll solve() {
  ll res = 0;
  if (a - x + b - y <= n) return x * y;
  ll p1;
  if (n >= a - x) {
    p1 = x * (b - (n - (a - x)));
  } else {
    p1 = b * (a - n);
  }
  ll p2;
  if (n >= b - y) {
    p2 = y * (a - (n - (b - y)));
  } else {
    p2 = a * (b - n);
  }
  return min(p1, p2);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> a >> b >> x >> y >> n;
    cout << solve() << endl;
  }
  return 0;
}
