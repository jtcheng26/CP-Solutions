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
vector<pair<int, int> > out[100001];
vector<pair<int, int> > in[100001];
ll cost[100001];
ll mn[100001];
ll mx[100001];
ll cnt[100001];
bool visited[100001];

ll dfs(int node) {
  if (cnt[node] != -1) return cnt[node];
  ll res = 0;
  for (pair<int, int>& child : out[node]) {
    if (cost[node] + child.F == cost[child.S]) {
      res = (res + dfs(child.S)) % MOD;
    }
  }
  cnt[node] = res;
  return res;
}

int dfs2(int node) {
  if (mn[node] != -1) return mn[node];
  int res = n;
  for (pair<int, int>& child : out[node]) {
    if (cost[node] + child.F == cost[child.S]) {
      res = min(res, 1 + dfs2(child.S));
    }
  }
  mn[node] = res;
  return mn[node];
}

void solve() {
  for (int i=1;i<=n;i++) {
    cost[i] = 10e16+7;
    mn[i] = -1;
    mx[i] = 0;
    cnt[i] = -1;
  }
  priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int > > > pq;
  pq.push(mp(0, 1));
  cost[1] = 0;
  mn[n] = 0;
  mx[1] = 0;
  while (!pq.empty()) {
    pair<ll, int> node = pq.top();
    int top = node.S;
    pq.pop();
    if (visited[top]) continue;
    visited[top] = true;
    for (pair<int, int>& child : out[top]) {
      if (visited[child.S]) continue;
      int c = child.F;
      int k = child.S;
      if (cost[top] + c < cost[k]) {
        cost[k] = cost[top] + c;
        mx[k] = mx[top] + 1;
      } else if (cost[top] + c == cost[k]) {
        mx[k] = max(mx[k], mx[top] + 1);
      }
      pq.push(mp(cost[k], k));
    }
  }
  cnt[n] = 1;
  dfs(1);
  dfs2(1);
}

int main() {
  cin >> n >> m;
  for (int i=0;i<m;i++) {
    int u, v, c;
    cin >> u >> v >> c;
    out[u].pb(mp(c, v));
    in[v].pb(mp(c, u));
  }
  solve();
  cout << cost[n] << " " << cnt[1] << " " << mn[1] << " " << mx[n] << "\n";
  return 0;
}
