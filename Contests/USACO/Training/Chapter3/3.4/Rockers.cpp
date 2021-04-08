/*
   LANG: C++11
   PROG: rockers
*/

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

int n, t, m;
int songs[21];

int solve() {
  // max songs for ith disk where previous last song was j and through t minutes
  int dp[21][21][21];
  for (int i=0;i<=m;i++)
  for (int j=0;j<=n;j++)
  for (int k=0;k<=t;k++)
    dp[i][j][k] = 0;
  int best = 0;
  for (int j=0;j<m;j++) { // disk
    for (int i=0;i<=n;i++) { // start bound
      for (int i2=i+1;i2<=n;i2++) { // new song
        for (int k=0;k<=t;k++) { // time
          if (k + songs[i2] <= t) {
            if (dp[j][i][k] + 1 > dp[j][i2][k+songs[i2]]) // put song in this disk
              dp[j][i2][k+songs[i2]] = dp[j][i][k] + 1;
          } else if (dp[j][i][k] + 1 > dp[j+1][i2][songs[i2]]) // put song in next disk
            dp[j+1][i2][songs[i2]] = dp[j][i][k] + 1;
        }
      }
    }
  }
  for (int i=0;i<m;i++) {
    for (int j=0;j<=n;j++) {
      for (int k=0;k<=t;k++) {
        best = max(best, dp[i][j][k]);
      }
    }
  }
  //cout << dp[0][0][t] << endl;
  //cout << dp[1][1][t] << endl;
  return best;
}

int main() {
  ofstream cout ("rockers.out");
  ifstream cin ("rockers.in");
  cin >> n >> t >> m;
  for (int i=1;i<=n;i++) cin >> songs[i];
  cout << solve() << endl;
  return 0;
}
