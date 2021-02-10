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

int n, m, k;

ll solve() {
  ll dp[n+1];
  ll pfxDP[n + 1];
  for (int i=0;i<=n;i++) {
    dp[i] = 0;
    pfxDP[i] = 0;
  }
  dp[0] = 1;
  pfxDP[0] = 1;
  for (int i=1;i<k;i++) {
    dp[i] = (dp[i-1] * m) % MOD;
    pfxDP[i] = (pfxDP[i-1] + dp[i]) % MOD;
  }
  for (int i=k;i<=n;i++) {
    dp[i] = (dp[i] + (pfxDP[i-1] - pfxDP[i - k] + MOD) % MOD) % MOD;
    dp[i] = (dp[i] * (m - 1)) % MOD;
    pfxDP[i] = (pfxDP[i-1] + dp[i]) % MOD;
  }
  ll tot = m;
  for (int i=1;i<n;i++) {
    tot = (tot * m) % MOD;
  }
  return ((tot - dp[n]) + MOD) % MOD;
}

int main() {
  ofstream cout ("spainting.out");
  ifstream cin ("spainting.in");
  cin >> n >> m >> k;
  cout << solve() << "\n";
  return 0;
}
