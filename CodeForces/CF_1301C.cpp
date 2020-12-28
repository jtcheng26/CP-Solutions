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

ll n, m;

ll solve() {
  ll res = (n * (n + 1)) / 2;
  if (m == 0) return 0;
  if (n == m) return res;
  if ((n % 2 == 0 && m < n / 2) || (n % 2 == 1 && m <= n / 2)) {
    ll zeroes = n - m;
    ll divisions = m + 1;
    if (zeroes % divisions == 0) {
      res -= divisions * (zeroes / divisions) * (zeroes / divisions + 1) / 2;
    } else {
      res -= (zeroes % divisions) * (zeroes / divisions + 1) * (zeroes / divisions + 2) / 2;
      res -= (divisions - zeroes % divisions) * (zeroes / divisions) * (zeroes / divisions + 1) / 2;
    }
  } else if (m >= n / 2) {
    res -= n - m;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    cout << solve() << "\n";
  }
  return 0;
}
