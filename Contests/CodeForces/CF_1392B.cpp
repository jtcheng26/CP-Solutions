#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INFI 1e18 + 7

typedef long long ll;

using namespace std;

ll n, k;
ll a[2][200001];

bool solve() {
  ll mx = -1 * INFI;
  if (n == 1) {
    a[0][0] = 0;
    return true;
  }
  for (int i=0;i<n;i++) {
    mx = max(mx, a[0][i]);
  }
  ll mx2 = -1 * INFI;
  for (int i=0;i<n;i++) {
    a[0][i] = mx - a[0][i];
    mx2 = max(mx2, a[0][i]);
  }
  for (int i=0;i<n;i++) {
    a[1][i] = mx2 - a[0][i];
  }
  return k % 2 != 0;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (int i=0;i<n;i++) {
      cin >> a[0][i];
    }
    bool res = solve();
    int idx = res ? 0 : 1;
    for (int i=0;i<n-1;i++) {
      cout << a[idx][i] << " ";
    }
    cout << a[idx][n-1] << endl;
  }
  return 0;
}
