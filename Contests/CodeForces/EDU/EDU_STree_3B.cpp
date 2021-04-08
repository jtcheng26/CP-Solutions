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

  int findX(int x, int index, int l, int r) {
    //cout << l << " " << sums[index] << endl;
    if (r - l == 1) return l;
    int mid = (l + r) / 2;
    if (sums[2 * index + 2] > x)
      return findX(x, 2 * index + 2, mid, r);
    else
      return findX(x - sums[2 * index + 2], 2 * index + 1, l, mid);
  }

  int findX(int x) {
    return findX(x, 0, 0, n);
  }

};

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  vector<int> arr; arr.resize(n);
  for (int i=0;i<n;i++) arr[i] = 1;
  SegTree st;
  st.init(arr);
  for (int i=0;i<n;i++) {
    cin >> arr[i];
  }
  vector<int> ans;
  for (int i=n-1;i>=0;i--) {
    int res = st.findX(arr[i]);
    ans.pb(res + 1);
    st.ptUpdate(res, 0);
  }
  for (int i=n-1;i>0;i--) {
    cout << ans[i] << " ";
  }
  cout << ans[0] << endl;
  return 0;
}
