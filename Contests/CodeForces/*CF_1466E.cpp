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
#define MOD 1000000007

typedef uint64_t ll;

using namespace std;

int n;
ll a[500001];

ll solve() {
  ll res = 0;
  ll isSet[64] = {0};
  for (ll i = 0; i <= 60; i++) {
      for (ll j = 0; j < n; j++)
        if ((a[j] & (1ULL << i)))
          isSet[i]++;
  }
  for (ll i=0;i<n;i++) {
    ll sumA = 0;
    ll sumO = 0;
    for (ll k=0;k<=60;k++) {
      ll s = (1ULL << k) % MOD;
      if (a[i] & (1ULL << k)) {
        sumA = (sumA + (s * (isSet[k])) % MOD) % MOD;
        sumO = (sumO + (s * n) % MOD) % MOD;
      } else if (isSet[k]) {
        sumO = (sumO + (s * isSet[k]) % MOD) % MOD;
      }
    }
    sumA %= MOD;
    sumO %= MOD;
    res = (res + ((sumA * sumO) % MOD) % MOD) % MOD;
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
