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

int n, k;

ll solve() {
  ll l = 0; ll r = 10000000000;
  ll res = 0;
  while (l < r) {
    ll mid = (l + r) / 2;
    ll num = mid - (mid / n);
    if (num > k) {
      r = mid;
    } else if (num < k) {
      l = mid + 1;
    } else {
      res = mid;
      r = mid;
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    cout << solve() << endl;
  }
  return 0;
}
