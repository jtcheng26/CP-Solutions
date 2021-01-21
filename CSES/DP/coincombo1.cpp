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

int n, k;
int a[101];

ll solve() {
  ll dp[k+1];
  for (int i=1;i<=k;i++) dp[i] = 0;
  dp[0] = 1;
    for (int i=1;i<=k;i++) {
      for (int j=0;j<n;j++) {
        if (i < a[j]) continue;
        dp[i] = (dp[i] + dp[i-a[j]]) % MOD;
      }
    }
  return dp[k];
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n >> k;
  for (int i=0;i<n;i++) cin >> a[i];
  cout << solve() << "\n";
  return 0;
}
