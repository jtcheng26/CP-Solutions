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

int n;
vector<int> adj[100001];
pair<int, int> cut;
pair<int, int> add;
int subtreeSize[100001];
vector<int> centroids;

void dfs(int parent, int root) {
  if (root > n) return;
  bool cen = true;
  subtreeSize[root] = 1;
  for (int i=0;i<adj[root].size();i++) {
    int child = adj[root][i]; if (child == parent) continue;
    dfs(root, child);
    subtreeSize[root] += subtreeSize[child];
    if (subtreeSize[child] > n / 2) cen = false;
  }
  if (n - subtreeSize[root] > n / 2) cen = false;
  if (cen) centroids.pb(root);
}

int solve() {
  int res = 0;
  dfs(-1, 1);
  //for (int i=1;i<=n;i++) cout << subtreeSize[i] << endl;
  //for (int i=0;i<centroids.size();i++) cout << centroids[i] << endl;
  if (centroids.size() == 1) {
    cut.F = centroids[0];
    cut.S = adj[centroids[0]][0];
    add.F = centroids[0];
    add.S = adj[centroids[0]][0];
  } else {
    int root = centroids[0];
    for (int i=0;i<adj[root].size();i++) {
      if (adj[root][i] == centroids[1]) continue;
      cut.F = root;
      cut.S = adj[root][i];
      add.F = centroids[1];
      add.S = adj[root][i];
      break;
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i=1;i<=n;i++) adj[i].clear();
    centroids.clear();
    for (int i=0;i<n-1;i++) {
      int x, y;
      cin >> x >> y;
      adj[x].pb(y);
      adj[y].pb(x);
    }
    solve();
    cout << cut.F <<  " " << cut.S << "\n";
    cout << add.F << " " << cut.S << "\n";
  }
  return 0;
}
