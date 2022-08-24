#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>

#define INF 1000000001
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

int n;
int a[301];
int dp[301][301];

int go(int l, int r) { // inclusive
  if (l >= r)
    return 0;
  if (dp[l][r] != -1) return dp[l][r];
  dp[l][r] = 0;
  if (a[l] == a[r])
    dp[l][r] = max(dp[l][r], 1 + go(l + 1, r - 1));
  for (int i = l + 1; i < r; i++)
  {
    dp[l][r] = max(dp[l][r], go(l, i) + go(i, r));
  }
  // cout << l << " " << r << " " << dp[l][r] << "\n";
  return dp[l][r];
}

int solve() {
  for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
      dp[i][j] = -1;
    }
  }
  return n - go(0, n - 1);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  for (int i=0;i<n;i++) cin >> a[i];
  cout << solve() << endl;
  return 0;
}
