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

int n, k;
int a[100001];

int solve() {
  int res = 0;
  int dp[n][k+1][3];
  for (int i=0;i<n;i++) {
    for (int j=0;j<=k;j++) {
      for (int l=0;l<3;l++) {
        dp[i][j][l] = 0;
        dp[0][0][l] = (a[0] == l);
      }
    }
  }
  for (int i=1;i<n;i++) {
    for (int j=0;j<=min(i, k);j++) {
      for (int l=0;l<3;l++) {
        if (j == 0)
          dp[i][j][l] = dp[i-1][j][l] + (a[i] == l);
        else if (a[i] == l) {
          dp[i][j][l] = max(dp[i-1][j][l], max(max(dp[i-1][j-1][0], dp[i-1][j-1][1]), dp[i-1][j-1][2])) + 1;
        } else {
          dp[i][j][l] = dp[i-1][j][l];
        }
        res = max(res, dp[i][j][l]);
      }
    }
  }
  return res;
}

int main() {
  ofstream cout ("hps.out");
  ifstream cin ("hps.in");
  cin >> n >> k;
  for (int i=0;i<n;i++) {
    char c;
    cin >> c;
    if (c == 'P') a[i] = 0;
    else if (c == 'H') a[i] = 1;
    else a[i] = 2;
  }
  cout << solve() << endl;
  return 0;
}
