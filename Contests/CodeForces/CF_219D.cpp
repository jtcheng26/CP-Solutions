#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INF 1000000001
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

int n;
vector<int> in[200001];
vector<int> out[200001];
vector<int> vertices;
int ans;
int sub[200001]; // cost to have all edges in subtree pointing away from root
int cost1;
int cost2;

void dfs1(int root, int parent) {
  for (int node : out[root]) {
    if (node == parent) continue;
    dfs1(node, root);
    sub[root] += sub[node];
  }
  for (int node : in[root]) {
    if (node == parent) continue;
    dfs1(node, root);
    sub[root] += sub[node] + 1;
  }
}

void dfs2(int root, int parent) {
  int k = sub[1] - cost2 + cost1;
  if (k < ans) {
    ans = k;
    vertices.clear();
    vertices.pb(root);
  } else if (k == ans) {
    vertices.pb(root);
  }
  for (int node : out[root]) {
    if (node == parent) continue;
    cost1++;
    dfs2(node, root);
    cost1--;
  }
  for (int node : in[root]) {
    if (node == parent) continue;
    cost2++;
    dfs2(node, root);
    cost2--;
  }
}

void solve() {
  cost1 = 0;
  cost2 = 0;
  ans = INF;
  for (int i=1;i<=n;i++) {
    sub[i] = 0;
  }
  dfs1(1, 0);
  dfs2(1, 0);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  for (int i=0;i<n-1;i++) {
    int u, v;
    cin >> u >> v;
    in[v].pb(u);
    out[u].pb(v);
  }
  solve();
  cout << ans << "\n";
  sort(vertices.begin(), vertices.end());
  for (int i=0;i<vertices.size();i++) {
    cout << vertices[i] << (i == vertices.size() - 1 ? "\n" : " ");
  }
  return 0;
}
