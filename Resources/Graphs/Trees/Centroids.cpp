/* Finding the 1 or 2 centroids in a tree
*/

struct TreeCentroids {
  int n;
  vector<int> adj[100001];
  int subtreeSize[100001];
  vector<int> centroids;
  void init(int num) { n = num; for (int i=1;i<=n;i++) adj[i].clear(); } // clear tree
  void add_edge(int a, int b) { adj[a].pb(b); adj[b].pb(a); } // add edge
  void dfs(int parent, int root) {
    if (root > n) return;
    bool cen = true;
    subtreeSize[root] = 1;
    for (int i=0;i<adj[root].size();i++) {
      int child = adj[root][i]; if (child == parent) continue;
      dfs(root, child);
      subtreeSize[root] += subtreeSize[child];
      if (subtreeSize[child] > n / 2) cen = false;
    }
    if (n - subtreeSize[root] > n / 2) cen = false;
    if (cen) centroids.pb(root);
  }
  vector<int> centroids() { if (centroids.size() == 0) dfs(0, 1); return centroids }
};
