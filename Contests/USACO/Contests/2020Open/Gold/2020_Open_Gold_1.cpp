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

struct SegTree {
  int n = 100001;  // array size
  int t[200002] = {0};

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

int n;
int a[100001];
ll ans[100001];
vector<int> b[100001];

void solve() {
  SegTree st;
  st.init();
  for (int i=n-1;i>=0;i--) {
    b[a[i]].pb(i);
    ans[n] += st.rngSum(0, a[i]);
    st.ptUpdate(a[i], st.t[st.n+a[i]] + 1);
  }
  SegTree st2;
  st2.init();
  for (int i=0;i<=n;i++) {
    for (int j : b[i]) {
      st2.ptUpdate(j, 1);
    }
    for (int j : b[i]) {
      ans[i] -= j - st2.rngSum(0, j);
    }
  }
  for (int i=n-1;i>=0;i--) {
    ans[i] += ans[i+1];
  }
}

int main() {
  ofstream cout ("haircut.out");
  ifstream cin ("haircut.in");
  cin >> n;
  for (int i=0;i<n;i++) cin >> a[i];
  solve();
  for (int i=0;i<n;i++) {
    cout << ans[i] << "\n";
  }
  return 0;
}
