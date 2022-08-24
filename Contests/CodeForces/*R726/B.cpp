#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>

#define INF 1000000001
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

int n, m;
int x, y;

pair<pair<int, int>, pair<int, int> > solve() {
  pair<int, int> a;
  pair<int, int> b;
  a.F = 1;
  a.S = 1;
  b.F = n;
  b.S = m;
  return mp(a, b);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m >> x >> y;
    pair<pair<int, int>, pair<int, int> > res = solve();
    cout << res.F.F << " " << res.F.S << " " << res.S.F << " " << res.S.S << "\n";
  }
  return 0;
}