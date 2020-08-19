#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define MOD 1000000007

typedef long long ll;

using namespace std;

int n;
vector<ll> facts;

ll factorial(int f) {
  if (facts.size() > 0 && facts[f] != 0) return facts[f];
  if (f == 0) return 1;
  facts.push_back(1);
  ll ans = 1;
  for (int i=1;i<=f;i++) {
    ans *= i;
    ans %= MOD;
    facts.push_back(ans);
  }
  return ans;
}

ll power(ll x, ll y, ll p) {
 ll res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1)
      res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}

ll modInverse(ll n, ll p) {
  return power(n, p - 2, p);
}

ll solve() {
  ll res = factorial(n);
  //cout << res << endl;
  ll sub = 0; // sorted up/down
  for (int i=1;i<=n;i++) { // for every position of max num
    int k = max(i - 1, n - i);
    sub += (factorial(n-1) * modInverse(factorial(k), MOD) % MOD * modInverse(factorial(n - 1 - k), MOD)) % MOD;
    sub %= MOD;
  }
  //sub %= MOD;
  //cout << sub << endl;
  return (res - sub + MOD) % MOD;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  cout << solve() << endl;
  return 0;
}
