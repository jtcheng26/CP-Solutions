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
char CONV[4] = { 'A', 'C', 'G', 'T' };
string s;

ll solve() {
  ll dp[n+1][4][4][4];
  for (int i=0;i<=n;i++) {
    for (int j=0;j<4;j++) {
      for (int k=0;k<4;k++) {
        for (int l=0;l<4;l++) {
          dp[i][j][k][l] = 0;
          if (i > 0)
            dp[1][j][k][k] = (s[0] == CONV[k] || s[0] == '?');
        }
      }
    }
  }
  for (int i=1;i<=n;i++) {
    for (int j=0;j<4;j++) {
      for (int k=0;k<4;k++) {
        for (int l=0;l<4;l++) {
          if (s[i-1] == '?' || s[i-1] == CONV[l]) {
            for (int l2=0;l2<4;l2++) {
              if (l2 != l) {
                dp[i][j][k][l] = (dp[i][j][k][l] + dp[i-1][j][k][l2]) % MOD;
              }
            }
          }
        }
        if (s[i-1] == '?' || s[i-1] == CONV[k]) {
          for (int l=0;l<4;l++) {
            dp[i][j][k][k] = (dp[i][j][k][k] + dp[i-1][l][j][l]) % MOD;
          }
        }
      }
    }
  }
  ll res = 0;
  for (int i=0;i<4;i++) {
    for (int j=0;j<4;j++) {
      res = (res + dp[n][i][j][i]) % MOD;
    }
  }
  return res;
}

int main() {
  cin >> s;
  n = s.length();
  cout << solve() << endl;
  return 0;
}
