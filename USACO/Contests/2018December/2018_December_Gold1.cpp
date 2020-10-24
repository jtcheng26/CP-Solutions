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

int ans[50001] = {0};

struct Graph {
  int n;
  vector<pair<int, int> > adj[50001];
  int yum[50001] = {0};
  vector<int> yums;
  const int INF = 1000000007;
  int dist[50001];
  int distk[50001];

  void init(int num) { n = num; for (int i=1;i<=n;i++) adj[i].clear(); } // clear tree
  //void add_edge(int a, int b) { adj[a].pb(b); adj[b].pb(a); } // add edge
  void add_edge(int a, int b, int w) { adj[a].pb(mp(w, b)); adj[b].pb(mp(w, a)); }
  void set_yum(int a, int y) { yum[a] = y; }
  int get_yum(int a) { return yum[a]; }
  vector<int> get_yums() { return yums; }
  void set_yums() {
    for (int i=0;i<n;i++) {
      if (yum[i] > 0)
        yums.pb(i);
    }
  }

  int get_dist(int node) {
    return dist[node];
  }
  int get_distk(int node) {
    return distk[node];
  }

  void dijkstra(int root) {
    bool visited[n];
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    for (int i=0;i<n;i++) {
      dist[i] = INF; visited[i] = false;
    }
    dist[root] = 0;
    pair<int, int> p(dist[root], root); pq.push(p);
    while (pq.size() > 0) {
      pair<int, int> u = pq.top(); pq.pop();
      int idx = u.second;
      if (visited[idx]) continue; visited[idx] = true;
      for (int i=0;i<adj[idx].size();i++) {
        int child = adj[idx][i].S; if (visited[child]) continue;
        int d = dist[idx] + adj[idx][i].F; // replace 1 w/ weight of edge
        if (dist[child] > d) {
          dist[child] = d;
        }
        pair<int, int> node(dist[child], child); pq.push(node);
      }
    }
  }
  void dijkstra2(int root) {
    bool visited[n];
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    for (int i=0;i<n;i++) {
      distk[i] = INF; visited[i] = false;
    }
    distk[root] = 0;
    int src = dist[root];
    pair<int, int> p(distk[root], root); pq.push(p);
    while (pq.size() > 0) {
      pair<int, int> u = pq.top(); pq.pop();
      int idx = u.second;
      ans[idx] = 1;
      if (visited[idx]) continue;
      visited[idx] = true;
      for (auto child : adj[idx]) {
        if (visited[child.S]) continue;
        int d = distk[idx] + child.F; // replace 1 w/ weight of edge
        if (distk[child.S] > d) {
          distk[child.S] = d;
        }
        pair<int, int> node(distk[child.S], child.S);
        if (distk[child.S] + src - dist[child.S] <= yum[root])
          pq.push(node);
      }
    }
  }
};

int n, m, k;
Graph g;

int solve() {
  int dist[n];
  g.dijkstra(n-1);
  for (int i=0;i<n;i++)
    dist[i] = g.get_dist(i);
  vector<int> yums = g.get_yums();
  for (int i=0;i<yums.size();i++) {
    g.dijkstra2(yums[i]);
  }
  return 0;
}

int main() {
  ofstream cout ("dining.out");
  ifstream cin ("dining.in");
  cin >> n >> m >> k;
  g.init(n);
  for (int i=0;i<m;i++) {
    int u, v, t;
    cin >> u >> v >> t;
    g.add_edge(u-1, v-1, t);
  }
  for (int i=0;i<k;i++) {
    int hay, yum;
    cin >> hay >> yum;
    if (yum > g.get_yum(hay-1))
      g.set_yum(hay-1, yum);
    ans[hay-1] = 1;
  }
  g.set_yums();
  solve();
  for (int i=0;i<n-1;i++) {
    cout << ans[i] << endl;
  }
  return 0;
}
