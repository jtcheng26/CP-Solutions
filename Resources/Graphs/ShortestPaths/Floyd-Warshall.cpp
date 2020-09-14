/* Floyd-Warshall shortest path algorithm
  O(V^3)
  Finds shortest paths between all nodes
  required:
  - adj matrix
  - if no edge, default to infinity
*/

// very simple, definitely faster to manually implement
void fw() {
  int dist[n][n];
  for (int i=0;i<n;i++)
  for (int j=0;j<n;j++)
    dist[i][j] = adj[i][j];
  for (int k=0;k<n;k++)
  for (int i=0;i<n;i++)
  for (int j=0;j<n;j++)
    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}
