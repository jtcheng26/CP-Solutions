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

int x, y, x2, y2;

int solve() {
  int res = 0;
  if (x == x2) return abs(y2 - y);
  else if (y == y2) return abs(x2 - x);
  return abs(x2 - x) + abs(y2 - y) + 2;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> x >> y >> x2 >> y2;
    cout << solve() << endl;
  }
  return 0;
}
