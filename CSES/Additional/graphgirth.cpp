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

int n, m;
vector<int> adj[2501];

int bfs(int source) {
  int res = INF;
  int dist[n+1];
  int parent[n+1];
  for (int i=1;i<=n;i++) {
    dist[i] = -1;
    parent[i] = -1;
  }
  queue<int> q;
  q.push(source);
  parent[source] = -1;
  dist[source] = 0;
  while (!q.empty()) {
    int top = q.front();
    q.pop();
    for (int neighbor : adj[top]) {
      if (neighbor == parent[top]) continue;
      if (dist[neighbor] == -1) {
        dist[neighbor] = dist[top] + 1;
        parent[neighbor] = top;
        q.push(neighbor);
      } else {
        res = min(res, dist[top] + 1 + dist[neighbor]);
      }
    }
  }
  return res;
}

int solve() {
  int ans = INF;
  for (int i=1;i<=n;i++) {
    ans = min(ans, bfs(i));
  }
  return ans == INF ? -1 : ans;
}

int main() {
  cin >> n >> m;
  for (int i=0;i<m;i++) {
    int u, v;
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  cout << solve() << endl;
  return 0;
}
