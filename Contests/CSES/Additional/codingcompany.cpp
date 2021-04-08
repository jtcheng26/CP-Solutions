#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INF 1000000001
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

int n, x;
int a[101];

int solve() {
  sort(a, a+n);
  ll dp[2][n+1][10001];
  for (int i=0;i<2;i++) {
    for (int j=0;j<=n;j++) {
      for (int k=0;k<=10000;k++) {
        dp[i][j][k] = 0;
      }
    }
  }
  dp[0][0][5000] = 1;
  for (int i=0;i<n;i++) {
    for (int j=0;j<=i+1;j++) {
      for (int k=0;k<=10000;k++) {
        dp[1][j][k] = (dp[1][j][k] + dp[0][j][k]) % MOD;
        dp[1][j][k] = (dp[1][j][k] + (j * dp[0][j][k]) % MOD) % MOD;
        if (j < n && k - a[i] >= 0)
          dp[1][j][k] = (dp[1][j][k] + ((j+1) * dp[0][j+1][k - a[i]]) % MOD) % MOD;
        if (j > 0 && k + a[i] <= 10000)
          dp[1][j][k] = (dp[1][j][k] + dp[0][j-1][k + a[i]]) % MOD;
      }
    }
    for (int j=0;j<=i+1;j++) {
      for (int k=0;k<=10000;k++) {
        dp[0][j][k] = dp[1][j][k];
        dp[1][j][k] = 0;
      }
    }
  }
  ll res = 0;
  for (int k=5000;k<=5000+x;k++) {
    res = (res + dp[0][0][k]) % MOD;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n >> x;
  for (int i=0;i<n;i++) cin >> a[i];
  cout << solve() << "\n";
  return 0;
}
