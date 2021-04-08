#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INFI 1e18+7
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long ll;

using namespace std;

struct Graph {
  vector<int> adj[100001];
  int dist[100001];
  int n;
  int r;
  const int INF = 1000000007;
  void init(int num) {
    n = num;
    for (int i=1;i<=n;i++) adj[i].clear();
  }
  void add_edge(int a, int b) {
    adj[a].pb(b);
    adj[b].pb(a);
  }
  void findDists(int root) {
    r = root;
    for (int i=1;i<=n;i++) dist[i] = INF;
    dist[root] = 0;
    dfs(-1, root);
  }
  int getDist(int from, int to) {
    return dist[from] + dist[to];
  }
  int diameter() {
    int mxIdx = 0;
    for (int i=1;i<=n;i++) {
      if (dist[i] > dist[mxIdx])
        mxIdx = i;
    }
    return dfs2(-1, mxIdx, 0);
  }
  int dfs2(int parent, int node, int d) {
    int res = d;
    for (int i=0;i<adj[node].size();i++) {
      int child = adj[node][i];
      if (child == parent) continue;
      res = max(res, dfs2(node, child, d+1));
    }
    return res;
  }
  void dfs(int parent, int node) {
    for (int i=0;i<adj[node].size();i++) {
      int child = adj[node][i];
      if (child == parent) continue;
      dist[child] = dist[node] + 1;
      dfs(node, child);
    }
  }
};

int n, a, b, da, db;
Graph g;

bool solve() {
  bool bobWin = false;
  g.findDists(a);
  //cout << g.diameter() << endl;
  if (g.getDist(a, b) <= da) return false;
  if (g.diameter() <= 2 * da) return false;
  if (db > 2 * da) bobWin = true;
  return bobWin;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> a >> b >> da >> db;
    g.init(n);
    for (int i=0;i<n-1;i++) {
      int u, v;
      cin >> u >> v;
      g.add_edge(u, v);
    }
    cout << (solve() ? "Bob" : "Alice") << endl;
  }
  return 0;
}
