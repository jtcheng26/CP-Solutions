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

int solve() {
  int dp[n+1];
  for (int i=0;i<=n;i++) {
    dp[i] = INF;
  }
  dp[n] = 0;
  for (int i=n;i>=0;i--) {
    int k = i;
    while (k > 0) {
      dp[i - (k % 10)] = min(dp[i - (k % 10)], dp[i] + 1);
      k /= 10;
    }
  }
  return dp[0];
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  cout << solve() << "\n";
  return 0;
}
