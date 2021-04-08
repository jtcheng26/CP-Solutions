#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INFI 100000007

typedef long long ll;

using namespace std;

int n[3];
int c[3][201];
int dp[3][201];

bool cmp(int a, int b) {
  return a > b;
}

ll solve() {
  for (int i=0;i<3;i++) {
    sort(c[i] + 1, c[i]+n[i] + 1, cmp);
  }
  int dp[n[0]+1][n[1]+1][n[2]+1];
  for (int i=0;i<=n[0];i++) {
    for (int j=0;j<=n[1];j++) {
      for (int k=0;k<=n[2];k++) {
        dp[i][j][k] = 0;
      }
    }
  }
  for (int i=0;i<=n[0];i++) {
    for (int j=0;j<=n[1];j++) {
      for (int k=0;k<=n[2];k++) {
        if (i > 0 && j > 0)
          dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-1][k] + c[0][i] * c[1][j]);
        if (j > 0 && k > 0)
          dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k-1] + c[1][j] * c[2][k]);
        if (i > 0 && k > 0)
          dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k-1] + c[0][i] * c[2][k]);
        //cout << "i " << i << " J " << j << " K " << k << " res " << dp[i][j][k] << endl;
      }
    }
  }
  int res = 0;
  for (int i=1;i<=n[0];i++) {
    for (int j=1;j<=n[1];j++) {
      for (int k=1;k<=n[2];k++) {
        res = max(res, dp[i][j][k]);
      }
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n[0] >> n[1] >> n[2];
  for (int i=1;i<=n[0];i++) cin >> c[0][i];
  for (int i=1;i<=n[1];i++) cin >> c[1][i];
  for (int i=1;i<=n[2];i++) cin >> c[2][i];
  cout << solve() << endl;
  return 0;
}
