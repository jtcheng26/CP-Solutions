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

int n;
int a[101];
int ans[101];

void solve() {
  int dp[n][n+1][n];
  int dp2[n][n+1];
  for (int i=0;i<n;i++) {
    for (int j=0;j<=n;j++) {
      dp2[i][j] = INF;
      for (int k=0;k<n;k++) {
        dp[i][j][k] = INF;
      }
    }
  }
  dp[0][1][0] = (a[0] != 0);
  dp2[0][1] = dp[0][1][0];
  for (int i=1;i<n;i++) {
    for (int j=1;j<=i+1;j++) {
      for (int k=1;k<=i;k++) {
        dp[i][j][k] = (a[i] != k) + dp[i-1][j][k-1];
        dp2[i][j] = min(dp2[i][j], dp[i][j][k]);
      }
      if (j > 1)
        dp[i][j][0] = (a[i] != 0) + dp2[i-1][j-1];
      dp2[i][j] = min(dp2[i][j], dp[i][j][0]);
    }
  }
  for (int i=1;i<=n;i++) {
    ans[i] = dp2[n-1][i];
  }
}

int main() {
  ofstream cout ("taming.out");
  ifstream cin ("taming.in");
  cin >> n;
  for (int i=0;i<n;i++) cin >> a[i];
  solve();
  for (int i=1;i<=n;i++) {
    cout << ans[i] << "\n";
  }
  return 0;
}
