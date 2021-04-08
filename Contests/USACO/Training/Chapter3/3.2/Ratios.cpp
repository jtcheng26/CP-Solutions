/*
   LANG: C++11
   PROG: ratios
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

typedef long long ll;

using namespace std;

ll n;
int goal[3];
int r[3][3];
int ans[3];
int cnt = 0;

bool isZeroOk(int i, int a) {
  return goal[i] == 0 && a == 0;
}

int solve() {
  bool poss = false;
  int dp[3][3][101];
  int dp2[3][101];
  for (int j=0;j<3;j++) {
    for (int k=0;k<3;k++) {
      for (int i=0;i<100;i++) {
        dp[j][k][i] = r[j][k] * i;
        //cout << r[j][k] << " " << i << " " << dp[j][k][i] << endl;
      }
    }
  }
  for (int i=1;i<100;i++) {
    for (int j=0;j<3;j++) {
      dp2[j][i] = goal[j] * i;
    }
  }
  int best = 1000000;
  for (int i=1;i<100;i++) {
    for (int j=0;j<100;j++) {
      for (int k=0;k<100;k++) {
        for (int m=0;m<100;m++) {
          if (j + k + m > best) break;
          int a = dp[0][0][j] + dp[1][0][k] + dp[2][0][m];
          int b = dp[0][1][j] + dp[1][1][k] + dp[2][1][m];
          int c = dp[0][2][j] + dp[1][2][k] + dp[2][2][m];
          //cout << a << " " << b << " " << c << endl;
          if (dp2[0][i] == a && dp2[1][i] == b && dp2[2][i] == c) {
            ans[0] = j;
            ans[1] = k;
            ans[2] = m;
            best = j + k + m;
            cnt = i;
            poss = true;
          }
        }
      }
    }
  }
  return poss;
}

int main() {
  ofstream cout ("ratios.out");
  ifstream cin ("ratios.in");
  for (int i=0;i<3;i++) {
    cin >> goal[i];
  }
  for (int i=0;i<3;i++) {
    for (int j=0;j<3;j++) {
      cin >> r[i][j];
    }
  }
  if (!solve()) {
    cout << "NONE" << endl;
    return 0;
  }
  cout << ans[0] << " " << ans[1] << " " << ans[2] << " " << cnt << endl;
  return 0;
}
