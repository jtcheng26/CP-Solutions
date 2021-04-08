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
#define MOD 1000000007

typedef long long ll;

using namespace std;

int n;
int l[2];

int solve() {
  bool dp[n+1][2];
  for (int i=0;i<=n;i++) {
    for (int j=0;j<2;j++)
      dp[i][j] = false;
  }
  dp[0][0] = true;
  for (int k=0;k<2;k++) {
    for (int i=0;i<=n;i++) {
      if (i >= l[k]) {
        dp[i][0] = dp[i][0] || dp[i-l[k]][0];
        dp[i][1] = dp[i][1] || dp[i-l[k]][1];
      }
      if (dp[i][0])
        dp[i / 2][1] = true;
    }
  }
  for (int k=0;k<2;k++) {
    for (int i=0;i<=n;i++) {
      if (i >= l[k]) {
        dp[i][0] = dp[i][0] || dp[i-l[k]][0];
        dp[i][1] = dp[i][1] || dp[i-l[k]][1];
      }
      if (dp[i][0])
        dp[i / 2][1] = true;
    }
  }
  int res = 0;
  for (int i=0;i<=n;i++) {
    if (dp[i][0] || dp[i][1]) res = i;
  }
  return res;
}

int main() {
  ofstream cout ("feast.out");
  ifstream cin ("feast.in");
  cin >> n >> l[0] >> l[1];
  cout << solve() << endl;
  return 0;
}
