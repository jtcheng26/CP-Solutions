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

int depth[200001];

template<class T> struct SegTree { // comb(ID,b) = b
 	const T ID = -1;
  T comb(T a, T b) {
    if (a == -1) return b;
    else if (b == -1) return a;
    else if (depth[a] < depth[b]) return a;
    else return b;
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

int n, q;
vector<int> adj[200001];
int f[200001];
vector<int> b;
SegTree<int> st;

int query(int u, int v) {
  return st.query(min(f[u], f[v]), max(f[u], f[v]));
}

int dfs(int node, int parent, int v) {
  f[node] = v;
  b.pb(node);
  for (int child : adj[node]) {
    if (child == parent) continue;
    depth[child] = depth[node] + 1;
    v = dfs(child, node, v + 1) + 1;
    b.pb(node);
  }
  return v;
}

void solve() {
  dfs(1, 0, 0);
  st.init(b);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n >> q;
  for (int i=2;i<=n;i++) {
    int u;
    cin >> u;
    adj[i].pb(u);
    adj[u].pb(i);
  }
  solve();
  for (int i=0;i<q;i++) {
    int u, v;
    cin >> u >> v;
    cout << query(u, v) << "\n";
  }
  return 0;
}
