#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
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

struct cow {
  ll x, y;
};

struct edge {
  int l, r;
  ll w;
  edge(int l, int r, ll w) : l(l), r(r), w(w) {}
};

struct cmpEdge {
  bool operator()(edge const &e1, edge const &e2) { return e1.w > e2.w; }
};

bool cmp(cow a, cow b) { return a.x == b.x ? a.y < b.y : a.x < b.x; }

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

ll MAXX = 1000000;
int n;
cow a[100006];
// int c[1000006][11];

ll dist(cow a, cow b) {
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

ll bf() {
  ll res = 0;
  priority_queue<edge, vector<edge>, cmpEdge> edges;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      edges.push(edge(i, j, dist(a[i], a[j])));
    }
  }
  DSU dsu;
  dsu.build(n + 1);
  for (int i = 1; i <= n; i++) {
    dsu.make_set(i);
  }
  int cnt = 0;
  while (cnt < n - 1) {
    edge top = edges.top();
    edges.pop();
    if (dsu.find_set(top.l) != dsu.find_set(top.r)) {
      // cout << a[top.l].x << " " << a[top.l].y << " , " << a[top.r].x << " "
      // << a[top.r].y << "\n";
      dsu.union_sets(top.l, top.r);
      res += top.w;
      cnt++;
    }
  }

  return res;
}

ll solve() {
  ll res = 0;
  sort(a + 1, a + n + 1, cmp);

  vector<vector<int>> b;
  for (int i = 1; i <= n; i++) {
    if (i == 1 || (a[i].x != a[i - 1].x))
      b.pb(vector<int>(1, i));
    else
      b[b.size() - 1].pb(i);
  }

  priority_queue<edge, vector<edge>, cmpEdge> edges;

  int closest[11] = {0};

  for (int i = 0; i < int(b.size()); i++) {
    for (int j : b[i]) {
      for (int k = 0; k <= 10; k++) {
        if (closest[k] != 0) {
          edges.push(edge(j, closest[k], dist(a[j], a[closest[k]])));
        }
      }
    }
    for (int j = 1; j < int(b[i].size()); j++) {
      edges.push(edge(b[i][j], b[i][j - 1], dist(a[b[i][j]], a[b[i][j - 1]])));
    }
    for (int j : b[i]) {
      closest[a[j].y] = j;
    }
  }
  // for (int i=1;i<=n;i++) {
  //   for (int j=0;j<=10;j++) {
  //     if (closest[j] != 0) {
  //       edges.push(edge(i, closest[j], dist(a[i], a[closest[j]])));
  //     }
  //     closest[a[i].y] = i;
  //   }
  // }

  // cout << edges.size() << "\n";

  DSU dsu;
  dsu.build(n + 1);
  for (int i = 1; i <= n; i++) {
    dsu.make_set(i);
  }
  int cnt = 0;
  while (cnt < n - 1) {
    edge top = edges.top();
    edges.pop();
    if (dsu.find_set(top.l) != dsu.find_set(top.r)) {
      // cout << a[top.l].x << " " << a[top.l].y << " , " << a[top.r].x << " "
      // << a[top.r].y << "\n";
      dsu.union_sets(top.l, top.r);
      res += top.w;
      cnt++;
    }
  }
  return res;
}

void stress() {
  n = 10;
  random_device rd; // only used once to initialise (seed) engine
  mt19937 rng(
      rd()); // random-number engine used (Mersenne-Twister in this case)
  uniform_int_distribution<int> uni(0, 10); // guaranteed unbiased
  uniform_int_distribution<int> uni2(0, 1000000);

  for (int i = 1; i <= n; i++) {
    a[i].y = uni(rng);
    a[i].x = uni2(rng);
  }
  ll g = bf();
  ll b = solve();
  if (g != b) {
    cout << "got " << b << " watned " << g << "\n";
    for (int i=1;i<=n;i++) {
      cout << a[i].x << " " << a[i].y << "\n";
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // for (int i=0;i<100;i++) {
  //   stress();
  // }
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].x >> a[i].y;
  }
  cout << solve() << "\n";
  return 0;
}
