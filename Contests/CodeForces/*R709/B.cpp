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

int n;
int a[100001];

vector<int> solve() {
  vector<int> res;
  if (n == 1) {
    res.pb(0);
    return res;
  }
  int i;
  for (i=2;i<n;i++) {
    if (!(a[i] - a[i-1] == a[1] - a[0])) {
      break;
    }
  }
  if (i == n) {
    res.pb(0);
    return res;
  } else {
    int c1 = -1;
    int c2 = -1;
    for (int i=1;i<n;i++) {
      if (c1 == -1) {
        c1 = a[i] - a[i-1];
      } else if (c2 == -1 && c1 != a[i] - a[i-1]) {
        c2 = a[i] - a[i-1];
      }
    }
    int m = abs(c1) + abs(c2);
    int c = -1;
    if (c == -1 && a[1] < a[0]) {
      c = a[1] + m - a[0];
    } else {
      c = a[1] - a[0];
    }
    for (int i=0;i<n;i++) {
      if (a[i] >= m) {
        res.pb(-1);
        return res;
      }
    }
    for (i=1;i<n;i++) {
      if ((a[i-1] + c) % m != a[i]) break;
    }
    if (i == n) {
      res.pb(m);
      res.pb(c);
      return res;
    }
  }
  res.pb(-1);
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    vector<int> ans = solve();
    for (int k : ans) {
      cout << k << " ";
    }
    cout << "\n";
  }
  return 0;
}
