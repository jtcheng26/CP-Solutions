#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INF 10000000001
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

int n, k;
int a[101];
int b[101][101];

ll solve() {
  ll res = INF;
  for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
      b[i][j] = a[(j+i) % n];
      //cout << b[i][j] << " ";
    }
    //cout << "\n";
  }
  ll dp[n][n][k+1][n];
  ll dp2[n][n][k+1];
  for (int s=0;s<n;s++) {
    for (int i=0;i<n;i++) {
      for (int j=0;j<=k;j++) {
        dp2[s][i][j] = INF;
        for (int l=0;l<n;l++) {
          dp[s][i][j][l] = INF;
        }
      }
    }
    dp[s][0][1][0] = 0;
    dp2[s][0][1] = 0;
  }
  for (int s=0;s<n;s++) {
    for (int i=1;i<n;i++) {
      for (int j=1;j<=k;j++) {
        for (int l=1;l<n;l++) {
          dp[s][i][j][l] = dp[s][i-1][j][l-1] + l * b[s][i];
          dp2[s][i][j] = min(dp2[s][i][j], dp[s][i][j][l]);
        }
        dp[s][i][j][0] = dp2[s][i-1][j-1];
        dp2[s][i][j] = min(dp2[s][i][j], dp[s][i][j][0]);
      }
    }
    res = min(res, dp2[s][n-1][k]);
  }
  return res;
}

int main() {
  ofstream cout ("cbarn2.out");
  ifstream cin ("cbarn2.in");
  cin >> n >> k;
  for (int i=0;i<n;i++) cin >> a[i];
  cout << solve() << endl;
  return 0;
}
