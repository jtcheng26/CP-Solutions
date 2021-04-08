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

int n, m;
int a[100001];

int solve() {
  ll dp[n][m + 2];
  for (int i=1;i<n;i++) {
    dp[i][0] = 0;
    for (int j=1;j<=m;j++) {
      dp[i][j] = 0;
    }
    dp[i][m + 1] = 0;
  }
  dp[0][0] = 0;
  dp[0][m + 1] = 0;
  for (int j=1;j<=m;j++) {
    if (a[0] == 0)
      dp[0][j] = 1;
    else if (a[0] == j)
      dp[0][j] = 1;
    else
      dp[0][j] = 0;
  }
  for (int i=1;i<n;i++) {
    if (a[i] == 0) {
      for (int j=1;j<=m;j++) {
          dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1] + dp[i - 1][j]) % MOD;
      }
    } else {
      dp[i][a[i]] = (dp[i - 1][a[i] - 1] + dp[i - 1][a[i] + 1] + dp[i - 1][a[i]]) % MOD;
      for (int j=1;j<=m;j++) {
        if (j == a[i]) continue;
        dp[i][j] = 0;
      }
    }
  }
  ll res = 0;
  if (a[n-1] != 0) return dp[n-1][a[n-1]];
  for (int i=1;i<=m;i++) {
    res = (res + dp[n-1][i]) % MOD;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n >> m;
  for (int i=0;i<n;i++) {
    cin >> a[i];
  }
  cout << solve() << "\n";
  return 0;
}
