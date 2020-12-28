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
#define MOD 998244353

typedef long long ll;

using namespace std;

int gcdExtended(int a, int b, int *x, int *y) {
  if (a == 0) {
    *x = 0, *y = 1;
    return b;
  }
  int x1, y1;
  int gcd = gcdExtended(b%a, a, &x1, &y1);
  *x = y1 - (b/a) * x1;
  *y = x1;
  return gcd;
}

int modInverse(int a, int m) {
  int x, y;
  int g = gcdExtended(a, m, &x, &y);
  if (g != 1)
    return -1;
  else {
    int res = (x%m + m) % m;
    return res;
  }
}

int n;
ll twoPow[200001];

void precompute() {
  twoPow[0] = 1;
  for (int i=1;i<=n;i++)
    twoPow[i] = (twoPow[i-1] * 2) % MOD;
}

ll solve() {
  precompute();
  ll prev = 0;
  ll res = 1;
  for (int i=2;i<=n;i++) {
    ll curr = res;
    res = (prev + res) % MOD;
    prev = curr;
  }
  return (res * modInverse(twoPow[n], MOD)) % MOD;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  cout << solve() << "\n";
  return 0;
}
