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

ll x, y, z;

bool solve() {
  if (x != y && y != z && x != z) return false;
  if (x == y && z > x) return false;
  if (y == z && x > y) return false;
  if (x == z && y > x) return false;
  if (x == y) x = min(y, z);
  if (y == z) y = min(x, y);
  if (x == z) x = min(z, y);
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> x >> y >> z;
    bool ans = solve();
    cout << (ans ?  "YES" : "NO") << endl;
    if (ans)
      cout << x << " " << y << " " << z << endl;
  }
  return 0;
}
