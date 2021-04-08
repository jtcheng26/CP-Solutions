#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INFI 1e18+7
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long ll;

using namespace std;

struct FlowGraph {
  int n;
  vector<int> adj[10];
  int cap[10][10]; // use map for larger graphs
  const int INF = 1000000007;

  void init(int num) { n = num; for (int i=1;i<=n;i++) adj[i].clear(); } // clear tree
  void add_edge(int a, int b, int c) { adj[a].pb(b); adj[b].pb(a); cap[a][b] = cap[b][a] = c;} // add edge

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

int n;
int rps[3][2];
FlowGraph g;
int ans1, ans2;

int solve() {
  int res = 0;
  ans1 = min(rps[0][0], rps[2][1]) + min(rps[1][0], rps[0][1]) + min(rps[2][0], rps[1][1]);
  ans2 = g.netFlow(0, 7);
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  cin >> rps[0][0];
  cin >> rps[2][0];
  cin >> rps[1][0];
  cin >> rps[0][1];
  cin >> rps[2][1];
  cin >> rps[1][1];
  g.init(8);
  g.add_edge(0, 1, rps[0][0]);
  g.add_edge(0, 2, rps[1][0]);
  g.add_edge(0, 3, rps[2][0]);
  g.add_edge(1, 4, rps[0][1]);
  g.add_edge(1, 5, rps[1][1]);
  g.add_edge(2, 5, rps[1][1]);
  g.add_edge(2, 6, rps[2][1]);
  g.add_edge(3, 6, rps[2][1]);
  g.add_edge(3, 4, rps[0][1]);
  g.add_edge(4, 7, rps[0][1]);
  g.add_edge(5, 7, rps[1][1]);
  g.add_edge(6, 7, rps[2][1]);
  solve();
  cout << (n - ans2) << " " << ans1 << "\n";
  return 0;
}
