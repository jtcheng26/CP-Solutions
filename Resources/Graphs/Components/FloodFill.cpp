/* Flood Fill alogrithm for finding components
  O(V + E)
  required
  - adj list
  - array to store component numbers
  notes
  - recursive is generally preferred, but it runs a risk of overflowing the stack size
  - that being said, remember to increase stack size when running large inputs locally
*/

// recursive approach (DFS)
void dfs(int comp, int node) {
  component[node] = comp;
  for (int i=0;i<adj[node].size();i++) {
    int child = adj[node][i];
    if (component[child] != comp) // add an && clause here depending on problem
      dfs(comp, child);
  }
}

void ff() {
  int comp = 1;
  for (int i=0;i<n;i++) {
    if (component[i] == -1)
      dfs(comp++, i);
  }
}

// iterative approach (BFS)
void ff() {
  queue<int> nodes;
  int comp = 1;
  for (int node=0;node<n;node++) {
    if (component[node] != -1) continue;
    nodes.push(node);
    while (nodes.size() > 0) {
      int u = nodes.front();
      nodes.pop_front();
      component[u] = comp;
      for (int i=0;i<adj[u].size();i++) {
        int child = adj[u][i];
        if (component[child] == comp) continue;
        q.push(child);
      }
    }
    comp++;
  }
}
