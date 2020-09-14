#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

typedef long long ll;

using namespace std;

ll n, k, m;

ll try_x(ll x) {
  //cout << "test " << x << endl;
  ll g = 0; ll cnt = 0;
  while (g < n && cnt < k) {
    ll y = (n - g) / x;
    if (y < m)
      break;
    ll ymatch = n - x * y;
    ll days = (ymatch - g) / y + 1;
    g += y * days;
    cnt += days;
    //cout << g << endl;
  }
  if (cnt == k && g < n) return k+1;
  if (n > g) cnt += (n - g) / m;
  return cnt;
}

ll bin_sch(ll l, ll r) {
  ll ans = l;
  while (l < r) {
    ll m = (l + r) / 2;
    ll res = try_x(m);
    if (res > k)
      r = m;
    else if (res <= k) {
      l = m + 1;
      ans = m;
    }
  }
  return ans;
}

ll solve() {
  return bin_sch(1, n / m);
}

int main() {
  ofstream cout ("loan.out");
  ifstream cin ("loan.in");
  cin >> n >> k >> m;
  cout << solve() << endl;
  return 0;
}
