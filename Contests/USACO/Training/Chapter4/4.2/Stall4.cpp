/*
   LANG: C++11
   PROG: stall4
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

#define INF 1000000007
#define mp make_pair
#define pb push_back
#define F first
#define S second

typedef long long ll;

using namespace std;

int n, m;
vector<int> adj[404];
int cap[404][404];

int netFlow(int source, int sink) {
  if (source == sink)
    return INF;
  int total = 0;
  int prev[n+m+2];
  bool visited[n+m+2];
  int flow[n+m+2];
  while (true) {
    // Dijkstra
    for (int i=0;i<=n+m+1;i++) {
      prev[i] = -1;
      flow[i] = 0;
      visited[i] = false;
    }
    flow[source] = INF;
    int maxFlow;
    int maxLoc;
    while (true) {
      maxFlow = 0;
      maxLoc = -1;
      for (int i=0;i<=n+m+1;i++) { // not sure how i could replace this step with a pq since flow changes dynamically.
        if (flow[i] > maxFlow && !visited[i]) {
          maxFlow = flow[i];
          maxLoc = i;
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
    }
    // End Dijkstra
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

int solve() {
  for (int i=1;i<=n;i++) {
    cap[0][i] = 1;
    adj[0].pb(i);
    adj[i].pb(0);
  }
  for (int i=n+1;i<=n+m;i++) {
    cap[i][n+m+1] = 1;
    adj[i].pb(n+m+1);
    adj[n+m+1].pb(i);
  }
  return netFlow(0, n+m+1);
}

int main() {
  ofstream cout ("stall4.out");
  ifstream cin ("stall4.in");
  cin >> n >> m;
  for (int i=1;i<=n;i++) {
    int s, k;
    cin >> s;
    for (int j=0;j<s;j++) {
      cin >> k;
      adj[i].pb(n + k);
      adj[n+k].pb(i);
      cap[n+k][i] = 0;
      cap[i][n+k] = 1;
    }
  }
  cout << solve() << endl;
  return 0;
}
