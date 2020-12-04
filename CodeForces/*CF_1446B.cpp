#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INFI 10000
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long ll;

using namespace std;

int n, m;
string a, b;

int solve() {
  int dp[n+1][m+1];
  for (int i=0;i<=n;i++) {
    for (int j=0;j<=m;j++) {
      dp[i][j] = 0;
    }
  }
  int res = 0;
  for (int i=1;i<=n;i++) {
    for (int j=1;j<=m;j++) {
      if (a[i-1] == b[j-1])
        dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 2);
      else {
        dp[i][j] = max(dp[i][j], dp[i-1][j] - 1);
        dp[i][j] = max(dp[i][j], dp[i][j-1] - 1);
      }
      res = max(res, dp[i][j]);
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n >> m;
  cin >> a >> b;
  cout << solve() << "\n";
  return 0;
}
