/* Finding the diameter of a tree!
*/

// tree struct for finding distances and diameter
struct TreeDiameter {
  vector<int> adj[100001];
  int dist[100001];
  int n;
  int r;
  const int INF = 1000000007;
  void init(int num) { n = num; for (int i=1;i<=n;i++) adj[i].clear(); } // clear tree
  void add_edge(int a, int b) { adj[a].pb(b); adj[b].pb(a); } // add edge
  void findDists(int root) { // dfs distances
    r = root;
    for (int i=1;i<=n;i++) dist[i] = INF;
    dist[root] = 0;
    dfs(-1, root);
  }
  int getDist(int from, int to) { return dist[from] + dist[to]; } // distance between nodes
  int diameter() {
    int mxIdx = 0;
    for (int i=1;i<=n;i++) { if (dist[i] > dist[mxIdx]) mxIdx = i; } // get farthest node
    return dfs2(-1, mxIdx, 0); // get farthest node from farthest node (diameter)
  }
  int dfs2(int parent, int node, int d) {
    int res = d;
    for (int i=0;i<adj[node].size();i++) {
      int child = adj[node][i]; if (child == parent) continue;
      res = max(res, dfs2(node, child, d+1));
    }
    return res;
  }
  void dfs(int parent, int node) {
    for (int i=0;i<adj[node].size();i++) {
      int child = adj[node][i]; if (child == parent) continue;
      dist[child] = dist[node] + 1;
      dfs(node, child);
    }
  }
};
