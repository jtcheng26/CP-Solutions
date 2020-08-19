#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

typedef long long ll;

using namespace std;

struct stree {

  int size;
  vector<ll> sums;

  void init(int n) {
    size = 1;
    while (size < n) size *= 2;
    sums.resize(2 * size);
  }

  void build(vector<ll> &a, int x, int lx, int rx) {
    if (rx - lx == 1) {
      if (lx < (int) a.size())
        sums[x] = a[lx];
      return;
    }
    int m = (lx + rx) / 2;
    build(a, 2 * x + 1, lx, m);
    build(a, 2 * x + 2, m, rx);
    sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
  }

  void build(vector<ll> &a) {
    build(a, 0, 0, size);
  }

  void set(int i, int v, int x, int lx, int rx) {
    if (rx - lx == 1) {
      sums[x] = v;
      return;
    }
    int m = (lx + rx) / 2;
    if (i < m) {
      set(i, v, 2 * x + 1, lx, m);
    } else {
      set(i, v, 2 * x + 2, m, rx);
    }
    sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
  }

  void set(int i, int v) {
    set(i, v, 0, 0, size);
  }

  ll sum (int l, int r, int x, int lx, int rx) {
    if (lx >= r || rx <= l) return 0;
    if (lx >= l && rx <= r) return sums[x];
    int m = (lx + rx) / 2;
    ll s1 = sum(l, r, 2 * x + 1, lx, m);
    ll s2 = sum(l, r, 2 * x + 2, m, rx);
    return s1 + s2;
  }

  ll sum(int l, int r) {
    return sum(l, r, 0, 0, size);
  }

};

int main() {
  int n, m;
  cin >> n >> m;
  stree s;
  s.init(n);
  vector<ll> arr; arr.resize(n);
  for (int i=0;i<n;i++) {
    cin >> arr[i];
  }
  s.build(arr);
  while (m--) {
    int op, i, v;
    cin >> op;
    if (op == 1) {
      cin >> i >> v;
      s.set(i, v);
    } else {
      cin >> i >> v;
      cout << s.sum(i, v) << endl;
    }
  }
  return 0;
}
