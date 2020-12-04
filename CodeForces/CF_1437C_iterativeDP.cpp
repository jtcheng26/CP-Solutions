#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INFI 1000000007
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long ll;

using namespace std;

int n;
int a[201];

int solve() {
  int dp[n][2*n];
  sort(a, a+n);
  dp[0][0] = INFI;
  for (int i=1;i<2*n;i++) {
    dp[0][i] = min(dp[0][i-1], abs(a[0] - i));
  }
  for (int i=1;i<n;i++) {
    for (int j=0;j<=i;j++) {
      dp[i][j] = INFI;
    }
    for (int j=i+1;j<2*n;j++) {
      dp[i][j] = min(dp[i][j-1], dp[i-1][j-1] + abs(a[i] - j));
    }
  }
  int res = INFI;
  for (int i=0;i<2*n;i++) {
    res = min(res, dp[n-1][i]);
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    cout << solve() << "\n";
  }
  return 0;
}
