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
  if (l == r) return 1;
  if (l > r) return 0;
  if (dp[l][r] != -1) return dp[l][r];
  dp[l][r] = INF;
  int nl = l;
  int nr = r;
  while (nl < r && a[nl] == a[l]) nl++;
  while (nr > l && a[nr] == a[r]) nr--;

  if (nl > nr && a[l] == a[r]) {
    dp[l][r] = 1;
    return 1;
  } else if (nl > nr) {
    dp[l][r] = 2;
    return 2;
  }
  for (int i=nl+1;nl<=nr;i++) {
    if (a[nl] == a[i]) {
      dp[l][r] = min(dp[l][r], a[nl] + a[i])
    }
  }
  if (a[l] == a[r]) {
    dp[l][r] = 1 + go(nl, nr);
  } else {
    dp[l][r] = min(dp[l][r], 1 + go(nl, r));
    dp[l][r] = min(dp[l][r], 1 + go(l, nr));
  }
  //cout << l << " " << r << " " << dp[l][r] << "\n";
  return dp[l][r];
}

int solve() {
  for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
      dp[i][j] = -1;
    }
  }
  return go(0, n-1);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  for (int i=0;i<n;i++) cin >> a[i];
  cout << solve() << endl;
  return 0;
}
