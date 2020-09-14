/* Tree traversal/euler tour notation
*/

/* pre-order traversal dfs
  constructs an array of the nodes where each subtree is a subrange of the array (euler tour)
*/
struct TreeTraversal {
  vector<int> adj[100001];
  pair<int, int> rng[100001]; // subtree ranges for each node
  int depth[100001]; // depth of nodes (with respect to root)
  int pre[100001]; // pre-order
  int dfs(int parent, int root, int index) {
    if (root >= n) return index - 1;
    pre[index] = root; // switch this line around to do other traversals (in-order, post-order, etc.)
    int og = index;
    for (int i=0;i<adj[root].size();i++) {
      int child = adj[root][i]; if (child == parent) continue;
      depth[child] = depth[root] + 1;
      index = dfs(root, child, ++index);
    }
    rng[root] = mp(og, index);
    return index;
  }
};
