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

typedef long long ll;

using namespace std;

struct SegTree {
  int n = 400000;  // array size
  int t[800001] = {0};

  void init() {  // build the tree
    for (int i = n - 1; i > 0; --i) t[i] = min(t[i<<1], t[i<<1|1]);
  }

  int rngMin(int l, int r) {  // min on interval [l, r)
    int res = 1000000;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) res = min(res, t[l++]);
      if (r&1) res = min(res, t[--r]);
    }
    return res;
  }
};

int n;
int a[300001];
bool ans[300001];
SegTree st;

void rec(int l, int r) { // inclusive
  int num = n - (r - l);
  if (l > r) return;
  int mn = st.rngMin(l, r+1);
  if (mn == num)
    ans[n-num] = true;
  if (a[l] == num && a[r] != num) {
    rec(l+1, r);
  } else if (a[r] == num && a[l] != num) {
    rec(l, r-1);
  }
}

int solve() {
  int cnt[300001] = {0};
  st.n = n;
  for (int i=0;i<n;i++) {
    ans[i] = false;
    st.t[i] = 1000000;
    st.t[n + i] = a[i];
  }
  st.init();
  ans[0] = true;
  for (int i=0;i<n;i++) {
    if (cnt[a[i]] != 0) {
      ans[0] = false;
      break;
    }
    cnt[a[i]] = 1;
  }
  rec(0, n-1);
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    solve();
    for (int i=0;i<n;i++) cout << ans[i] << (i == n-1?"\n" : "");
  }
  return 0;
}
