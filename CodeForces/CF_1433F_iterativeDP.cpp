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

int n, m, k;
int a[71][71];

int solve() {
  int res = 0;
  int dp1[n][m][m/2+1][k];
  int dp2[n][k];
  int dp3[n][k];
  for (int i=0;i<n;i++) {
    for (int j=0;j<m;j++) {
      for (int b=0;b<=m/2;b++) {
        for (int r=0;r<k;r++) {
          dp1[i][j][b][r] = 0;
          dp2[i][r] = 0;
          dp3[i][r] = 0;
        }
      }
    }
  }
  for (int i=0;i<n;i++) {
    for (int j=0;j<m;j++) {
      int num = a[i][j];
      for (int b=1;b<=m/2;b++) {
        if (j == 0) {
          dp1[i][j][b][num % k] = max(dp1[i][j][b][num % k], num);
          break;
        }
        for (int r=0;r<k;r++) {
          dp1[i][j][b][(dp1[i][j-1][b-1][r] + num) % k] = max(dp1[i][j][b][(dp1[i][j-1][b-1][r] + num) % k], dp1[i][j-1][b-1][r] + num);
          dp1[i][j][b][r] = max(dp1[i][j][b][r], dp1[i][j-1][b][r]);
        }
      }
    }
  }
  for (int i=0;i<n;i++) {
    for (int b=1;b<=m/2;b++) {
      for (int r=0;r<k;r++) {
        dp2[i][r] = max(dp2[i][r], dp1[i][m-1][b][r]);
      }
    }
  }
  for (int i=0;i<n;i++) {
    for (int r=0;r<k;r++) {
      if (i == 0) dp3[i][r] = dp2[i][r];
      for (int r2=0;r2<k;r2++) {
        if (i == 0) break;
        if (dp2[i][r2] % k == r2 && dp3[i-1][r] % k == r)
          dp3[i][(r + r2) % k] = max(dp3[i][(r + r2) % k], dp3[i-1][r] + dp2[i][r2]);
        if (i > 0)
          dp3[i][(r + r2) % k] = max(dp3[i][(r + r2) % k], dp3[i-1][(r + r2) % k]);
      }
    }
  }
  return dp3[n-1][0];
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n >> m >> k;
  for (int i=0;i<n;i++) {
    for (int j=0;j<m;j++) {
      cin >> a[i][j];
    }
  }
  cout << solve() << "\n";
  return 0;
}
