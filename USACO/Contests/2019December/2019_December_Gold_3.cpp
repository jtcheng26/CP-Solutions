#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define INF 1000000007

typedef long long ll;

using namespace std;

int n, m, k;
int cost[27][27];
char s[100001];
int dp[100001][26];
int pfx[100001][26];

void fw() {
  for (int k=0;k<m;k++)
  for (int i=0;i<m;i++)
  for (int j=0;j<m;j++)
    cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
}

int rngSum(int l, int r, int p) {
  return pfx[r][p] - pfx[l][p];
}

int go(int prev, int idx) {
  if (idx >= n) return 0;
  if (dp[idx][prev] != -1) return dp[idx][prev];
  if (n - idx < k) {
    dp[idx][prev] = cost[s[idx] - 'a'][prev] + go(prev, idx+1);
  }
  else if (idx == 0) {
    dp[idx][prev] = 1000000007;
    for (int i=0;i<m;i++) {
      int sum = rngSum(0, k, i);
      dp[idx][prev] = min(dp[idx][prev], sum + go(i, k));
    }
  }
  else if (n - idx < 2 * k) {
    int mn = rngSum(idx, n, 0);
    for (int i=1;i<m;i++) {
      mn = min(mn, rngSum(idx, n, i));
    }
    dp[idx][prev] = min(mn, cost[s[idx] - 'a'][prev] + go(prev, idx+1));
  } else {
    int copyPrev = cost[s[idx] - 'a'][prev] + go(prev, idx+1);
    int startNew = 1000000007;
    for (int i=0;i<m;i++) {
      startNew = min(startNew, rngSum(idx, idx+k, i) + go(i, idx+k));
    }
    dp[idx][prev] = min(copyPrev, startNew);
  }
  //cout << (char)(prev + 'a') << " " << idx << " " << dp[idx][prev] << endl;;
  return dp[idx][prev];
}

int solve() {
  fw();
  for (int i=0;i<n;i++) {
    for (int j=0;j<m;j++) {
      dp[i][j] = -1;
    }
  }
  for (int i=0;i<m;i++) {
    pfx[0][i] = 0;
    for (int j=0;j<n;j++) {
      pfx[j+1][i] = pfx[j][i] + cost[s[j] - 'a'][i];
    }
  }
  return go(0, 0);
}

int main() {
  ofstream cout ("cowmbat.out");
  ifstream cin ("cowmbat.in");
  cin >> n >> m >> k;
  for (int i=0;i<n;i++) cin >> s[i];
  for (int i=0;i<m;i++)
  for (int j=0;j<m;j++) {
    cin >> cost[i][j];
  }
  cout << solve() << endl;
  return 0;
}
