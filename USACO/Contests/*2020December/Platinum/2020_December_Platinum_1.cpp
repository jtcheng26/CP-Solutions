#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INF 1000000001
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

struct FlowGraph {
  int n;
  vector<int> adj[100001];
  int cap[1000][1000]; // use map for larger graphs

  void init(int num) { n = num; for (int i=0;i<=n;i++) adj[i].clear(); } // clear tree
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

int n;
FlowGraph fg;
int barns[3001];
int cows[3001];

ll solve() {
  int source = 0;
  int sink = 2 * n + 1;
  fg.init(2 * n + 2);
  for (int i=1;i<=n;i++) {
    fg.add_edge(0, i);
    fg.cap[0][i] = fg.cap[i][0] = n;
    fg.add_edge(2 * n + 1, n + i);
    fg.cap[2 * n + 1][n + i] = fg.cap[n + i][2 * n + 1] = n;
  }
  for (int i=1;i<=n;i++) {
    for (int j=1;j<=n;j++) {
      if (cows[i] <= barns[j]) {
        fg.add_edge(i, n + j);
        fg.cap[i][n + j] = fg.cap[n + j][i] = 1;
      }
    }
  }
  return fg.netFlow(source, sink);
}

int main() {
  cin >> n;
  for (int i=1;i<=n;i++) {
    cin >> cows[i];
  }
  for (int i=1;i<=n;i++) {
    cin >> barns[i];
  }
  cout << solve() << "\n";
  return 0;
}
