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
int a[200001];

ll solve() {
  ll res = 0;
  pair<ll, int> best = mp(0, 0); // 0 = set to i - 1, 1 = set to i + 1
  for (int i=0;i<n;i++) {
    ll diff = 0;
    if (i == 0) {
      diff = abs(a[i] - a[i+1]);
    } else if (i == n-1) {
      diff = abs(a[i] - a[i-1]);
    } else {
      if ((a[i] >= a[i-1] && a[i] <= a[i+1]) || (a[i] <= a[i-1] && a[i] >= a[i+1]))
        continue;
      else
        diff = 2 * min(abs(a[i] - a[i-1]), abs(a[i] - a[i+1]));
    }
    if (diff > best.F) {
      best.F = diff;
      best.S = i;
    }
  }
  a[best.S] = best.S > 0 ? a[best.S-1] : a[best.S+1];
  for (int i=n-2;i>=0;i--) {
    res += abs(a[i] - a[i+1]);
  }
  return res;
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
