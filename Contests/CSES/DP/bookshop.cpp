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
int cost[100001];
int pages[100001];

int solve() {
  int res = 0;
  int dp[k + 1];
  for (int i=0;i<=k;i++) dp[i] = 0;
  for (int i=0;i<n;i++) {
    for (int j=k;j>=cost[i];j--) {
      dp[j] = max(dp[j], (dp[j-cost[i]] + pages[i]) % MOD);
      res = max(res, dp[j]);
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n >> k;
  for (int i=0;i<n;i++) {
    cin >> cost[i];
  }
  for (int i=0;i<n;i++) {
    cin >> pages[i];
  }
  cout << solve() << "\n";
}
