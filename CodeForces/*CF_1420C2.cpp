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
ll a[300003];
bool is_max[300003];
bool is_min[300003];
ll res;

ll update(int l, int r) {
  //cout << "QUERY " << l <<  " " << r << "\n";
  int temp = a[r];
  for (int i=l-1;i<=l+1;i++) {
    if (i == 0 || i == n+1) continue;
    if (is_max[i])
      res -= a[i];
    if (is_min[i])
      res += a[i];
    is_max[i] = false;
    is_min[i] = false;
  }
  for (int i=r-1;i<=r+1;i++) {
    if (i == 0 || i == n+1) continue;
    if (is_max[i])
      res -= a[i];
    if (is_min[i])
      res += a[i];
    is_max[i] = false;
    is_min[i] = false;
  }
  a[r] = a[l];
  a[l] = temp;
  for (int i=l-1;i<=l+1;i++) {
    if (i == 0 || i == n+1) continue;
    if (a[i] > a[i-1] && a[i] > a[i+1]) {
      is_max[i] = true;
      res += a[i];
    }
    if (a[i] < a[i-1] && a[i] < a[i+1]) {
      is_min[i] = true;
      res -= a[i];
    }
  }
  for (int i=r-1;i<=r+1;i++) {
    if (i == 0 || i == n+1) continue;
    if (!is_max[i] && a[i] > a[i-1] && a[i] > a[i+1]) {
      is_max[i] = true;
      res += a[i];
    }
    if (!is_min[i] && a[i] < a[i-1] && a[i] < a[i+1]) {
      is_min[i] = true;
      res -= a[i];
    }
  }
  //for (int i=1;i<=n;i++) cout << a[i] << (i == n ? "\n" : " ");
  return res;
}

ll solve() {
  ll odds = 0;
  ll evens = 0;
  a[0] = -1; a[n+1] = -1;
  is_max[0] = false;
  is_min[n+1] = false;
  for (int i=1;i<=n;i++) {
    is_max[i] = false;
    is_min[i] = false;
    if (a[i] > a[i-1] && a[i] > a[i+1]) {
      is_max[i] = true;
      odds += a[i];
    }
    if (a[i] < a[i-1] && a[i] < a[i+1]) {
      is_min[i] = true;
      evens += a[i];
    }
  }
  res = odds - evens;
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    //cout << "NEW CASE" << "\n";
    cin >> n >> q;
    for (int i=1;i<=n;i++) cin >> a[i];
    cout << solve() << "\n";
    for (int i=0;i<q;i++) {
      int l, r;
      cin >> l >> r;
      cout << update(l, r) << "\n";
    }
  }
  return 0;
}
