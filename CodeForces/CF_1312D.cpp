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

int n, m;
ll factorial[200001];
ll twoPow[200001];

// C function for extended Euclidean Algorithm
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
    // m is added to handle negative x
    int res = (x%m + m) % m;
    return res;
  }
}

void precompute() {
  factorial[0] = 1;
  twoPow[0] = 1;
  for (int i=1;i<=max(n, m);i++) {
    factorial[i] = (factorial[i-1] * i) % MOD;
    twoPow[i] = (2 * twoPow[i-1]) % MOD;
  }
}

ll choose(int n, int r) {
  return (factorial[n] * modInverse((factorial[r] * factorial[n - r]) % MOD, MOD)) % MOD;
}

ll solve() {
  precompute();
  ll res = 0;
  for (int i=n-1;i<=m;i++) {
    res = (res + (((choose(i - 1, n - 2) * twoPow[n - 3]) % MOD) * (n - 2)) % MOD) % MOD;
    //cout << res << "\n";
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n >> m;
  cout << solve() << "\n";
  return 0;
}
