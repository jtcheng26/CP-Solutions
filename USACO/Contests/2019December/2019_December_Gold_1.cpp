#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>

#define mp make_pair
#define pb push_back
#define F first
#define S second

typedef long long ll;

using namespace std;

struct Graph {
  int n;
  vector<pair<int, int> > adj[1001];
  int edgeFlow[1001][1001];
  set<int> edgeFlows;
  const int INF = 1000000007;

  void init(int num) { n = num; for (int i=1;i<=n;i++) adj[i].clear(); } // clear tree
  void add_edge1(int a, int b, int c) {
    adj[a].pb(mp(c, b));
    adj[b].pb(mp(c, a));
   } // add edge
  void add_edge2(int a, int b, int c) { edgeFlow[a][b] = edgeFlow[b][a] = c; edgeFlows.insert(c); } // add edge

  int dijkstra(int root, int goal, int f) {
    int dist[1001]; bool visited[1001];
    for (int i=1;i<=n;i++) {
      dist[i] = INF; visited[i] = false;
    }
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    dist[root] = 0;
    pair<int, int> p(dist[root], root); pq.push(p);
    while (pq.size() > 0) {
      pair<int, int> u = pq.top(); pq.pop();
      int idx = u.second;
      if (visited[idx]) continue; visited[idx] = true;
      for (auto child : adj[idx]) {
        if (visited[child.second] || edgeFlow[idx][child.second] < f) continue;
        int d = dist[idx] + child.first; // replace 1 w/ weight of edge
        if (dist[child.second] > d) {
          dist[child.second] = d;
        }
        pair<int, int> node(dist[child.second], child.second); pq.push(node);
      }
    }
    return dist[goal];
  }
};

int n, m;
Graph g;

int solve() {
  set<int> edges = g.edgeFlows;
  double ans = 0;
  for (auto it=edges.begin();it!=edges.end();it++) {
    double f = (double) *it;
    double dist = (double) g.dijkstra(1, n, (int)f);
    if (dist >= 1000000007 || dist == 0) continue;
    cout << f << " " << dist << endl;
    ans = max(ans, f / dist);
  }
  return (int)(1000000 * (ans));
}

int main() {
  ofstream cout ("pump.out");
  ifstream cin ("pump.in");
  cin >> n >> m;
  g.init(n);
  for (int i=0;i<m;i++) {
    int u, v, c, f;
    cin >> u >> v >> c >> f;
    g.add_edge1(u, v, c);
    g.add_edge2(u, v, f);
  }
  cout << solve() << endl;
  return 0;
}
