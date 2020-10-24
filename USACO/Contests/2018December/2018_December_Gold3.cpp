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

typedef long long ll;

using namespace std;

int n, k;
int cows[10001];

int solve() {
  int dp[n+1];
  int mx[n+1][k+1];
  for (int i=1;i<=n;i++) {
    mx[i][0] = 0;
    for (int j=i;j>i-k;j--) {
      if (j <= 0) break;
      mx[i][i - j + 1] = max(mx[i][i - j], cows[j-1]);
      //cout << i << " " << i - j + 1 << " " << mx[i][i-j+1] << endl;
    }
  }
  dp[0] = 0;
  for (int i=1;i<=n;i++) {
    dp[i] = 0;
    for (int j=1;j<=k;j++) {
      if (i - j < 0) break;
      dp[i] = max(dp[i], dp[i-j] + mx[i][j] * j);
      //cout << i << " " << j << " " << dp[i] << endl;
    }
  }
  return dp[n];
}

int main() {
  ofstream cout ("teamwork.out");
  ifstream cin ("teamwork.in");
  cin >> n >> k;
  for (int i=0;i<n;i++) cin >> cows[i];
  cout << solve() << endl;
  return 0;
}
