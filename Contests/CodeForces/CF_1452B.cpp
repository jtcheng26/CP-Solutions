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
ll a[100001];

ll solve() {
  ll tot = 0;
  ll mx = 0;
  for (int i=0;i<n;i++) {
    tot += a[i];
    mx = max(mx, a[i]);
  }
  return (n - 1) * max((tot + n - 2) / (n - 1), mx) - tot;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    cout << solve() << "\n";
  }
  return 0;
}
