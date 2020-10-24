#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INFI 1e18+7
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long ll;

using namespace std;

int k;
int n, m;
int arr[501][501];
/*
int bob() {
  int dp[n+1][m+1];
  for (int i=0;i<=n;i++)
  for (int j=0;j<=m;j++)
    dp[i][j] = 0;
  dp[0][1] = arr[1][1];
  for (int i=1;i<=n;i++) {
    for (int j=1;j<=m;j++) {
      dp[i][j] = max(dp[i-1][j]&arr[i][j], dp[i][j-1]&arr[i][j]);
    }
  }
  for (int i=0;i<=n;i++)
  for (int j=0;j<=m;j++)
    cout << dp[i][j] << (j == m ? "\n" : " ");
  return dp[n][m];
}
*/
int solve() {
  n = 2; m = 3;
  arr[1][1] = 131072 + k;
  arr[1][2] = k;
  arr[1][3] = 0;
  arr[2][1] = 131072;
  arr[2][2] = 131072 + k;
  arr[2][3] = k;
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> k;
  solve();
  cout << n << " " << m << "\n";
  for (int i=1;i<=n;i++) {
    for (int j=1;j<=m;j++) {
      cout << arr[i][j] << (j == m ? "\n" : " ");
    }
  }
  return 0;
}
