#include <iostream>
#include <fstream>
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

int d[100001];

template<class T> struct Seg { // comb(ID,b) = b
 	const T ID = -1;
  T comb(T a, T b) {
    if (a == -1) return b;
    else if (b == -1) return a;
    else if (d[a] < d[b]) return a;
    return b;
  }
 	int n; vector<T> seg;
 	void init(int _n) { n = _n; seg.assign(2*n,ID); }
  void init(vector<T> v) { n = int(v.size()); init(n); for (int i=0;i<n;i++) { upd(i, v[i]);}}
 	void pull(int p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
 	void upd(int p, T val) { // set val at position p
 		seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); }
 	T query(int l, int r) { // sum on interval [l, r]
 		T ra = ID, rb = ID;
 		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
 			if (l&1) ra = comb(ra,seg[l++]);
 			if (r&1) rb = comb(seg[--r],rb);
 		}
 		return comb(ra,rb);
 	}
};

template<class T> struct BIT {
  vector<T> bit;
  void init(int n) {
    bit.assign(n, 0);
  }
  T query(int r) {
    T res = 0;
    for (; r >= 0;r = (r & (r + 1)) - 1)
      res ^= bit[r];
    return res;
  }
  T query(int l, int r) {
    return query(r) - query(l - 1);
  }
  void upd(int idx, T d) {
    for (; idx < bit.size(); idx = idx | (idx + 1))
      bit[idx] ^= d;
  }
};

int n, q;
vector<int> adj[100001];
pair<int, int> sub[100001];
BIT<int> bit;
Seg<int> st;
int f[100001];
int cost[100001];
int num = 0;
vector<int> b;

void query1(int p, int v) {
  int dif = v ^ cost[p];
  cost[p] = v;
  bit.upd(sub[p].F, dif);
  bit.upd(sub[p].S+1, dif);
}

int query2(int u, int v) {
  //cout << f[u] << " " << f[v] << "\n";
  //cout << st.query(min(f[u], f[v]), max(f[u], f[v])) << "\n";
  return bit.query(sub[u].F) ^ bit.query(sub[v].F) ^ cost[st.query(min(f[u], f[v]), max(f[u], f[v]))];
}

int dfs(int node, int parent, int v) {
  sub[node].F = v;
  f[node] = num++;
  b.pb(node);
  for (int child : adj[node]) {
    if (child == parent) continue;
    d[child] = d[node] + 1;
    v = dfs(child, node, v + 1);
    b.pb(node);
    num++;
  }
  sub[node].S = v;
  return v;
}

void solve() {
  d[1] = 0;
  dfs(1, 0, 0);
  bit.init(n);
  st.init(b);
  //for (int i=0;i<b.size();i++) cout << b[i] << (i == b.size()-1 ? "\n" : " ");
  for (int i=1;i<=n;i++) {
    bit.upd(sub[i].F, cost[i]);
    bit.upd(sub[i].S+1, cost[i]);
  }
}

int main() {
  ifstream cin ("cowland.in");
  ofstream cout ("cowland.out");
  cin >> n >> q;
  for (int i=1;i<=n;i++) cin >> cost[i];
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
      int p, v;
      cin >> p >> v;
      query1(p, v);
    } else {
      int a, b;
      cin >> a >> b;
      cout << query2(a, b) << "\n";
    }
  }
  return 0;
}
