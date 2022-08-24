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
char a[1001];

vector<int> solve() {
  vector<int> res;
  vector<int> cnt;
  vector<bool> good;
  for (int i=0;i<n;i++) {
    res.pb(a[i] - '0');
    if (a[i] == '0') {
      cnt.pb(i);
      good.pb(false);
    }
  }
  int j = 0;
  while (j < m) {
    bool changed = false;
    vector<int> temp;
    for (int r=0;r<cnt.size();r++) {
      if (good[r]) continue;
      int k = cnt[r];
      int l = 0;
      if (k > 0 && res[k-1] == 1) l++;
      if (k < n-1 && res[k+1] == 1) l++;
      if (l == 1) {
        changed = true;
        temp.pb(k);
        good[r] = true;
      }
    }
    for (int k : temp) {
      res[k] = 1;
    }
    if (!changed)
      break;
    j++;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i=0;i<n;i++) {
      cin >> a[i];
    }
    vector<int> ans = solve();
    for (int j : ans) {
      cout << j;
    }
    cout << "\n";
  }
  return 0;
}