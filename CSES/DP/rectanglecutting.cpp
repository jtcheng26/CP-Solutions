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

int a, b;

int solve() {
  int dp[a+1][b+1];
  for (int i=0;i<=a;i++) {
    for (int j=0;j<=b;j++) {
      dp[i][j] = INF;
      if (i == 0) dp[i][j] = 0;
      else if (j == 0) dp[i][j] = 0;
    }
  }
  for (int i=1;i<=a;i++) {
    for (int j=1;j<=b;j++) {
      if (i == j) {
        dp[i][j] = 0;
        continue;
      }
      for (int k=1;k<i;k++) {
        dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
      }
      for (int k=1;k<j;k++) {
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
      }
      //cout << i << " " << j << " " << dp[i][j] << "\n";
    }
  }
  return dp[a][b];
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> a >> b;
  cout << solve() << "\n";
  return 0;
}
