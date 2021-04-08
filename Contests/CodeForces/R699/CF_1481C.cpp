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

int n, m;
int a[100001];
int b[100001];
int c[100001];
int color[100001];
vector<int> occ[100001];
int curr[100001];

void resetAll() {
  for (int i=0;i<n;i++) {
    occ[b[i]].clear();
    curr[b[i]] = 0;
  }
  for (int i=0;i<m;i++) {
    occ[c[i]].clear();
    curr[c[i]] = 0;
  }
}

int solve() {
  int res = 0;
  int ok = -1;
  for (int i=0;i<n;i++) {
    if (a[i] != b[i])
      occ[b[i]].pb(i);
  }
  for (int i=0;i<n;i++) {
    if (a[i] == b[i])
      occ[b[i]].pb(i);
  }
  for (int i=m-1;i>=0;i--) {
    if (!occ[c[i]].empty()) {
      if (curr[c[i]] < occ[c[i]].size()) {
        color[i] = occ[c[i]][curr[c[i]]];
        if (ok == -1)
          ok = occ[c[i]][curr[c[i]]];
        a[occ[c[i]][curr[c[i]]]] = c[i];
        curr[c[i]]++;
      } else {
        color[i] = occ[c[i]][0];
        if (ok == -1)
          ok = occ[c[i]][0];
      }
    } else {
      if (ok != -1) {
        color[i] = ok;
      } else {
        return false;
      }
    }
  }
  for (int i=0;i<n;i++) {
    if (a[i] != b[i]) return false;
  }
  return true;
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
    for (int i=0;i<n;i++) {
      cin >> b[i];
    }
    for (int i=0;i<m;i++) {
      cin >> c[i];
    }
    resetAll();
    bool ans = solve();
    if (ans) {
      cout << "YES" << "\n";
      for (int i=0;i<m;i++) {
        cout << (color[i] + 1) << (i == m-1 ? "\n" : " ");
      }
    } else {
      cout << "NO" << "\n";
    }
  }
  return 0;
}
