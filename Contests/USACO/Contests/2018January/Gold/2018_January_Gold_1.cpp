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

struct query {
  int idx, v, k;
};

struct edge {
  int l, r, w;
};

struct DSU {
  vector<int> sz;
  vector<int> parent;
  void build(int n) {
    sz.resize(n + 1);
    parent.resize(n + 1);
  }
  int find_set(int v) {
    if (parent[v] == v) return v;
    return parent[v] = find_set(parent[v]);
  }
  void make_set(int v) {
    parent[v] = v;
    sz[v] = 1;
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

int n, q;
edge edges[100001];
query queries[100001];
int ans[100001];

bool cmpEdges(edge a, edge b) {
  return a.w > b.w;
}

bool cmpQueries(query a, query b) {
  return a.k > b.k;
}

void solve() {
  sort(edges, edges + n - 1, cmpEdges);
  sort(queries, queries + q, cmpQueries);
  DSU dsu;
  dsu.build(n);
  for (int i=1;i<=n;i++) {
    dsu.make_set(i);
  }
  int j = 0;
  for (int i=0;i<q;i++) {
    while (j < n - 1 && edges[j].w >= queries[i].k) {
      dsu.union_sets(edges[j].l, edges[j].r);
      j++;
    }
    ans[queries[i].idx] = dsu.sz[dsu.find_set(queries[i].v)] - 1;
  }
}

int main() {
  ofstream cout ("mootube.out");
  ifstream cin ("mootube.in");
  cin >> n >> q;
  for (int i=0;i<n-1;i++) {
    cin >> edges[i].l >> edges[i].r >> edges[i].w;
  }
  for (int i=0;i<q;i++) {
    cin >> queries[i].k >> queries[i].v;
    queries[i].idx = i;
  }
  solve();
  for (int i=0;i<q;i++) {
    cout << ans[i] << "\n";
  }
  return 0;
}
