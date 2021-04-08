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

int n, m;
char arr[501][501];

int solve() {
  int res = 0;
  int dp[501][501][2];
  for (int i=0;i<n;i++) {
    for (int j=0;j<m;j++) {
      if (arr[i][j] == '.') {
        dp[i][j][0] = 0;
        continue;
      }
      if (j == 0) dp[i][j][0] = 1;
      else dp[i][j][0] = dp[i][j-1][0] + 1;
    }
  }
  for (int i=n-1;i>=0;i--) {
    for (int j=m-1;j>=0;j--) {
      if (arr[i][j] == '.') {
        dp[i][j][1] = 0;
        continue;
      }
      if (j == m-1) dp[i][j][1] = 1;
      else dp[i][j][1] = dp[i][j+1][1] + 1;
    }
  }
  for (int i=0;i<n;i++) {
    for (int j=0;j<m;j++) {
      if (arr[i][j] == '.') continue;
      res++;
      for (int k=1;k<n - i;k++) {
        int r = i + k;
        if (r >= n) break;
        int c;
        if (j-k < 0 || j+k >= m) break;
        if (min(dp[r][j][0], dp[r][j][1]) - 1 >= k) {
          res++;
        } else break;
      }
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i=0;i<n;i++) {
      for (int j=0;j<m;j++) {
        cin >> arr[i][j];
      }
    }
    cout << solve() << "\n";
  }
  return 0;
}
