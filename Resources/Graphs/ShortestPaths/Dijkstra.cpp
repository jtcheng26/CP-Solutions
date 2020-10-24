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
