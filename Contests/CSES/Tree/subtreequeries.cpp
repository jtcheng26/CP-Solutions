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

struct SegTree {
  int n = 200001;  // array size
  ll t[400002];

  void init() {  // build the tree
    for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
  }

  void ptUpdate(int p, int value) {  // set value at position p
    for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
  }

  ll rngSum(int l, int r) {  // sum on interval [l, r)
    ll res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) res += t[l++];
      if (r&1) res += t[--r];
    }
    return res;
  }
};

int n, q;
int a[200001];
vector<int> adj[200001];
SegTree st;
pair<int, int> sub[200001];

void query1(int i, int v) {
  st.ptUpdate(sub[i].F, v);
}

ll query2(int i) {
  return st.rngSum(sub[i].F, sub[i].S + 1);
}

int dfs(int node, int parent, int v, vector<int>& b) {
  sub[node].F = v;
  b.pb(a[node]);
  for (int child : adj[node]) {
    if (child == parent) continue;
    v = dfs(child, node, v + 1, b);
  }
  sub[node].S = v;
  return v;
}

void solve() {
  vector<int> b;
  dfs(1, 0, 0, b);
  //cout << "b" << "\n";
  for (int i=0;i<n;i++) {
    st.t[st.n+i] = b[i];
    //cout << sub[i+1].F << " " << sub[i+1].S << "\n";
    //cout << b[i] << " ";
  }
  //cout << "\n";
  st.init();
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n >> q;
  for (int i=1;i<=n;i++) cin >> a[i];
  for (int i=0;i<n-1;i++) {
    int u, v;
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  solve();
  for (int i=0;i<q;i++) {
    int t;
    cin >> t;
    if (t == 1) {
      int s, x;
      cin >> s >> x;
      query1(s, x);
    } else {
      int s;
      cin >> s;
      cout << query2(s) << "\n";
    }
  }
  return 0;
}
