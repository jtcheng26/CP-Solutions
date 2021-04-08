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
int a[249];

int solve() {
  int res = a[0];
  int limit = 10000;
  int poss[n][limit+1];
  for (int i=0;i<n;i++) {
    for (int j=0;j<=limit;j++) {
      poss[i][j] = -1;
    }
  }
  poss[0][a[0]] = 0;
  for (int i=1;i<n;i++) {
    poss[i][a[i]] = 0;
    int curr = a[i];
    int prev = i-1;
    while (prev >= 0 && poss[prev][curr] != -1) {
      poss[i][curr + 1] = poss[prev][curr] + i - prev;
      prev = i - poss[i][curr + 1] - 1;
      curr++;
    }
  }
  for (int i=0;i<n;i++) {
    for (int j=0;j<=limit;j++) {
      if (poss[i][j] != -1) res = max(res, j);
    }
  }
  return res;
}

int solve2() {
  int dp[n][n];
  int res = 0;
  for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
      dp[i][j] = -1;
    }
  }
  for (int len=1;len<=n;len++) {
    for (int i=0;i+len<=n;i++) {
      int j = i + len - 1;
      if (len == 1)
        dp[i][j] = a[i];
      else {
        for (int k=i;k<j;k++) {
          if (dp[i][k] != -1 && dp[i][k] == dp[k+1][j]) {
            dp[i][j] = max(dp[i][j], dp[i][k] + 1);
            res = max(res, dp[i][j]);
          }
        }
      }
    }
  }
  return res;
}

// 2 1 1 3 2 2 3

int main() {
  ofstream cout ("248.out");
  ifstream cin ("248.in");
  cin >> n;
  for (int i=0;i<n;i++) cin >> a[i];
  cout << solve2() << endl;
  return 0;
}
