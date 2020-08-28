/*
  various simple depth-first search implementations.
  most of them are simple enough that it might be easier to manually implement
  but i guess it still doesn't hurt to have them here if i need them.
*/

/* pre-order dfs
  constructs an array of the nodes where each subtree is a subrange of the array (euler tour)
  required:
  - adj list (array of vectors)
  - array to store euler tour of tree
  - array of pairs to store start and end of subtrees
  - optional: array/map to store depth of nodes in tree
*/
int dfs(int parent, int root, int index) {
  if (root >= n) return index - 1;
  pre[index] = root;
  int og = index;
  for (int i=0;i<adj[root].size();i++) {
    int child = adj[root][i];
    if (child == parent) continue;
    depth[child] = depth[root] + 1;
    index = dfs(root, child, ++index);
  }
  rng[root] = mp(og, index);
  return index;
}
