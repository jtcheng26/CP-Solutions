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
int a[5001];

ll solve() {
  ll dp[2][n][n];
  for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
      dp[0][i][j] = dp[1][i][j] = 0;
    }
    dp[0][i][i] = a[i];
  }
  for (int k=1;k<n;k++) {
    for (int i=0;i<n - k;i++) {
      if (dp[1][i+1][i+k] + a[i] > dp[1][i][i+k-1] + a[i+k]) {
        dp[0][i][i+k] = dp[1][i+1][i+k] + a[i];
        dp[1][i][i+k] = dp[0][i+1][i+k];
      } else {
        dp[0][i][i+k] = dp[1][i][i+k-1] + a[i+k];
        dp[1][i][i+k] = dp[0][i][i+k-1];
      }
    }
  }
  return dp[0][0][n-1];
}

int main() {
  cin >> n;
  for (int i=0;i<n;i++) cin >> a[i];
  cout << solve() << endl;
  return 0;
}
