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
ll rows[2][100001];

ll solve() {
  ll dp[n][3];
  dp[0][0] = rows[0][0]; dp[0][1] = rows[1][0]; dp[0][2] = 0;
  for (int i=1;i<n;i++) {
    dp[i][0] = max(dp[i-1][1] + rows[0][i], dp[i-1][2] + rows[0][i]);
    dp[i][1] = max(dp[i-1][0] + rows[1][i], dp[i-1][2] + rows[1][i]);
    dp[i][2] = max(dp[i-1][0], dp[i-1][1]);
  }
  return max(dp[n-1][0], dp[n-1][1]);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  for (int i=0;i<2;i++) {
    for (int j=0;j<n;j++) {
      cin >> rows[i][j];
    }
  }
  cout << solve() << endl;
  return 0;
}
