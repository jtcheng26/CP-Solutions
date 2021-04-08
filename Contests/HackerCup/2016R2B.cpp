#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INFI 1000000007
#define pb push_back
#define F first
#define S second

typedef long long ll;

using namespace std;

int n, k;
double p;

double solve() {

  double dp[n+1][n+1];

  dp[0][0] = 1;
  for (int i=1;i<=n;i++) dp[0][i] = 0;
  for (int i=1;i<=n;i++) {
    dp[i][0] = pow((1-p), i);
    for (int j=1;j<=n;j++) {
      dp[i][j] = dp[i-1][j-1] * p + dp[i-1][j] * (1 - p);
    }
  }
  double dp1[n+1];
  for (int i=1;i<=n;i++) {
    dp1[i] = 0;
    for (int j=k;j<=n;j++) {
      dp1[i] += dp[i][j];
    }
  }
  double dp2[n+1];
  dp2[0] = 0;
  for (int i=1;i<=n;i++) {
    dp2[i] = 0;
    for (int j=0;j<i;j++) {
      dp2[i] = max(dp2[i], dp2[j] + dp1[i - j]);
    }
  }
  /*
  dp[2][0] = 0.25 dp[1][0] = 0.5
  dp[2][1] = 0.5 dp[1][1] = 0.5
  dp[2][2] = 0.25
  */
  return dp2[n];
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  ifstream cin ("carnival_coins_input.txt");
  ofstream cout ("2016R2B.txt");
  int t;
  cin >> t;//
  cout << fixed;
  cout << setprecision(9);
  for (int i=1;i<=t;i++) {
    cin >> n >> k >> p;
    cout << "Case #" << i << ": " << solve() << endl;//
  }
  return 0;
}
