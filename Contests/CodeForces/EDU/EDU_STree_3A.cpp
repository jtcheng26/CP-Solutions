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
  vector<int> maxElem;

  void init(vector<int> &rng) {
    int sz = 1;
    n = rng.size();
    while (sz < n) sz *= 2;
    sums.resize(sz * 2);
    maxElem.resize(sz * 2);
    build(rng, 0, 0, n);
  }

  // r is non-inclusive
  void build(vector<int> &rng, int index, int l, int r) {
    //cout << leftmost << " " << rightmost << endl;
    if (r - l == 1) {
      if (l < (ll) rng.size()) {
        sums[index] = rng[l];
        maxElem[index] = rng[l];
      }
      return;
    }
    int mid = (l + r) / 2;
    int lchild = 2 * index + 1;
    int rchild = 2 * index + 2;
    build(rng, lchild, l, mid); // left child
    build(rng, rchild, mid, r); // right child
    sums[index] = sums[lchild] + sums[rchild];
    maxElem[index] = max(maxElem[lchild], maxElem[rchild]);
  }

  void ptUpdate(int rngIndex, int index, int value, int l, int r) {
    if (rngIndex > r - 1 || rngIndex < l) return;
    if (r - l == 1) {
      sums[index] = value;
      maxElem[index] = value;
      return;
    }
    int mid = (l + r) / 2;
    int lchild = 2 * index + 1;
    int rchild = 2 * index + 2;
    ptUpdate(rngIndex, lchild, value, l, mid);
    ptUpdate(rngIndex, rchild, value, mid, r);
    sums[index] = sums[lchild] + sums[rchild];
    maxElem[index] = max(maxElem[lchild], maxElem[rchild]);
  }

  void ptUpdate(int index, int value) {
    ptUpdate(index, 0, value, 0, n);
  }

  ll rngSum(int rngl, int rngr, int index, int l, int r) {
    if (rngr < l || r <= rngl) return 0;
    if (rngr >= r - 1 && rngl <= l) return sums[index];
    //cout << leftmost << " " << rightmost << endl;
    int mid = (l + r) / 2;
    ll lsum = rngSum(rngl, rngr, 2 * index + 1, l, mid);
    ll rsum = rngSum(rngl, rngr, 2 * index + 2, mid, r);
    return lsum + rsum;
  }

  ll rngSum(int l, int r) {
    return rngSum(l, r, 0, 0, n);
  }

};

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  vector<int> arr; arr.resize(n);
  SegTree st;
  st.init(arr);
  for (int i=0;i<n;i++) {
    cin >> arr[i];
  }
  for (int i=0;i<n-1;i++) {
    cout << st.rngSum(arr[i] - 1, n) << " ";
    st.ptUpdate(arr[i] - 1, 1);
  }
  cout << st.rngSum(arr[n-1] - 1, n) << endl;
  return 0;
}
