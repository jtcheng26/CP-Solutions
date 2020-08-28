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
  vector<pair<int, int> > mins;

  void init(int* arr, int rng_size) {
    int sz = 1;
    n = rng_size + 1;
    while (sz < n) sz *= 2;
    mins.resize(sz * 2);
    build(arr, 0, 0, n);
  }

  // r is non-inclusive
  void build(int* arr, int index, int l, int r) {
    //cout << leftmost << " " << rightmost << endl;
    if (r - l == 1) {
      if (l < (ll) n) {
        mins[index] = mp(arr[l], l);
      }
      return;
    }
    int mid = (l + r) / 2;
    int lchild = 2 * index + 1;
    int rchild = 2 * index + 2;
    build(arr, lchild, l, mid); // left child
    build(arr, rchild, mid, r); // right child
    mins[index] = min(mins[lchild], mins[rchild]);
  }

  pair<int, int> minQ(int rngl, int rngr, int index, int l, int r) {
    if (rngr < l || rngl >= r) return make_pair(1000000007, 0);
    if (rngr >= r - 1 && rngl <= l) {
      return mins[index];
    }
    int mid = (l + r) / 2;
    pair<int, int> lmid = minQ(rngl, rngr, 2 * index + 1, l, mid);
    pair<int, int> rmid = minQ(rngl, rngr, 2 * index + 2, mid, r);
    return min(lmid, rmid);
  }

  pair<int, int> minQ(int l, int r) {
    return minQ(l, r, 0, 0, n);
  }

};

int n;
int a[5003];
SegTree st;

int sch(int l, int r) {
  if (l > r) return 0;
  pair<int, int> minimum = st.minQ(l, r);
  int prev_min = max(a[l-1], a[r+1]);
  int min_num = minimum.F;
  int min_index = minimum.S;
  //cout << min_num << endl;
  return min(r - l + 1, sch(l, min_index - 1) + sch(min_index + 1, r) + (min_num - prev_min));
}

int solve() {
  a[0] = 0;
  a[n+1] = 0;
  return sch(1, n);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  for (int i=1;i<=n;i++) cin >> a[i];
  st.init(a, n+1);
  cout << solve() << endl;
  return 0;
}
