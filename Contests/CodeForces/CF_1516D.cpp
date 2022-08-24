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

int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

struct state {
  int l, r, v;
};

template<class T> struct Seg { // comb(ID,b) = b
 	const T ID = { 0, 0, 0 };
  T comb(T a, T b) {
    state s;
    s.l = a.l;
    s.r = b.r;
    s.v = a.v + b.v;
    if (gcd(a.r, b.l) == 1) {
      if (b.v == 1) s.r = 1;
      if (a.v == 1) s.l = 1;
      s.v--;
    }
    return s;
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
int a[100001];
Seg<state> st;

int query(int l, int r) {
  return st.query(l, r).v;
}

void solve() {
  st.init(n);
  for (int i=0;i<n;i++) {
    state s;
    s.l = s.r = a[i];
    s.v = 1;
    st.upd(i, s);
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n >> q;
  for (int i=0;i<n;i++) cin >> a[i];
  solve();
  for (int i=0;i<q;i++) {
    int l, r;
    cin >> l >> r;
    cout << query(l-1, r-1) << "\n";
  }
  return 0;
}