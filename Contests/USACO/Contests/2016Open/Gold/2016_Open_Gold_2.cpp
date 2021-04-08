#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INF 1000000001
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

struct DSU {
  vector<int> parent;
  vector<int> sz;
  void init(int n) {
    parent.resize(n+1);
    sz.resize(n+1);
    for (int i=1;i<=n;i++) {
      make_set(i);
    }
  }
  void make_set(int v) {
    parent[v] = v;
    sz[v] = 1;
  }
  int find_set(int v) {
    if (parent[v] == v) return v;
    return parent[v] = find_set(parent[v]);
  }
  void union_sets(int u, int v) {
    u = find_set(u);
    v = find_set(v);
    if (u != v) {
      if (sz[u] < sz[v]) swap(u, v);
      sz[u] += sz[v];
      parent[v] = u;
    }
  }
};

int n, m;
vector<int> adj[200001];
int q[200001];
bool ans[200001];

void solve() {
  DSU dsu;
  dsu.init(n);
  bool open[n+1];
  for (int i=1;i<=n;i++) open[i] = false;
  for (int i=n-1;i>=0;i--) {
    int u = q[i];
    open[u] = true;
    for (int neighbor : adj[u]) {
      if (open[neighbor])
        dsu.union_sets(u, neighbor);
    }
    //cout << u << " " << cnt << "\n";
    ans[i] = (dsu.sz[dsu.find_set(u)] == n - i);
  }
}

int main() {
  ofstream cout ("closing.out");
  ifstream cin ("closing.in");
  cin >> n >> m;
  for (int i=0;i<m;i++) {
    int u, v;
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  for (int i=0;i<n;i++) {
    cin >> q[i];
  }
  solve();
  for (int i=0;i<n;i++) {
    cout << (ans[i] ? "YES" : "NO") << "\n";
  }
  return 0;
}
