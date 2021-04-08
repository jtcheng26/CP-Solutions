#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

#define mp make_pair
#define pb push_back
#define F first
#define S second

typedef long long ll;

using namespace std;

int n;
bool ans[100001];
vector<int> adj[100001];
vector<int> subtree[100001];

int dfs(int parent, int node) {
  int cnt = 0;
  for (int child : adj[node]) {
    if (child == parent) continue;
    int sz = dfs(node, child) + 1;
    cnt += sz;
    subtree[node].pb(sz);
  }
  if (cnt != n - 1) subtree[node].pb(n - cnt - 1);
  return cnt;
}

bool ok(int k) {
  map<int, int> cnt;
  for (int i=1;i<=n;i++) {
    int bad = 0;
    for (int sub : subtree[i]) {
      int len = sub % k;
      if (len == 0) continue;
      if (cnt[k - len] > 0) {
        cnt[k - len]--;
        bad--;
      } else {
        cnt[len]++;
        bad++;
      }
    }
    if (bad > 0) return 0;
  }
  return true;
}

void solve() {
  ans[1] = true;
  for (int i=2;i<=n-1;i++) {
    ans[i] = false;
  }
  vector<int> factors;
  for (int i=2;i<=sqrt(n-1);i++) {
    if ((n-1) % i == 0) {
      factors.pb(i);
      if (i * i != (n-1))
        factors.pb((n-1) / i);
    }
  }
  dfs(0, 1);
  for (int k : factors) {
    ans[k] = ok(k);
  }
}

int main() {
  ofstream cout ("deleg.out");
  ifstream cin ("deleg.in");
  cin >> n;
  for (int i=0;i<n-1;i++) {
    int u, v;
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  solve();
  for (int i=1;i<=n-1;i++) {
    cout << ans[i] << (i==n-1 ? "\n" : "");
  }
  return 0;
}
