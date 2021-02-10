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
  vector<int> sz;
  vector<int> parent;
  void build(int n) {
    sz.resize(n);
    parent.resize(n);
  }
  void make_set(int v) {
    parent[v] = v;
    sz[v] = 1;
  }
  int find_set(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
  }
  void union_sets(int u, int v) {
    int a = find_set(u);
    int b = find_set(v);
    if (a != b) {
      if (sz[a] < sz[b]) swap(a, b);
      parent[b] = a;
      sz[a] += sz[b];
    }
  }
};

int n, m;
vector<int> adj[200001], ofParent[200001];
int ans[200001];
int parent[200001];
int color[200001];
queue<int> q;

void merge(int a, int b) {
  int pa = parent[a];
  int pb = parent[b];
  if (ofParent[pa].size() < ofParent[pb].size()) swap(pa, pb);
  for (int child : ofParent[pb]) {
    parent[child] = pa;
    ofParent[pa].pb(child);
  }
  ofParent[pb].clear();
  //adj[pa].insert(adj[pa].end(), adj[pb].begin(), adj[pb].end());
  for (int child : adj[pb])
    adj[pa].pb(child);
  adj[pb].clear();
  if (adj[pa].size() > 1) q.push(pa);
}

void solve() {
  for (int i=1;i<=n;i++) {
    parent[i] = i;
    ofParent[i].pb(i);
    if (adj[i].size() > 1) q.push(i);
  }
  while (!q.empty()) {
    int top = q.front();
    if (adj[top].size() <= 1) q.pop();
    else {
      int a = adj[top].back();
      adj[top].pop_back();
      if (parent[adj[top].back()] != parent[a]) {
        merge(a, adj[top].back());
      }
    }
  }
  int cnt = 1;
  for (int i=1;i<=n;i++) {
    int s = parent[i];
    if (color[s] == 0) {
      color[s] = cnt++;
    }
    ans[i] = color[s];
  }
}

int main() {
  ofstream cout ("fcolor.out");
  ifstream cin ("fcolor.in");
  cin >> n >> m;
  for (int i=0;i<m;i++) {
    int u, v;
    cin >> u >> v;
    adj[u].pb(v);
  }
  solve();
  for (int i=1;i<=n;i++) {
    cout << ans[i] << "\n";
  }
  return 0;
}
