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

ll solve() {
  ll dp[n+1];
  for (int i=1;i<=n;i++) {
    dp[i] = 0;
  }
  dp[0] = 1;
    for (int i=1;i<=n;i++) {
      for (int j=1;j<=6;j++) {
        if (i < j) continue;
        dp[i] = (dp[i] + dp[i-j]) % MOD;
      }
    }
  return dp[n];
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  cout << solve() << "\n";
  return 0;
}
