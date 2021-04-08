#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

#define mp make_pair
#define pb push_back
#define F first
#define S second

typedef long long ll;

using namespace std;

struct SegTree {
  int n = 100001;  // array size
  int t[200002] = {0};

  void init() {  // build the tree
    for (int i = n - 1; i > 0; --i) t[i] = max(t[i<<1], t[i<<1|1]);
  }

  int rngMax(int l, int r) {  // sum on interval [l, r)
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) res = max(res, t[l++]);
      if (r&1) res = max(res, t[--r]);
    }
    return res;
  }
};

int n;
ll m;
int flavor[100001];
SegTree s;

int solve() {
  int res = 1000000001;
  int l = 0;
  int r = 1;
  ll sum = flavor[0];
  while (r <= n) {
    while (sum >= m && l < n) {
      res = min(res, s.rngMax(l, r));
      //cout << l << " " << r << " " << s.rngMax(l, r) << "\n";
      sum -= flavor[l];
      l++;
    }
    sum += flavor[r];
    r++;
  }
  return res;
}

int main() {
  ofstream cout ("hayfeast.out");
  ifstream cin ("hayfeast.in");
  cin >> n >> m;
  for (int i=0;i<n;i++) {
    cin >> flavor[i] >> s.t[i+s.n];
  }
  s.init();
  cout << solve() << "\n";
  return 0;
}
