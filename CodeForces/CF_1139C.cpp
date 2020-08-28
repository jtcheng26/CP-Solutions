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
#define MOD 1000000007

typedef long long ll;

using namespace std;

int n, k;
vector<int> adj[100001];
vector<int> color[100001]; // 1 = red
int comp[100001];
int comp_size[100001];

vector<ll> facts;

ll power(int n, int k) {
  ll res = n;
  for (int i=2;i<=k;i++) {
    res = (res * n) % MOD;
  }
  return res;
}

ll factorial(int f) {
  if (facts.size() > 0 && facts[f] != 0) return facts[f];
  if (f == 0) return 1;
  facts.push_back(1);
  ll ans = 1;
  for (int i=1;i<=f;i++) {
    ans *= i;
    ans %= MOD;
    facts.push_back(ans);
  }
  return ans;
}

void dfs(int c, int u) {
  comp[u] = c; int cnt = 0;
  for (int i=0;i<adj[u].size();i++) {
    int child = adj[u][i];
    if (color[u][i] == 1) {
      if (comp[child] <= 0)
        dfs(c, child);
      cnt++;
    }
  }
  if (cnt == 0) comp[u] = 0;
  else comp_size[c]++;
}

ll solve() {
  ll res = power(n, k) % MOD;
  int c = 0;
  for (int i=1;i<=n;i++) comp[i] = -1;
  for (int i=1;i<=n;i++) {
    if (comp[i] == -1) {
        dfs(++c, i);
      if (comp[i] == 0) c--; // no red edges incident
    }
  }
  ll sub = 0;
  for (int i=1;i<=n;i++)
    if (comp_size[comp[i]] <= 1)
      sub++;
  bool visited[100001] = {false};
  for (int i=1;i<=n;i++) {
    //cout << comp[i] << endl;
    if (comp[i] == 0 || visited[comp[i]]) continue;
    res -= power(comp_size[comp[i]], k);
    if (res < 0) res += MOD;
    visited[comp[i]] = true;
  }
  res -= sub; // any path consisting of itself k times will not work
  return (res < 0 ? res + MOD : res);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n >> k;
  for (int i=0;i<n-1;i++) {
    int u, v, x;
    cin >> u >> v >> x;
    adj[u].pb(v);
    adj[v].pb(u);
    color[u].pb(!x);
    color[v].pb(!x);
  }
  cout << solve() << endl;
  return 0;
}
