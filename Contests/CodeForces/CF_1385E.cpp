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

int n, m;
vector<vector<int> > directed; // directed edges i -> j
vector<pair<int, int> > edges;
vector<int> ord;
vector<bool> visited;
int pos[200001];

void dfs(int u) {
  visited[u] = true;
  for (int i=0;i<directed[u].size();i++) {
    if (visited[directed[u][i]]) continue;
    dfs(directed[u][i]);
  }
  ord.pb(u);
}

int solve() {
  visited = vector<bool> (n+1);
  for (int i=1;i<=n;i++) {
    if (!visited[i])
      dfs(i);
  }
  reverse(ord.begin(), ord.end());
  for (int i=0;i<n;i++) {
    pos[ord[i]] = i;
  }
  for (int i=1;i<=n;i++) {
    for (int j=0;j<directed[i].size();j++) {
      if (pos[directed[i][j]] < pos[i]) return false;
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    edges.clear();
    ord.clear();
    directed = vector<vector<int> > (n + 1);
    for (int i=0;i<m;i++) {
      int tp, u, v;
      cin >> tp >> u >> v;
      if (tp == 1)
        directed[u].pb(v);
      edges.pb(mp(u, v));
    }
    bool ans = solve();
    cout << (ans ? "YES" : "NO") << endl;
    if (ans) {
      for (int i=0;i<edges.size();i++) {
        int u = edges[i].F; int v = edges[i].S;
        if (pos[v] > pos[u])
          cout << u << " " << v << endl;
        else
          cout << v << " " << u << endl;
      }
    }
  }
  return 0;
}
