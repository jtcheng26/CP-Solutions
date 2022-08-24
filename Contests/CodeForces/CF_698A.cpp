#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>

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

int solve() {
  int res = 0;
  int dp[n][3];
  for (int i=0;i<n;i++) {
    for (int j=0;j<3;j++) {
      dp[i][j] = INF;
    }
  }
  dp[0][0] = 1;
  if (a[0] == 1 || a[0] == 3)
    dp[0][1] = 0;
  if (a[0] == 2 || a[0] == 3)
    dp[0][2] = 0;
  for (int i=1;i<n;i++) {
    dp[i][0] = min(dp[i-1][0], min(dp[i-1][1], dp[i-1][2])) + 1;
    if (a[i] == 1) {
      dp[i][1] = min(dp[i-1][0], dp[i-1][2]);
    } else if (a[i] == 2) {
      dp[i][2] = min(dp[i-1][0], dp[i-1][1]);
    } else if (a[i] == 3) {
      dp[i][1] = min(dp[i-1][0], dp[i-1][2]);
      dp[i][2] = min(dp[i-1][0], dp[i-1][1]);
    }
  }
  return min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2]));
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  for (int i=0;i<n;i++) {
    cin >> a[i];
  }
  cout << solve() << "\n";
  return 0;
}