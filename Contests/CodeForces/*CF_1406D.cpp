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

int n;
int a[100001];
ll diffs[100001];
ll ans;
ll first;
ll k;

int update(int l, int r, int x) {
  if (l == 1) {
    first += x;
  } else {
    k -= max((ll)0, diffs[l-1]);
    diffs[l-1] += x;
    k += max((ll)0, diffs[l-1]);
  }
  if (r != n) {
    k -= max((ll)0, diffs[r]);
    diffs[r] += -1 * x;
    k += max((ll)0, diffs[r]);
  }
  //cout << k << endl;
  //for (int i=1;i<n;i++) cout << diffs[i] << (i == n-1 ? "\n" : " ");
  if (k + first >= 0)
    ans = (k + first + 1) / 2;
  else ans = (k + first) / 2;
  return 0;
}

int solve() {
  ll res = 0;
  for (int i=1;i<n;i++) {
    res += max(0, a[i] - a[i-1]);
    diffs[i] = a[i] - a[i-1];
  }
  first = a[0];
  k = res;
  if (k + first >= 0)
    ans = (k + a[0] + 1) / 2;
  else ans = (k + a[0]) / 2;
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int q;
  cin >> n;
  for (int i=0;i<n;i++) cin >> a[i];
  solve();
  cout << ans << "\n";
  cin >> q;
  for (int i=0;i<q;i++) {
    int l, r, x;
    cin >> l >> r >> x;
    update(l, r, x);
    cout << ans << "\n";
  }
  return 0;
}
