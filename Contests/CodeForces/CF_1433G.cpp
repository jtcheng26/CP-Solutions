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
  int n;
  vector<pair<int, int> > adj[1001]; // pair edge weight, node
  const int INF = 1000000007;
  int dist[1001][1001];

  void init(int num) { n = num; for (int i=0;i<=n;i++) adj[i].clear(); } // clear tree
  void add_edge(int u, int v, int w) { adj[u].pb(mp(w, v)); adj[v].pb(mp(w, u)); } // add edge

  void dijkstra(int root) {
    bool visited[n];
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    for (int i=0;i<n;i++) { dist[root][i] = INF; visited[i] = false; }
    dist[root][root] = 0;
    pair<int, int> p(dist[root][root], root); pq.push(p);
    while (pq.size() > 0) {
      pair<int, int> u = pq.top(); pq.pop();
      int idx = u.second;
      if (visited[idx]) continue; visited[idx] = true;
      for (auto child : adj[idx]) {
        if (visited[child.second]) continue;
        int d = dist[root][idx] + child.first;
        if (dist[root][child.second] > d) dist[root][child.second] = d;
        pair<int, int> node(dist[root][child.second], child.second); pq.push(node);
      }
    }
  }
  void allPairsDijkstra() {
    for (int i=0;i<n;i++) {
      dijkstra(i);
    }
  }
  int get_dist(int u, int v) { return dist[u][v]; }
};

struct route {
  int a, b;
};

int n, m, k;
Graph g;
route routes[1001];
pair<int, int> edges[1001];

int solve() {
  int res = g.INF;
  g.allPairsDijkstra();
  for (int i=0;i<m;i++) {
    int sum = 0;
    int l = edges[i].F;
    int r = edges[i].S;
    for (int j=0;j<k;j++) {
      int start = routes[j].a;
      int end = routes[j].b;
      sum += min(g.get_dist(start, end), min(g.get_dist(start, l) + g.get_dist(end, r), g.get_dist(end, l) + g.get_dist(start, r)));
    }
    res = min(res, sum);
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n >> m >> k;
  g.init(n);
  for (int i=0;i<m;i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g.add_edge(u-1, v-1, w);
    edges[i] = mp(u-1, v-1);
  }
  for (int i=0;i<k;i++) {
    cin >> routes[i].a >> routes[i].b;
    routes[i].a--;
    routes[i].b--;
  }
  cout << solve() << "\n";
  return 0;
}
