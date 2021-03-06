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
  vector<pair<int, int> > adj[100001]; // pair edge weight, node
  const int INF = 1000000007;
  int dist[100001];

  void init(int num) { n = num; for (int i=0;i<=n;i++) adj[i].clear(); } // clear tree
  void add_edge(int a, int b, int c) { adj[a].pb(mp(c, b)); adj[b].pb(mp(c, a)); } // add edge

  void dijkstra(int root) {
    bool visited[n];
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    for (int i=0;i<n;i++) { dist[i] = INFI; visited[i] = false; }
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


int n;
int poles[1001];
Graph g;

int solve() {
  g.init(n);
  for (int i=0;i<n;i++) {
    double mxSlope = -1 * INFI;
    for (int j=i+1;j<n;j++) {
      if ((poles[j] - poles[i]) / ((double)(j - i)) >= mxSlope) {
        g.add_edge(i, j, 1);
        //cout << i << " " << j << "\n";
        mxSlope = (poles[j] - poles[i]) / ((double)(j - i));
      }
    }
  }
  g.dijkstra(0);
  return g.get_dist(n-1) + 1;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  for (int i=0;i<n;i++) cin >> poles[i];
  cout << solve() << "\n";
  return 0;
}
