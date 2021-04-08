#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

int n, k;
vector<int> adj[100001];
int color[100001];
ll dp[100001][4];

ll dfs(int parent, int node, int parColor) {
  if (dp[node][parColor] != -1) return dp[node][parColor];
  ll cnt[4] = {0};
  if (color[node] > 0) {
    if (color[node] == parColor) return 0;
    cnt[color[node]] = 1;
    for (int child : adj[node]) {
      if (child == parent) continue;
      cnt[color[node]] = (cnt[color[node]] * dfs(node, child, color[node])) % MOD;
    }
    return cnt[color[node]];
  }
  for (int i=1;i<=3;i++) {
    if (i == parColor) continue;
    cnt[i] = 1;
    for (int child : adj[node]) {
      if (child == parent) continue;
      cnt[i] = (cnt[i] * dfs(node, child, i)) % MOD;
    }
  }
  dp[node][parColor] = (cnt[1] + cnt[2] + cnt[3]) % MOD;
  return dp[node][parColor];
}

ll solve() {
  ll res = 0;
  for (int i=1;i<=n;i++) {
    for (int j=0;j<=3;j++) {
      dp[i][j] = -1;
    }
  }
  return dfs(0, 1, 0);
}

int main() {
  ofstream cout ("barnpainting.out");
  ifstream cin ("barnpainting.in");
  cin >> n >> k;
  for (int i=1;i<=n-1;i++) {
    int u, v;
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
    color[i] = 0;
  }
  for (int i=0;i<k;i++) {
    int b, c;
    cin >> b >> c;
    color[b] = c;
  }
  cout << solve() << endl;
  return 0;
}

/*
10 4
1 2
2 3
2 4
3 5
1 6
1 7
7 8
7 9
7 10
2 1
5 2
8 3
10 1
should be 8
*/
