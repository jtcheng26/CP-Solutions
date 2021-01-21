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
vector<pair<int, int> > ans;

void solve() {
  int d;
  if (n < 256) {
    if (n < 32)
      d = 2;
    else
      d = 4;
  } else {
    d = 16;
  }
  int k = n;
  for (int i=3;i<=n - 1;i++) {
    if (i == d) continue;
    ans.pb(mp(i, i + 1));
  }
  while (k > d) {
    k = (k + d - 1) / d;
    ans.pb(mp(n, d));
  }
  int s = d;
  if (d != 2) {
    while (d > 1) {
      d = (d + k - 1) / k;
      ans.pb(mp(s, n));
    }
  }
  while (k > 1) {
    k = (k + 1) / 2;
    ans.pb(mp(n, 2));
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ans.clear();
    cin >> n;
    solve();
    cout << ans.size() << "\n";
    for (int i=0;i<ans.size();i++) {
      cout << ans[i].F << " " << ans[i].S << "\n";
    }
  }
  return 0;
}
