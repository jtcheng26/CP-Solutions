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

int n, x, y;

pair<int, int> solve() {
  pair<int, int> res = mp(0, 0);
  if (x > y) swap(x, y);
  res.F = min(n, max(1, x + y - n + 1));
  res.S = min(n, y - 1 + x - 1 + 1);
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> x >> y;
    pair<int, int> ans = solve();
    cout << ans.F << " " << ans.S << "\n";
  }
  return 0;
}
