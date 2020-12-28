#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define INF 1000000007

typedef long long ll;

using namespace std;

int n, k;
int a[401];

int solve() {
  int dp[n][k+1];
  int high = 0;
  int total = 0;
  for (int i=0;i<n;i++) {
    total += a[i];
    high = max(high, a[i]);
    dp[i][0] = high * (i + 1);
    for (int j=1;j<=k;j++) {
      dp[i][j] = INF;
      int mx = a[i];
      for (int l=i-1;l>=0;l--) {
        dp[i][j] = min(dp[i][j], dp[l][j-1] + mx * (i - l));
        mx = max(mx, a[l]);
      }
    }
  }
  int res = INF;
  for (int i=0;i<=k;i++) res = min(res, dp[n-1][i]);
  return res - total;
}

int main() {
  ofstream cout ("snakes.out");
  ifstream cin ("snakes.in");
  cin >> n >> k;
  for (int i=0;i<n;i++) cin >> a[i];
  cout << solve() << endl;
  return 0;
}
