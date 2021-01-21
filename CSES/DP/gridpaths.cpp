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

int n;
char a[1001][1001];

ll solve() {
  ll dp[n][n];
  for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
      dp[i][j] = 0;
    }
  }
  dp[0][0] = a[0][0] == '.';
  for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
      if (a[i][j] == '*') continue;
      if (i > 0) {
        dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
      }
      if (j > 0) {
        dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
      }
    }
  }
  return dp[n-1][n-1];
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
      cin >> a[i][j];
    }
  }
  cout << solve() << "\n";
  return 0;
}
