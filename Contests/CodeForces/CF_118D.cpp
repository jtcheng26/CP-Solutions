#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

#define MOD 100000000;

typedef long long ll;

using namespace std;

ll n[2];
ll k[2];
ll dp[2][101][101];

ll sch(int c, int f, int h) {
  ll res = 0;
  if (f < 0 || h < 0) return 0;
  if (dp[c][f][h] >= 0) return dp[c][f][h];
  //cout << f << h << endl;
  for (int j=1;j<=k[c];j++) {
    if (c == 0)
      res += sch(1, f - j, h);
    else
      res += sch(0, f, h - j);
    res %= MOD;
  }
  dp[c][f][h] = res % MOD;
  return res;
}

ll solve() {
  for (int i=0;i<2;i++) {
    for (int j=0;j<=n[0];j++) {
      for (int m=0;m<=n[1];m++) dp[i][j][m] = -1;
    }
  }
  dp[0][0][0] = dp[1][0][0] = 1;
  return (sch(0, n[0], n[1]) + sch(1, n[0], n[1])) % MOD;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n[0] >> n[1] >> k[0] >> k[1];
  cout << solve() << endl;
  return 0;
}
