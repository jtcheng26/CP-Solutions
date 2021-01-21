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

string a, b;

int solve() {
  int n = a.length();
  int m = b.length();
  int dp[n + 1][m + 1];
  for (int i=1;i<=n;i++) {
    for (int j=1;j<=m;j++) {
      dp[i][j] = INF;
    }
  }
  for (int j=1;j<=m;j++) {
    dp[0][j] = j;
  }
  for (int j=1;j<=n;j++) {
    dp[j][0] = j;
  }
  dp[0][0] = 0;
  for (int i=1;i<=n;i++) {
    for (int j=1;j<=m;j++) {
      if (a[i-1] != b[j-1]) {
        dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
      } else {
        dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]) + 1);
      }
    }
  }
  return dp[n][m];
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> a;
  cin >> b;
  cout << solve() << "\n";
  return 0;
}
