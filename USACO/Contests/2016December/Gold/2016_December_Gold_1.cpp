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

struct edge {
  int u, v, w;
};

struct DSU {
  vector<int> sz;
  vector<int> parent;

  void build(int size) {
    sz.resize(size + 1);
    parent.resize(size + 1);
  }

  int find_set(int v) {
    if (v == parent[v])
      return v;
    return parent[v] = find_set(parent[v]);
  }

  void make_set(int v) {
    parent[v] = v;
    sz[v] = 1;
  }

  void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
      if (sz[a] < sz[b])
        swap(a, b);
      parent[b] = a;
      sz[a] += sz[b];
    }
  }
};

int n;
vector<edge> edges;

bool cmp(edge a, edge b) {
  return a.w < b.w;
}

int solve() {
  if (n == 1) return 0;
  DSU dsu;
  dsu.build(n);
  sort(edges.begin(), edges.end(), cmp);
  for (int i=0;i<n;i++) {
    dsu.make_set(i);
  }
  for (int i=0;i<edges.size();i++) {
    dsu.union_sets(edges[i].u, edges[i].v);
    if (dsu.sz[dsu.find_set(edges[i].u)] == n) return edges[i].w;
  }
  return 0;
}

int main() {
  ofstream cout ("moocast.out");
  ifstream cin ("moocast.in");
  cin >> n;
  pair<int, int> pts[n];
  for (int i=0;i<n;i++) {
    cin >> pts[i].F >> pts[i].S;
  }
  for (int i=0;i<n;i++) {
    for (int j=i+1;j<n;j++) {
      edge e;
      e.u = i;
      e.v = j;
      e.w = abs(pts[i].F - pts[j].F) * abs(pts[i].F - pts[j].F) + abs(pts[i].S - pts[j].S) * abs(pts[i].S - pts[j].S);
      edges.pb(e);
    }
  }
  cout << solve() << endl;
  return 0;
}
