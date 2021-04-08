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

int n, q;
int a[100001];
map<int, bool> poss;
ll pfx[100001];

bool query(int s) {
  return poss[s];
}

void rec(int l, int r) {
  if (l > r) return;
  ll mid = (a[l] + a[r]) / 2;
  int l2 = l;
  if (pfx[r] - (l > 0 ? pfx[l-1] : 0) <= 1000000000)
    poss[pfx[r] - (l > 0 ? pfx[l-1] : 0)] = true;
  while (a[l2] <= mid && l2 <= r) l2++;
  if (l2 == r+1) return;
  rec(l2, r);
  rec(l, l2 - 1);
}

void solve() {
  sort(a, a+n);
  pfx[0] = a[0];
  for (int i=1;i<n;i++) {
    pfx[i] = pfx[i-1] + a[i];
  }
  rec(0, n-1);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    poss.clear();
    cin >> n >> q;
    for (int i=0;i<n;i++) cin >> a[i];
    solve();
    for (int i=0;i<q;i++) {
      int s;
      cin >> s;
      cout << (query(s) ? "Yes" : "No") << "\n";
    }
  }
  return 0;
}
