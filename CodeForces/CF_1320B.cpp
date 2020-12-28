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
  vector<pair<int, int> > adj[200001]; // pair edge weight, node
  const int INF = 1000000007;
  int dist[200001];

  void init(int num) { n = num; for (int i=0;i<=n;i++) adj[i].clear(); } // clear tree
  void add_edge(int u, int v, int w) { adj[u].pb(mp(w, v)); } // add edge

  void dijkstra(int root) {
    bool visited[n];
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    for (int i=1;i<=n;i++) { dist[i] = INFI; visited[i] = false; }
    dist[root] = 0;
    pair<int, int> p(dist[root], root); pq.push(p);
    while (pq.size() > 0) {
      pair<int, int> u = pq.top(); pq.pop();
      int idx = u.second;
      if (visited[idx]) continue; visited[idx] = true;
      for (auto child : adj[idx]) {
        if (visited[child.second]) continue;
        int d = dist[idx] + child.first;
        if (dist[child.second] > d) dist[child.second] = d;
        pair<int, int> node(dist[child.second], child.second); pq.push(node);
      }
    }
  }
  int get_dist(int u) { return dist[u]; }
};

int n, m, k;
int path[200001];
vector<int> adj[200001];
Graph g;

pair<int, int> solve() {
  pair<int, int> res = mp(0, 0);
  g.dijkstra(path[k-1]);
  for (int i=0;i<k-1;i++) {
    int minDist = 1000000007;
    int minOccur = 0;
    for (int neighbor : adj[path[i]]) {
      if (g.get_dist(neighbor) < minDist) {
        minDist = g.get_dist(neighbor);
        minOccur = 1;
      } else if (g.get_dist(neighbor) == minDist) {
        minOccur++;
      }
    }
    //cout << minDist << "\n";
    if (minDist == g.get_dist(path[i+1])) {
      if (minOccur > 1) res.S++;
    } else {
      res.F++;
      res.S++;
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n >> m;
  g.init(n);
  for (int i=0;i<m;i++) {
    int u, v;
    cin >> u >> v;
    g.add_edge(v, u, 1);
    adj[u].pb(v);
  }
  cin >> k;
  for (int i=0;i<k;i++) cin >> path[i];
  pair<int, int> ans = solve();
  cout << ans.F << " " << ans.S << "\n";
  return 0;
}
