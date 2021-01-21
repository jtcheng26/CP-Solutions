#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <iomanip>

#define INFI 1e18+7
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define MOD 1e9+7

typedef long long ll;

using namespace std;

int n;
int a[101];
int b[101];
double ans[101];

void solve() {
  int totA = 0;
  double totB = 0;
  for (int i=0;i<n;i++) {
    totA += a[i];
    totB += b[i];
  }
  double dp[n+1][totA + 1];
  for (int i=0;i<=n;i++) {
    for (int j=0;j<=totA;j++) {
      dp[i][j] = -1;
    }
    dp[i][0] = 0;
  }
  for (int i=0;i<n;i++) {
    for (int j=n;j>=1;j--) {
      for (int k=totA;k>=a[i];k--) {
        if (dp[j-1][k-a[i]] >= 0)
          dp[j][k] = max(dp[j][k], dp[j-1][k-a[i]] + b[i]);
      }
    }
  }
  totB /= 2;
  for (int i=1;i<=n;i++) {
    ans[i] = 0;
    for (int j=0;j<=totA;j++) {
      if (dp[i][j] >= 0)
        ans[i] = max(ans[i], min((double)j, dp[i][j] / 2 + totB));
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  for (int i=0;i<n;i++) {
    cin >> a[i]; cin >> b[i];
  }
  solve();
  cout << fixed << showpoint;
  cout << setprecision(9);
  for (int i=1;i<=n;i++) {
    cout << ans[i] << (i == n ? "\n" : " ");
  }
  return 0;
}
