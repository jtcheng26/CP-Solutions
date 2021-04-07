#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>

#define INF 1000000001
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

template<class T> struct BIT {
  vector<T> bit;
  void init(int n) {
    bit.assign(n, 0);
  }
  T query(int r) {
    T res = 0;
    for (; r >= 0;r = (r & (r + 1)) - 1)
      res += bit[r];
    return res;
  }
  T query(int l, int r) {
    return query(r) - query(l - 1);
  }
  void upd(int idx, T d) {
    for (; idx < bit.size(); idx = idx | (idx + 1))
      bit[idx] += d;
  }
};

int n, q;
vector<int> adj[200001];
ll cost[200001];
pair<int, int> sub[200001];
BIT<ll> bit;

void query1(int p, ll v) {
  ll dif = v - cost[p];
  cost[p] = v;
  bit.upd(sub[p].F, dif);
  bit.upd(sub[p].S + 1, -dif);
}

ll query2(int p) {
  return bit.query(sub[p].F);
}

int dfs(int node, int parent, int v) {
  sub[node].F = v;
  for (int child : adj[node]) {
    if (child == parent) continue;
    v = dfs(child, node, v + 1);
  }
  sub[node].S = v;
  return v;
}

void solve() {
  dfs(1, 0, 0);
  bit.init(n);
  for (int i=1;i<=n;i++) {
    bit.upd(sub[i].F, cost[i]);
    bit.upd(sub[i].S + 1, -cost[i]);
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n >> q;
  for (int i=1;i<=n;i++) {
    cin >> cost[i];
  }
  for (int i=0;i<n-1;i++) {
    int a, b;
    cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  solve();
  for (int i=0;i<q;i++) {
    int t;
    cin >> t;
    if (t == 1) {
      int p, v;
      cin >> p >> v;
      query1(p, v);
    } else {
      int p;
      cin >> p;
      cout << query2(p) << "\n";
    }
  }
  return 0;
}
