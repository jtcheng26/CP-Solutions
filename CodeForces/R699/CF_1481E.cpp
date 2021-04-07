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
int a[500001];

int solve() {
  int dp[n+1];
  int l[n+1];
  int r[n+1];
  int occ[n+1];
  for (int i=0;i<=n;i++) {
    dp[i] = 0;
    l[i+1] = -1;
    r[i+1] = -1;
    occ[i] = 0;
  }
  for (int i=0;i<n;i++) {
    r[a[i]] = i;
    if (l[a[i]] == -1) {
      l[a[i]] = i;
    }
  }
  for (int i=n-1;i>=0;i--) {
    occ[a[i]]++;
    if (i == l[a[i]]) {
      dp[i] = max(dp[i], occ[a[i]] + (r[a[i]] + 1 < n ? dp[r[a[i]] + 1] : 0));
    } else {
      dp[i] = max(dp[i], occ[a[i]]);
    }
    dp[i] = max(dp[i], i + 1 < n ? dp[i+1] : dp[i]);
  }
  return n - dp[0];
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  for (int i=0;i<n;i++) cin >> a[i];
  cout << solve() << "\n";
  return 0;
}
