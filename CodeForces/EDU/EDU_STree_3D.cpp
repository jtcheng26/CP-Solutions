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
  vector<int> maxDist;

  void init(vector<int> &rng) {
    int sz = 1;
    n = rng.size();
    while (sz < n) sz *= 2;
    sums.resize(sz * 2);
    maxDist.resize(sz * 2);
    build(rng, 0, 0, n);
  }

  // r is non-inclusive
  void build(vector<int> &rng, int index, int l, int r) {
    //cout << leftmost << " " << rightmost << endl;
    if (r - l == 1) {
      if (l < (ll) rng.size()) {
        sums[index] = rng[l];
        maxDist[index] = n - l - 1;
      }
      return;
    }
    int mid = (l + r) / 2;
    int lchild = 2 * index + 1;
    int rchild = 2 * index + 2;
    build(rng, lchild, l, mid); // left child
    build(rng, rchild, mid, r); // right child
    sums[index] = sums[lchild] + sums[rchild];
    maxDist[index] = max(maxDist[lchild], maxDist[rchild]);
  }

  void ptUpdate(int rngIndex, int index, int value, int l, int r) {
    if (rngIndex > r - 1 || rngIndex < l) return;
    if (r - l == 1) {
      sums[index] = value;
      maxDist[index] = 0;
      return;
    }
    int mid = (l + r) / 2;
    int lchild = 2 * index + 1;
    int rchild = 2 * index + 2;
    ptUpdate(rngIndex, lchild, value, l, mid);
    ptUpdate(rngIndex, rchild, value, mid, r);
    sums[index] = sums[lchild] + sums[rchild];
    maxDist[index] = max(maxDist[lchild], maxDist[rchild]);
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
  vector<int> arr; arr.resize(2 * n);
  SegTree st;
  st.init(arr);
  int start[200001]; // leftmost occurrence of x
  int ans[200001];
  for (int i=0;i<2 * n;i++) {
    cin >> arr[i];
    start[arr[i]] = -1;
    ans[i] = 0;
  }
  for (int i=0;i<2 * n;i++) {
    if (start[arr[i]] == -1) {
      start[arr[i]] = i;
      continue;
    }
    ans[arr[i]] = (i - start[arr[i]] - 1) - 2 * st.rngSum(start[arr[i]], i);
    st.ptUpdate(start[arr[i]], 1);
  }
  for (int i=1;i<n;i++) {
    cout << ans[i] << " ";
  }
  cout << ans[n] << endl;
  return 0;
}
