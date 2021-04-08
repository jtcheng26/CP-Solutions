#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INF 1000000001
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;
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

int n;

ll solve() {
  int k = (n * (n + 1)) / 2;
  if (k % 2 == 1) return 0;
  k = k / 2;
  ll dp[k+1];
  for (int i=0;i<=k;i++) dp[i] = 0;
  dp[0] = 1;
  for (int i=1;i<=n;i++) {
    for (int j=k;j>=i;j--) {
      dp[j] = (dp[j] + dp[j-i]) % MOD;
    }
  }
  return (dp[k] * modInverse(2, MOD)) % MOD;
}

int main() {
  cin >> n;
  cout << solve() << endl;
  return 0;
}
