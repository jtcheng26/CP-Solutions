#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INFI 1e9+7
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long ll;

using namespace std;

int n, k;
vector<int> adj[200001];
ll depth[200001];
ll subtreeSize[200001];
ll happiness[200001];

int dfs(int parent, int node) {
  subtreeSize[node] = 0;
  depth[node] = depth[parent] + 1;
  for (int i=0;i<adj[node].size();i++) {
    int child = adj[node][i];
    if (parent == child) continue;
    subtreeSize[node] += dfs(node, child) + 1;
  }
  //cout << node << " subtree " << subtreeSize[node] << " depth " << depth[node] << endl;
  happiness[node] = subtreeSize[node] - (depth[node] - 1);
  //cout << happiness[node] << endl;
  return subtreeSize[node];
}

ll solve() {
  ll res = 0;
  depth[0] = 0;
  dfs(0, 1);
  sort(happiness+1, happiness+n+1);
  reverse(happiness+1, happiness+n+1);
  for (int i=1;i<=n-k;i++) res += happiness[i];
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
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
