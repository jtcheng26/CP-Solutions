#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INF 1000000001
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

int n;
int ans[1000001];

void solve() {
  ll dp[1000001][2];
  for (int i=1;i<=100000;i++) {
    dp[i][0] = dp[i][1] = 0;
  }
  dp[0][0] = dp[0][1] = 1;
  ans[0] = 2;
  for (int i=1;i<=1000000;i++) {
    dp[i][0] = ((dp[i-1][0] * 4) % MOD + dp[i-1][1]) % MOD;
    dp[i][1] = ((dp[i-1][1] * 2) % MOD + dp[i-1][0]) % MOD;
    ans[i] = (dp[i][0] + dp[i][1]) % MOD;
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  solve();
  while (t--) {
    cin >> n;
    cout << ans[n - 1] << "\n";
  }
  return 0;
}
