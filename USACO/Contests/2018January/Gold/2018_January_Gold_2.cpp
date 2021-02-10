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

int n, k;
vector<int> adj[100001];

int solve() {
  if (adj[k].size() == 0) return 1; // if source is an exit
  int distExit[n + 1]; // distance from leaf nodes
  int dist[n + 1]; // distance from source (k)
  int res = 0;
  queue<int> q;
  for (int i=1;i<=n;i++) {
    if (adj[i].size() == 1) {
      distExit[i] = 0;
      q.push(i);
    } else {
      distExit[i] = INF;
    }
    dist[i] = INF;
  }
  while (!q.empty()) {
    int top = q.front();
    q.pop();
    for (int& neighbor : adj[top]) {
      if (distExit[neighbor] != INF) continue;
      distExit[neighbor] = distExit[top] + 1;
      q.push(neighbor);
    }
  }
  q.push(k);
  dist[k] = 0;
  while (!q.empty()) {
    int top = q.front();
    q.pop();
    if (distExit[top] <= dist[top]) {
      res++;
    } else {
      for (int& neighbor : adj[top]) {
        if (dist[neighbor] != INF) continue;
        dist[neighbor] = dist[top] + 1;
        q.push(neighbor);
      }
    }
  }
  return res;
}

int main() {
  ofstream cout ("atlarge.out");
  ifstream cin ("atlarge.in");
  cin >> n >> k;
  for (int i=0;i<n-1;i++) {
    int u, v;
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  cout << solve() << endl;
  return 0;
}
