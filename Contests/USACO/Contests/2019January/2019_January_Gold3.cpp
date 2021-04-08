#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define mp make_pair
#define pb push_back
#define F first
#define S second

typedef long long ll;

using namespace std;

int cows[10001];

struct Graph {
  int n;
  vector<pair<int, int> > adj[100001]; // pair edge weight, node
  vector<int> adj2[100001];
  const int INF = 1000000007;
  int dist[100001];
  bool deleted[100001];
  int parent[100001];
  int subtreeCows[100001];
  bool visited[100001];

  void init(int num) { n = num; for (int i=0;i<=n;i++) { adj[i].clear(); deleted[i] = false; } } // clear tree
  void add_edge(int a, int b, int c) { adj[a].pb(mp(c, b)); adj[b].pb(mp(c, a)); } // add edge

  void dijkstra(int root) {
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    for (int i=1;i<=n;i++) { dist[i] = INF; visited[i] = false; parent[i] = -1; subtreeCows[i] = 0;}
    dist[root] = 0;
    pair<int, int> p(dist[root], root); pq.push(p);
    while (pq.size() > 0) {
      pair<int, int> u = pq.top(); pq.pop();
      int idx = u.second;
      if (visited[idx]) continue; visited[idx] = true;
      for (auto child : adj[idx]) {
        if (visited[child.second]) continue;
        int d = dist[idx] + child.first;
        if (dist[child.second] > d) {
          dist[child.second] = d;
          parent[child.second] = idx;
        }
        else if (dist[child.second] == d) {
          if (idx < parent[child.second])
            parent[child.second] = idx;
        }
        pair<int, int> node(dist[child.second], child.second); pq.push(node);
      }
    }
    for (int i=1;i<=n;i++) { visited[i] = false;}
  }
  int get_dist(int u) { return dist[u]; }

  int dfs(int parent, int node) {
    int cnt = cows[node];
    for (int child : adj2[node]) {
      if (child == parent) continue;
      cnt += dfs(node, child);
    }
    subtreeCows[node] = cnt;
    return cnt;
  }

  ll solve(int t) {
    dijkstra(1);
    ll res = 0;
    for (int i=2;i<=n;i++) {
      //cout << "node " << i << "\n";
      adj2[i].pb(parent[i]);
      adj2[parent[i]].pb(i);
      //cout << i << " " << subtreeCows[i] << "\n";
    }
    dfs(-1, 1);
    for (int i=2;i<=n;i++) {
      //cout << "node " << i << " count " << subtreeCows[i] << "\n";
      res = max(res, (ll)subtreeCows[i] * ((ll)(get_dist(i) - t)));
    }
    return res;
  }

};


int n, m, t;
Graph g;

ll solve() {
  return g.solve(t);
}

int main() {
  ofstream cout ("shortcut.out");
  ifstream cin ("shortcut.in");
  cin >> n >> m >> t;
  for (int i=1;i<=n;i++) {
    cin >> cows[i];
  }
  g.init(n);
  for (int i=0;i<m;i++) {
    int u, v, d;
    cin >> u >> v >> d;
    g.add_edge(u, v, d);
  }
  cout << solve() << endl;
  return 0;
}
