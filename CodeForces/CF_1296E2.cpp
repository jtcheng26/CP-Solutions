#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INFI 1e18+7
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long ll;

using namespace std;

struct SegTree {
  int sum;
  int n;
  vector<pair<int, int> > maxs;

  void init(int* arr, int rng_size) {
    int sz = 1;
    n = rng_size + 1;
    while (sz < n) sz *= 2;
    maxs.resize(sz * 2);
    build(arr, 0, 0, n);
  }

  // r is non-inclusive
  void build(int* arr, int index, int l, int r) {
    //cout << leftmost << " " << rightmost << endl;
    if (r - l == 1) {
      if (l < (ll) n) {
        maxs[index] = mp(arr[l], l);
      }
      return;
    }
    int mid = (l + r) / 2;
    int lchild = 2 * index + 1;
    int rchild = 2 * index + 2;
    build(arr, lchild, l, mid); // left child
    build(arr, rchild, mid, r); // right child
    maxs[index] = max(maxs[lchild], maxs[rchild]);
  }

  void ptUpdate(int rngIndex, int index, ll value, int l, int r) {
    if (rngIndex > r - 1 || rngIndex < l) return;
    if (r - l == 1) {
      maxs[index].F = value;
      return;
    }
    int mid = (l + r) / 2;
    ptUpdate(rngIndex, 2 * index + 1, value, l, mid);
    ptUpdate(rngIndex, 2 * index + 2, value, mid, r);
    maxs[index] = max(maxs[2 * index + 1], maxs[2 * index + 2]);
  }

  void ptUpdate(int index, ll value) {
    ptUpdate(index, 0, value, 0, n);
  }

  pair<int, int> maxQ(int rngl, int rngr, int index, int l, int r) {
    if (rngr < l || rngl >= r) return make_pair(-1, 0);
    if (rngr >= r - 1 && rngl <= l) {
      return maxs[index];
    }
    int mid = (l + r) / 2;
    pair<int, int> lmid = maxQ(rngl, rngr, 2 * index + 1, l, mid);
    pair<int, int> rmid = maxQ(rngl, rngr, 2 * index + 2, mid, r);
    return max(lmid, rmid);
  }

  pair<int, int> maxQ(int l, int r) {
    return maxQ(l, r, 0, 0, n);
  }

};

int n;
char s[200001];
int res[200001];

int solve() {
  int dp[n];
  int mxdp[26] = {0};
  SegTree st;
  int cnt = 0;
  for (int i=0;i<n;i++) dp[i] = 1;
  st.init(mxdp, 26);
  for (int i=0;i<n;i++) {
    dp[i] = max(dp[i], st.maxQ(s[i] - 'a' + 1, 25).F + 1);
    st.ptUpdate(s[i] - 'a', dp[i]);
    cnt = max(cnt, dp[i]);
  }
  for (int i=0;i<n;i++) res[i] = dp[i];
  return cnt;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  for (int i=0;i<n;i++) cin >> s[i];
  cout << solve() << endl;
  for (int i=0;i<n;i++) cout << res[i] << (i == n-1 ? "\n" : " ");
  return 0;
}
