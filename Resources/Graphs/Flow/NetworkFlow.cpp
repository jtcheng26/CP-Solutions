/* Network Flow algorithm.
  Uses a modified Dijkstra's algorithm to find the maximum flow between the source and sink nodes.
  required:
  - adj list
  - edge weights (capacity)
  notes
  - with multiple edges between nodes in the same direction, sum up weights into one edge
  - initialize opposite flowing edges to 0 if they don't already exist
*/
struct FlowGraph {
  int n;
  vector<int> adj[100001];
  int cap[1000][1000]; // use map for larger graphs
  const int INF = 1000000007;

  void init(int num) { n = num; for (int i=1;i<=n;i++) adj[i].clear(); } // clear tree
  void add_edge(int a, int b) { adj[a].pb(b); adj[b].pb(a); } // add edge

  int netFlow(int source, int sink) {
    if (source == sink) return INF;
    int total = 0;
    int prev[n]; bool visited[n]; int flow[n]; // REMEMBER TO SET CORRECT ARRAY SIZES
    while (true) { // Djikstra
      for (int i=0;i<n;i++) {
        prev[i] = -1; flow[i] = 0; visited[i] = false;
      }
      flow[source] = INF;
      int maxFlow, maxLoc;
      while (true) {
        maxFlow = 0; maxLoc = -1;
        for (int i=0;i<n;i++) { // not sure how i could replace this step with a pq since flow changes dynamically.
          if (flow[i] > maxFlow && !visited[i]) {
            maxFlow = flow[i]; maxLoc = i;
          }
        }
        if (maxLoc == -1) break;
        if (maxLoc == sink) break;
        visited[maxLoc] = true;
        for (int i=0;i<adj[maxLoc].size();i++) {
          int child = adj[maxLoc][i];
          if (flow[child] < min(maxFlow, cap[maxLoc][child])) { // capacity = weight of edge
            prev[child] = maxLoc;
            flow[child] = min(maxFlow, cap[maxLoc][child]);
          }
        }
      } // End Djikstra
      if (maxLoc == -1) break; // no path found
      int pathCap = flow[sink];
      total += pathCap;
      // subtract flow from path
      int node = sink;
      while (node != source) {
        int nxt = prev[node];
        cap[nxt][node] -= pathCap;
        cap[node][nxt] += pathCap; // add flow to reverse direction
        node = nxt;
      }
    }
    return total; // total network flow
  }
};
