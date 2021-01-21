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
ll a[201];

int getFactorCount(ll m, int f) {
  int cnt = 0;
  while (m % f == 0) {
    m /= f;
    cnt++;
  }
  return cnt;
}

ll solve() {
  ll dp[k+1][5001];
  for (int j=0;j<=k;j++) {
    for (int l=0;l<=5000;l++) {
      dp[j][l] = -1;
    }
    dp[j][0] = 0;
  }
    //dp[i][0][0] = 0;
    //if (i > 0)
    //  dp[i][1][getFactorCount(a[i], 5)] = getFactorCount(a[i], 2);
  for (int i=1;i<=n;i++) {
    int twos = getFactorCount(a[i], 2);
    int fives = getFactorCount(a[i], 5);
    for (int j=k;j>=1;j--) {
      for (int l=5000;l>=0;l--) {
        if (fives <= l) {
          if (dp[j-1][l-fives] >= 0)
            dp[j][l] = max(dp[j][l], dp[j-1][l-fives] + twos);
          //cout << i << " " << j << " " << l << " " << dp[i][j][l] << "\n";
        }
      }
    }
  }
  ll res = 0;
  for (ll i=0;i<=5000;i++) {
    //cout << i << " " << dp[k][i] << "\n";
    res = max(res, min(dp[k][i], i));
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n >> k;
  for (int i=1;i<=n;i++) cin >> a[i];
  cout << solve() << "\n";
  return 0;
}
