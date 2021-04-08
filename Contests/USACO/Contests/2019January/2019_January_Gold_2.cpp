#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define mp make_pair
#define pb push_back
#define F first
#define S second

typedef long long ll;

using namespace std;

struct SegTree {
  int n = 1000001;  // array size
  int t[2000002] = {0};

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
int cows[100001];
SegTree st;
vector<int> ans;

int solve() {
  queue<int> inside; // unsorted
  int left = -1;
  for (int i=1;i<n;i++) {
    if (cows[i] < cows[i-1])
      left = i;
  }
  if (left == -1) return 0;
  for (int i=0;i<left;i++) {
    inside.push(cows[i]);
  }
  st.init();
  for (int i=left;i<n;i++) {
    st.ptUpdate(cows[i], 1);
  }
  while (inside.size() > 0) {
    int top = inside.front();
    inside.pop();
    ans.pb(inside.size() + st.rngSum(0, top));
    st.ptUpdate(top, 1);
  }
  return 0;
}

int main() {
  ofstream cout ("sleepy.out");
  ifstream cin ("sleepy.in");
  cin >> n;
  for (int i=0;i<n;i++) cin >> cows[i];
  solve();
  cout << ans.size() << "\n";
  for (int i=0;i<ans.size();i++) {
    cout << ans[i] << (i==ans.size()-1 ? "\n" : " ");
  }
  return 0;
}
