#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INF 1000000001
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD 1000000009

typedef long long ll;

using namespace std;

int n, m, k;
int a[1001];
int b[1001];

ll solve() {
  ll dp[n+1][m+1][k+1];
  for (int i=0;i<=n;i++) {
    for (int l=0;l<=m;l++) {
      dp[i][l][0] = 1;
      for (int j=1;j<=k;j++) {
        dp[i][l][j] = 0;
      }
    }
  }
  sort(a, a+n);
  sort(b, b+m);
  for (int i=1;i<=n;i++) {
    for (int j=1;j<=m;j++) {
      for (int l=1;l<=k;l++) {
        dp[i][j][l] = (((dp[i-1][j][l] + dp[i][j-1][l]) % MOD - dp[i-1][j-1][l]) + MOD) % MOD;
        if (a[i-1] > b[j-1]) {
          dp[i][j][l] = (dp[i][j][l] + dp[i-1][j-1][l-1]) % MOD;
          //cout << i << " " << j << " " << l << " " << dp[i][j][l] << "\n";
        }
      }
    }
  }
  return dp[n][m][k];
}

int main() {
  ofstream cout ("team.out");
  ifstream cin ("team.in");
  cin >> n >> m >> k;
  for (int i=0;i<n;i++) cin >> a[i];
  for (int i=0;i<m;i++) cin >> b[i];
  cout << solve() << endl;
  return 0;
}
