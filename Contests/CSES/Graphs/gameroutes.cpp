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

int n, m;
vector<int> in[100001];
vector<int> out[100001];
ll dp[100001];

ll dfs(int node) {
  if (dp[node] != -1) return dp[node];
  ll res = 0;
  for (int k : out[node]) {
    res = (res + dfs(k)) % MOD;
  }
  dp[node] = res;
  return dp[node];
}

ll solve() {
  for (int i=1;i<=n;i++) {
    dp[i] = -1;
  }
  dp[n] = 1;
  return dfs(1);
}

int main() {
  cin >> n >> m;
  for (int i=0;i<m;i++) {
    int u, v;
    cin >> u >> v;
    in[v].pb(u);
    out[u].pb(v);
  }
  cout << solve() << endl;
  return 0;
}
