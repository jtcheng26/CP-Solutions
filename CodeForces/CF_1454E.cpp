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

vector<int> adj[200001];
vector<int> adj2[200001]; // no cycle edges
ll n;
int component[200001];
bool visited[200001];

int dfs(int root, int parent) {
  visited[root] = true;
  int ret = -1;
  for (int i=0;i<adj[root].size();i++) {
    int node = adj[root][i];
    if (node == parent) continue;
    if (visited[node]) {
      if (ret == -1)
        ret = node;
      continue;
    }
    int repeated = dfs(node, root);
    //cout << repeated << "\n";
    if (repeated != -1) {
      if (repeated != root)
        ret = repeated;
      else
        ret = -2;
    }
    else {
      //cout << root << " " << node << "\n";
      adj2[root].pb(node);
      adj2[node].pb(root);
    }
  }
  return ret == -2 ? -1 : ret;
}

int dfs2(int comp, int node) {
  int cnt = 1;
  component[node] = comp;
  for (int i=0;i<adj2[node].size();i++) {
    int child = adj2[node][i];
    if (component[child] != comp)
      cnt += dfs2(comp, child);
  }
  return cnt;
}

ll solve() {
  ll res = n * (n-1);
  ll sub = 0;
  int comp = 1;
  dfs(1, -1);
  for (int i=1;i<=n;i++) {
    if (component[i] == 0) {
      ll cnt = dfs2(comp++, i);
      //cout << cnt << "\n";
      sub += (cnt * (cnt-1)) / 2;
    }
  }
  return res - sub;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i=0;i<=n;i++) {
      component[i] = 0;
      visited[i] = false;
      adj[i].clear();
      adj2[i].clear();
    }
    for (int i=0;i<n;i++) {
      int u, v;
      cin >> u >> v;
      adj[u].pb(v);
      adj[v].pb(u);
    }
    cout << solve() << "\n";
  }
  return 0;
}
