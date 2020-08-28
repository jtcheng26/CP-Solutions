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
  vector<ll> mins;

  void init(vector<ll> &rng) {
    int sz = 1;
    n = rng.size();
    while (sz < n) sz *= 2;
    sums.resize(sz * 2);
    mins.resize(sz * 2);
    build(rng, 0, 0, n);
  }

  // r is non-inclusive
  void build(vector<ll> &rng, int index, int l, int r) {
    //cout << leftmost << " " << rightmost << endl;
    if (r - l == 1) {
      if (l < (ll) rng.size()) {
        sums[index] = rng[l];
        mins[index] = rng[l];
      }
      return;
    }
    int mid = (l + r) / 2;
    build(rng, 2 * index + 1, l, mid); // left child
    build(rng, 2 * index + 2, mid, r); // right child
    sums[index] = sums[2 * index + 1] + sums[2 * index + 2];
    mins[index] = min(mins[2 * index + 1], mins[2 * index + 2]);
  }

  void ptUpdate(int rngIndex, int index, ll value, int l, int r) {
    if (rngIndex > r - 1 || rngIndex < l) return;
    if (r - l == 1) {
      sums[index] = value;
      mins[index] = value;
      return;
    }
    int mid = (l + r) / 2;
    ptUpdate(rngIndex, 2 * index + 1, value, l, mid);
    ptUpdate(rngIndex, 2 * index + 2, value, mid, r);
    sums[index] = sums[2 * index + 1] + sums[2 * index + 2];
    mins[index] = min(mins[2 * index + 1], mins[2 * index + 2]);
  }

  void ptUpdate(int index, ll value) {
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

  ll minQ(int rngl, int rngr, int index, int l, int r) {
    if (rngr < l || rngl >= r) return (ll)INFI;
    if (rngr >= r - 1 && rngl <= l) return mins[index];
    int mid = (l + r) / 2;
    ll lmid = minQ(rngl, rngr, 2 * index + 1, l, mid);
    ll rmid = minQ(rngl, rngr, 2 * index + 2, mid, r);
    return min(lmid, rmid);
  }

  ll minQ(int l, int r) {
    return minQ(l, r, 0, 0, n);
  }
};

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n >> m;
  vector<ll> arr; arr.resize(n);
  for (int i=0;i<n;i++) {
    cin >> arr[i];
  }
  SegTree st;
  st.init(arr);
  for (int i=0;i<m;i++) {
    int tp, a, b;
    cin >> tp >> a >> b;
    if (tp == 1) {
      st.ptUpdate(a, b);
    } else {
      ll res = st.minQ(a, b - 1);
      cout << res << endl;
    }
  }
  return 0;
}
