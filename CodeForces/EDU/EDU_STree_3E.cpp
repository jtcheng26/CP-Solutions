#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INFI 1e18+7
#define pb push_back
#define F first
#define S second

typedef long long ll;

using namespace std;

int n, m;

struct SegTree {
  int sum;
  int n;
  vector<ll> sums;
  vector<ll> add;

  void init(vector<int> &rng) {
    int sz = 1;
    n = rng.size();
    while (sz < n) sz *= 2;
    sums.resize(sz * 2);
    add.resize(sz * 2);
    build(rng, 0, 0, n);
  }

  // r is non-inclusive
  void build(vector<int> &rng, int index, int l, int r) {
    //cout << leftmost << " " << rightmost << endl;
    if (r - l == 1) {
      if (l < (ll) rng.size()) {
        sums[index] = rng[l];
        add[index] = 0;
      }
      return;
    }
    int mid = (l + r) / 2;
    int lchild = 2 * index + 1;
    int rchild = 2 * index + 2;
    build(rng, lchild, l, mid); // left child
    build(rng, rchild, mid, r); // right child
    sums[index] = sums[lchild] + sums[rchild];
  }

  void rngAdd(int a, int rngl, int rngr, int index, int l, int r) {
    //cout << "add" << endl;
    if (l > rngr || r <= rngl) return;
    if (r - l == 1) {
      add[index] += a;
      //cout << a << " add ind " << endl;
      return;
    }
    if (l >= rngl && r - 1 <= rngr) {
      //cout << a <<  " add " << endl;
      add[index] += a;
      return;
    }
    int mid = (l + r) / 2;
    rngAdd(a, rngl, rngr, 2 * index + 1, l, mid);
    rngAdd(a, rngl, rngr, 2 * index + 2, mid, r);
  }

  void rngAdd(int l, int r, int v) {
    rngAdd(v, l, r - 1, 0, 0, n);
  }

  ll getElement(int goal, int index, int l, int r) {
    //cout << "get" << endl;
    if (r - l == 1) return sums[index] + add[index];
    int mid = (l + r) / 2;
    if (goal < mid) return add[index] + getElement(goal, 2 * index + 1, l, mid);
    else return add[index] + getElement(goal, 2 * index + 2, mid, r);
  }

  ll getElement(int index) {
    return getElement(index, 0, 0, n);
  }

};

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n >> m;
  vector<int> arr; arr.resize(n);
  SegTree st;
  st.init(arr);
  for (int i=0;i<m;i++) {
    int tp, a, b, c;
    cin >> tp >> a;
    if (tp == 2)
      cout << st.getElement(a) << endl;
    else {
      cin >> b >> c;
      st.rngAdd(a, b, c);
    }
  }
  return 0;
}
