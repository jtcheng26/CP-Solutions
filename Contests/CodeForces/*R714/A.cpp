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

int n, k;

vector<int> solve() {
  vector<int> res;
  if (k > (n - 1) / 2) return res;
  for (int i=1;i<=k;i++) {
    res.pb(i);
    res.pb(n - i + 1);
  }
  int j = k + 1;
  while (res.size() < n) {
    res.pb(j++);
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    vector<int> ans = solve();
    if (ans.empty()) {
      cout << "-1\n";
    } else {
      for (int a : ans) {
        cout << a << " ";
      }
      cout << "\n";
    }
  }
  return 0;
}