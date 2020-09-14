/* Dijkstra's shortest path algorithm
  O(E Log V)
  shortest path from source node to all other nodes (or terminate when found node)
  required:
  - adj list
  - distances array
  - visited array (booleans)
*/
struct Graph {
  int n;
  vector<int> adj[100001];
  const int INF = 1000000007;

  void init(int num) { n = num; for (int i=1;i<=n;i++) adj[i].clear(); } // clear tree
  void add_edge(int a, int b) { adj[a].pb(b); adj[b].pb(a); } // add edge
  
  void dijkstra(int root) {
    int dist[n]; bool visited[n];
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    for (int i=0;i<n;i++) {
      dist[i] = INFI; visited[i] = false;
      pair<int, int> p(dist[i], i);
      pq.push(p); // for some reason, initializing the pq with n values instead of just 1 drastically decreases runtime.
    }
    dist[root] = 0;
    pair<int, int> p(dist[root], i); pq.push(p);
    while (pq.size() > 0) {
      pair<int, int> u = pq.top(); pq.pop();
      int idx = u.second;
      if (visited[idx]) continue; visited[idx] = true;
      for (int i=0;i<adj[idx].size();i++) {
        int child = adj[idx][i]; if (visited[child]) continue;
        int d = dist[idx] + 1; // replace 1 w/ weight of edge
        if (dist[child] > d) dist[child] = d;
        pair<int, int> node(dist[child], child); pq.push(node);
      }
    }
  }
};
