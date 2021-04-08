#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

struct SegTree {
  int n = 200001;  // array size
  int t[400002] = {0};

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
pair<int, int> pts[100001];
ll twoPow[100001];

void precomp() {
  twoPow[0] = 1;
  for (int i=1;i<n;i++) {
    twoPow[i] = (twoPow[i-1] * 2) % MOD;
  }
}

ll solve() {
  ll res = 0;
  precomp();
  sort(pts, pts+n);
  SegTree st;
  st.init();
  for (int i=0;i<n;i++) {
    res = (2 * res) % MOD;
    int cnt = st.rngSum(0, pts[i].F);
    st.ptUpdate(pts[i].S, st.t[st.n+pts[i].S]+1);
    res = (res + twoPow[cnt]) % MOD;
  }
  return res;
}

int main() {
  ofstream cout ("help.out");
  ifstream cin ("help.in");
  cin >> n;
  for (int i=0;i<n;i++) {
    cin >> pts[i].F >> pts[i].S;
  }
  cout << solve() << "\n";
  return 0;
}
