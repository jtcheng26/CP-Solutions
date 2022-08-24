#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

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

/*
p1. For each point, bfs S distance to each other point
p2. Find X component for each X
p3. For each X component, find minimum S distance to each other X component
p4. Using minimum S distances as edges, find minimum spanning tree of all
islands p5. Answer is sum of edge weights for the mst
*/

struct edge {
  pair<int, int> l, r;
  int w;
  edge(pair<int, int> l, pair<int, int> r, int w) : l(l), r(r), w(w) {}
};

struct cmpEdge {
  bool operator()(edge const &e1, edge const &e2) { return e1.w > e2.w; }
};

int r, c;
char a[56][56];
int dist[56][56][56][56];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void bfs(int i, int j, priority_queue<edge, vector<edge>, cmpEdge> &edges) {
  queue<pair<int, int>> q;
  q.push(mp(i, j));
  dist[i][j][i][j] = 1;
  while (!q.empty()) {
    pair<int, int> top = q.front();
    if (a[top.F][top.S] == 'X')
      edges.push(edge(mp(i, j), mp(top.F, top.S), dist[i][j][top.F][top.S]));
    q.pop();
    for (int d = 0; d < 4; d++) {
      int x = top.F + dx[d];
      int y = top.S + dy[d];
      if (x >= 0 && x < r && y >= 0 && y < r) {
        if (a[x][y] != '.' && dist[i][j][x][y] == 0) {
          if (a[x][y] == 'S')
            dist[i][j][x][y] = dist[i][j][top.F][top.S] + 1;
          else
            dist[i][j][x][y] = dist[i][j][top.F][top.S];
          q.push(mp(x, y));
        }
      }
    }
  }
}

int solve() {
  priority_queue<edge, vector<edge>, cmpEdge> edges;
  DSU dsu;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (a[i][j] == 'X') {
        bfs(i, j, edges);
      }
    }
  }
  dsu.build(r * c);
  for (int i=0;i<r*c;i++) {
    dsu.make_set(i);
  }
  int res = 0;
  while (!edges.empty()) {
    edge top = edges.top();
    int l = top.l.F * c + top.l.S;
    int r = top.r.F * c + top.r.S;
    if (a[top.l.F][top.l.S] == 'X' && a[top.r.F][top.r.S] == 'X' && dsu.find_set(l) != dsu.find_set(r)) {
      dsu.union_sets(l, r);
      res += top.w - 1;
      // cout << top.w << " " << top.l.F << " " << top.l.S << " " << top.r.F << " " << top.r.S << "\n";
    }
    edges.pop();
  }
  return res;
}

int main() {
  // ofstream cout("island.out");
  // ifstream cin("island.in");
  cin >> r >> c;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> a[i][j];
    }
  }
  cout << solve() << endl;
  return 0;
}
