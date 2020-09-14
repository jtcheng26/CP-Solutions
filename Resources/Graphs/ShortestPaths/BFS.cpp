/* Simple breadth-first search for shortest paths in an unweighted graph
*/

struct Graph {
  int n;
  vector<int> adj[100001];
  const int INF = 1000000007;

  void init(int num) { n = num; for (int i=1;i<=n;i++) adj[i].clear(); } // clear tree
  void add_edge(int a, int b) { adj[a].pb(b); adj[b].pb(a); } // add edge

  int bfs() {
    int dist[n];
    for (int i=0;i<n;i++) dist[i] = INF;
    queue<int> q;
    q.push(0); dist[0] = 0;
    while (!q.empty()) {
      int top = q.front(); q.pop();
      for (int child : adj[top]) {
        if (dist[top] + 1 < dist[child]) {
          dist[child] = dist[top] + 1;
          q.push(child);
        }
      }
    }
    return dist[n-1];
  }
};
