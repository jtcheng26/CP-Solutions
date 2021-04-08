#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

#define INF 1000000001;
#define mp make_pair
#define pb push_back
#define F first
#define S second

typedef long long ll;

using namespace std;

int n[2];
pair<int, int> a[2005];

int dist(int u, int v) {
  return abs(a[u].F - a[v].F) * abs(a[u].F - a[v].F) + abs(a[u].S - a[v].S) * abs(a[u].S - a[v].S);
}

int solve() {
  int dp[2002][1001];
  for (int i=0;i<=n[0];i++) {
    for (int j=0;j<=n[1];j++) {
      dp[i][j] = INF;
    }
  }
  dp[1][0] = 0;
  dp[1][1] = 2 * dist(1, n[0] + 1);
  dp[n[0]+1][1] = dist(1, n[0] + 1);
  dp[n[0] + 1][0] = INF;
  for (int j=2;j<=n[1];j++) {
    dp[1][j] = dp[1][j-1] + dist(n[0] + j - 1, n[0] + j);
    dp[n[0] + j][1] = dp[n[0] + j - 1][1] + dist(n[0] + j - 1, n[0] + j);
  }
  for (int i=2;i<=n[0];i++) {
    dp[i][0] = dp[i-1][0] + dist(i - 1, i);
    for (int j=1;j<=n[1];j++) {
        dp[i][j] = min(dp[i-1][j] + dist(i - 1, i), dp[n[0] + j][i-1] + dist(i, n[0] + j));
        if (j > 1)
          dp[n[0] + j][i] = min(dp[n[0] + j - 1][i] + dist(n[0] + j - 1, n[0] + j), dp[i][j-1] + dist(i, n[0] + j));
        else
          dp[n[0] + j][i] = dp[i][j-1] + dist(i, n[0] + j);
    }
  }
  return dp[n[0]][n[1]];
}

int main() {
  ofstream cout ("checklist.out");
  ifstream cin ("checklist.in");
  cin >> n[0] >> n[1];
  for (int i=1;i<=n[0];i++) {
    cin >> a[i].F >> a[i].S;
  }
  for (int i=1;i<=n[1];i++) {
    cin >> a[i+n[0]].F >> a[i+n[0]].S;
  }
  cout << solve() << endl;
  return 0;
}
