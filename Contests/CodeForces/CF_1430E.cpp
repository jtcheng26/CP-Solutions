#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <stack>

#define INFI 1e18+7
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long ll;

using namespace std;

struct SegTree {
  int n = 200001;  // array size
  int t[400002] = {0};

  void init() {  // build the tree
    for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
  }

  void ptUpdate(int p) {  // set value at position p
    for (t[p += n]++; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
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
string s;

ll solve() {
  ll res = 0;
  int right = n - 1;
  map<char, stack<int> > loc;
  SegTree st;
  st.init();
  for (int i=0;i<n;i++) {
    loc[s[i]].push(i);
  }
  int p[n];
  int pos[n];
  for (int i=n-1;i>=0;i--) {
    p[loc[s[n-1-i]].top()] = i;
    pos[i] = loc[s[n-1-i]].top();
    loc[s[n-1-i]].pop();
  }
  //for (int i=0;i<n;i++) cout << pos[i] << (i == n-1 ? "\n" : " ");
  for (int i=0;i<n;i++) {
    //cout << res << "\n";
    res += st.rngSum(pos[i]+1, n);
    st.ptUpdate(pos[i]);
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  cin >> s;
  cout << solve() << "\n";
  return 0;
}
