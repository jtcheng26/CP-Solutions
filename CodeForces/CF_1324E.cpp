#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INFI 1e18+7
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long ll;

using namespace std;

int n, h, l, r;
int dp[2001][2001];
int sleep[2001];

int recurse(int i, int u) {
  if (i >= n) return 0;
  if (dp[i][u] != -1) return dp[i][u];
  int t = ((sleep[i] - u) % h + h) % h;
  int stay = l <= t && t <= r;
  stay += recurse(i+1, u);
  int t2 = ((t - 1) % h + h) % h;
  int go = l <= t2 && t2 <= r;
  go += recurse(i+1, u+1);
  dp[i][u] = max(stay, go);
  //cout << i << " " << u << " " << dp[i][u] << "\n";
  return dp[i][u];
}

int solve() {
  for (int i=1;i<n;i++) {
    sleep[i] = (sleep[i-1] + sleep[i]) % h;
  }
  for (int i=0;i<n;i++) {
    for (int j=0;j<=n;j++) {
      dp[i][j] = -1;
    }
  }
  return recurse(0, 0);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n >> h >> l >> r;
  for (int i=0;i<n;i++) cin >> sleep[i];
  cout << solve() << "\n";
  return 0;
}
