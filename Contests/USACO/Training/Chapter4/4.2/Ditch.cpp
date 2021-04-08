/*
   LANG: C++11
   PROG: ditch
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INF 1000000007
#define mp make_pair
#define pb push_back
#define F first
#define S second

typedef long long ll;

using namespace std;

int n, m;
vector<int> adj[201];
int cap[201][201];

int netFlow(int source, int sink) {
  if (source == sink)
    return INF;
  int total = 0;
  int prev[m+1];
  bool visited[m+1];
  int flow[m+1];
  while (true) {
    // Dijkstra
    for (int i=1;i<=m;i++) {
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
      for (int i=1;i<=m;i++) {
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
          //cout << flow[child] << " " << child << endl;
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
  return netFlow(1, m);
}

int main() {
  ofstream cout ("ditch.out");
  ifstream cin ("ditch.in");
  cin >> n >> m;
  for (int i=0;i<n;i++) {
    int s, e, c;
    cin >> s >> e >> c;
    cap[s][e] += c;
    //cap[e][s] = 0;
    adj[s].pb(e);
    adj[e].pb(s);
  }
  cout << solve() << endl;
  return 0;
}
