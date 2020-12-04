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
  void add_edge(int u, int v, int w) { adj[u].pb(mp(w, v)); adj[v].pb(mp(w, u)); } // add edge

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

// All-pairs shortest paths in O(VE Log V)
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
