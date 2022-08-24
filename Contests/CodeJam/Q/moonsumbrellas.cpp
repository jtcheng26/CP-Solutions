#include <iostream>

#define INF 1000000001

using namespace std;

int n;
int x, y;
int a[1001];

int solve() {
  int dp[n][2];
  for (int i=0;i<n;i++) {
    dp[i][0] = dp[i][1] = INF;
  }
  if (a[0] == 2)
    dp[0][0] = dp[0][1] = 0;
  else {
    dp[0][a[0]] = 0;
    dp[0][!a[0]] = INF;
  }
  for (int i=1;i<n;i++) {
    if (a[i] == 2) {
      dp[i][0] = min(dp[i-1][0], y + dp[i-1][1]);
      dp[i][1] = min(dp[i-1][1], x + dp[i-1][0]);
    } else {
      if (a[i] == 0) {
        dp[i][0] = min(dp[i-1][0], y + dp[i-1][1]);
        dp[i][1] = INF;
      } else {
        dp[i][1] = min(dp[i-1][1], x + dp[i-1][0]);
        dp[i][0] = INF;
      }
    }
  }
  return min(dp[n-1][0], dp[n-1][1]);
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    for (int c=1;c<=t;c++) {
        cin >> x >> y;
        string s;
        cin >> s;
        n = s.length();
        for (int i=0;i<n;i++) {
          if (s[i] == '?') a[i] = 2;
          else if (s[i] == 'C') a[i] = 0;
          else a[i] = 1;
        }
        cout << "Case #" << c << ": " << solve() << "\n";
    }
}
