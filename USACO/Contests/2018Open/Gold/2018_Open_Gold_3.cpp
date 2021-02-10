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

struct cow {
  int w, t;
};

int n, w;
cow a[251];

int solve() {
  int res = 0;
  int k = 1001 * n;
  int dp[k];
  for (int i=1;i<=k;i++) dp[i] = INF;
  dp[0] = 0;
  for (int i=0;i<n;i++) {
    for (int j=k;j>=a[i].t;j--) {
      dp[j] = min(dp[j], dp[j-a[i].t] + a[i].w);
      if (dp[j] >= w && dp[j] != INF) res = max(res, j * 1000 / dp[j]);
    }
  }
  return res;
}

int main() {
  ofstream cout ("talent.out");
  ifstream cin ("talent.in");
  cin >> n >> w;
  for (int i=0;i<n;i++) {
    cin >> a[i].w >> a[i].t;
  }
  cout << solve() << endl;
  return 0;
}
