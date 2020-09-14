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

struct query {
  int g;
  int beg, end;
};

int n, m;
vector<int> adj[5001];
int edge[5001][5001];
query q[5001];
int val[5000];

bool cmp(query a, query b) {
  return a.g < b.g;
}

bool dfs(int goal, int parent, int node, int beauty) {
  if (node == goal) {
    val[edge[parent][node]] = beauty;
    return true;
  }
  for (int e : adj[node]) {
    if (e == parent) continue;
    bool res = dfs(goal, node, e, beauty);
    if (res) {
      if (parent == -1) return true;
      val[edge[parent][node]] = max(val[edge[parent][node]], beauty);
      return true;
    }
  }
  return false;
}

int dfs2(int goal, int parent, int node) {
  if (node == goal) return val[edge[parent][node]];
  for (int e : adj[node]) {
    if (e == parent) continue;
    int mn = dfs2(goal, node, e);
    if (mn == 0) mn = 1000000;
    if (val[edge[parent][node]] == 0) val[edge[parent][node]] = 1000000;
    if (mn > 0) {
      if (parent == -1) return mn;
      return min(mn, val[edge[parent][node]]);
    }
  }
  return -1;
}

bool solve() {
  sort(q, q+m, cmp);
  int node, mn, beg, end, g;
  for (int i=0;i<m;i++) {
    dfs(q[i].end, -1, q[i].beg, q[i].g);
  }
  for (int i=0;i<m;i++) {
    int res = dfs2(q[i].end, -1, q[i].beg);
    if (res == -1 || res != q[i].g) return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  int u, v;
  for (int i=0;i<n-1;i++) {
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
    edge[u][v] = edge[v][u] = i+1;
  }
  cin >> m;
  for (int i=0;i<m;i++) {
    cin >> q[i].beg >> q[i].end >> q[i].g;
  }
  if (!solve()) cout << "-1" << endl;
  else for (int i=1;i<n;i++) cout << (val[i] == 0 ? 1000000 : val[i]) << (i == n-1 ? "\n" : " ");
  return 0;
}
