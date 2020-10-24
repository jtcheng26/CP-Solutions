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
vector<int> adj[200001];
ll a[200001];
int leafNodes[200001]; // # of leaf nodes
ll maxLeafCnt[200001]; // max citizens in a leaf node
ll totalLeafCnt[200001]; // total citizens in subtree

void dfs(int node) {
  if (adj[node].size() == 0) {
    leafNodes[node] = 1;
    maxLeafCnt[node] = a[node];
    totalLeafCnt[node] = a[node];
    return;
  }
  for (int neighbor : adj[node]) {
    dfs(neighbor);
    leafNodes[node] += leafNodes[neighbor];
    totalLeafCnt[node] += totalLeafCnt[neighbor];
    maxLeafCnt[node] = max(maxLeafCnt[node], maxLeafCnt[neighbor]);
  }
  totalLeafCnt[node] += a[node];
  maxLeafCnt[node] = max(maxLeafCnt[node], (totalLeafCnt[node] + (leafNodes[node]-1)) / leafNodes[node]);
}

ll solve() {
  ll res = 0;
  for (int i=0;i<=n;i++) {
    leafNodes[i] = 0;
    maxLeafCnt[i] = 0;
    totalLeafCnt[i] = 0;
  }
  dfs(1);
  //cout << leafNodes[1] << " " << maxLeafCnt[1] << " " << totalLeafCnt[1] << "\n";
  return maxLeafCnt[1];
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  for (int i=2;i<=n;i++) {
    int u;
    cin >> u;
    adj[u].pb(i);
  }
  for (int i=1;i<=n;i++) {
    cin >> a[i];
  }
  cout << solve() << "\n";
  return 0;
}
