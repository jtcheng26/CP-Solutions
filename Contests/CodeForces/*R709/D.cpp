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
  int n = 300001;  // array size
  int t[600001] = {INF};

  void init() {  // build the tree
    for (int i = n - 1; i > 0; --i) t[i] = min(t[i<<1], t[i<<1|1]);
  }

  void ptUpdate(int p, int value) {  // set value at position p
    for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = min(t[p], t[p^1]);
  }

  int rngMin(int left, int right) {  // min on interval [l, r)
    int l = left;
    int r = right;
    int res = INF;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) res = min(res, t[l++]);
      if (r&1) res = min(res, t[--r]);
    }
    return res;
  }
};

struct SegTree2 {
  int n = 300001;  // array size
  int t[600001] = {0};

  void init() {  // build the tree
    for (int i = n - 1; i > 0; --i) t[i] = max(t[i<<1], t[i<<1|1]);
  }

  void ptUpdate(int p, int value) {  // set value at position p
    for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = max(t[p], t[p^1]);
  }

  int rngMax(int left, int right) {  // min on interval [l, r)
    int l = left;
    int r = right;
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) res = max(res, t[l++]);
      if (r&1) res = max(res, t[--r]);
    }
    return res;
  }
};
int n;
int h[300001];
int b[300001];
int a[300001];
ll dp[300001];
SegTree st1;

ll solve() {
  ll res = 0;
  SegTree2 st2;
  st1.n = n;
  st1.init();
  st1.ptUpdate(0, h[0]);
  dp[0] = b[0];
  ll best = 0;
  for (int i=1;i<n;i++) {
    st1.ptUpdate(i, h[i]);
    dp[i] = a[st1.rngMin(0, i+1)];
    int be = st1.rngMin(best+1, i+1);
    if (be > h[i]) {
      best = a[h[i]];
    }
    if (dp[best] + a[h[i]] < dp[i])
    dp[i] = max(dp[i], best);
    for (int j=i-1;j>=0;j--) {
      dp[i] = max(dp[i], dp[j] + a[st1.rngMin(j+1, i+1)]);
    }
  }
  return dp[n-1];
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  for (int i=0;i<n;i++) cin >> h[i];
  for (int i=0;i<n;i++) {
    cin >> b[i];
    a[h[i]] = b[i];
  }
  cout << solve() << "\n";
  return 0;
}
