#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INF 1000000001
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

int n, k;

vector<int> solve() {
  vector<int> res;
  vector<int> res2;
  for (int i=n;i>=1;i--) {
    if (i >= ((k+1) / 2) && i != k) {
      res.pb(i);
    }
  }
  int s = 0;
  for (int i=1;i<=n;i++) {
    if (s + i < k) {
      s += i;
      res2.pb(i);
    } else if (i > k) {
      res2.pb(i);
    }
  }
  if (res.size() > res2.size()) return res;
  return res2;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    vector<int> ans = solve();
    cout << ans.size() << "\n";
    for (int a : ans) {
      cout << a << " ";
    }
    cout << "\n";
  }
  return 0;
}
