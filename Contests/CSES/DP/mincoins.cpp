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

int solve() {
  int dp[k+1];
  for (int i=1;i<=k;i++) dp[i] = INF;
  dp[0] = 0;
  for (int i=0;i<n;i++) {
    for (int j=a[i];j<=k;j++) {
      dp[j] = min(dp[j], dp[j-a[i]] + 1);
    }
  }
  return dp[k] == INF ? -1 : dp[k];
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n >> k;
  for (int i=0;i<n;i++) {
    cin >> a[i];
  }
  cout << solve() << "\n";
  return 0;
}
