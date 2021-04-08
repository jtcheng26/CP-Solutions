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
#define MOD 1e9+7

typedef long long ll;

using namespace std;

int n;
ll w[100001];
vector<int> adj[100001];
ll ans[100001];
priority_queue<ll> nodes;

void dfs(int parent, int node) {
  for (int i=0;i<adj[node].size();i++) {
    int child = adj[node][i];
    if (child == parent) continue;
    if (node != 1 ||  i < adj[node].size()-1) nodes.push(w[node]);
    dfs(node, child);
  }
}

void solve() {
  for (int i=0;i<=n;i++) {
    ans[i] = 0;
  }
  for (int i=1;i<=n;i++) {
    ans[1] += w[i];
  }
  while (!nodes.empty())
    nodes.pop();
  dfs(0, 1);
  for (int i=2;i<=n-1;i++) {
    ll top = nodes.top();
    nodes.pop();
    ans[i] = ans[i-1] + top;
  }
  //dfs(0, best);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i=1;i<=n;i++) {
      adj[i].clear();
      cin >> w[i];
    }
    for (int i=0;i<n-1;i++) {
      int u, v;
      cin >> u >> v;
      adj[u].pb(v);
      adj[v].pb(u);
    }
    solve();
    for (int i=1;i<=n-1;i++) {
      cout << ans[i] << (i == n-1 ? "\n" : " ");
    }
  }
  return 0;
}
