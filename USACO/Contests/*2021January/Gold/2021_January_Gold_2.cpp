#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INF 10e17
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

int n, k;
int a[500001];
vector<int> in[51];
vector<int> out[51];

ll solve() {
  ll dp[n][k+1];
  int idx[n][k+1];
  for (int i=0;i<n;i++) {
    for (int j=0;j<=k;j++) {
      dp[i][j] = INF;
      idx[i][j] = -1;
    }
  }
  /*
  for (int i=1;i<=k;i++) {
    cout << i << ": ";
    for (int j : in[i]) {
      cout << j << " ";
    }
    cout << "\n";
  }
  */
  dp[0][a[0]] = 0;
  idx[0][a[0]] = 0;
  for (int i=1;i<n;i++) {
    for (int j=1;j<=k;j++) {
      dp[i][j] = dp[i-1][j];
      idx[i][j] = idx[i-1][j];
    }
    idx[i][a[i]] = i;
    int j = a[i];
    dp[i][j] = INF;
    for (int neighbor : in[j]) {
      if (idx[i-1][neighbor] != -1)
        dp[i][j] = min(dp[i][j], dp[i-1][neighbor] + i - idx[i-1][neighbor]);
    }
    if (dp[i][j] != INF) {
      for (int neighbor : out[j]) {
        if (idx[i-1][neighbor] != -1) {
          dp[i][neighbor] = min(dp[i][neighbor], dp[i][j] + i - idx[i-1][neighbor]);
        }
        //cout << i << " " << j << " " << dp[i][j] << "\n";
      }
    }
  }
  return dp[n-1][a[n-1]] == INF ? -1 : dp[n-1][a[n-1]];
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n >> k;
  for (int i=0;i<n;i++) cin >> a[i];
  for (int i=1;i<=k;i++) {
    for (int j=1;j<=k;j++) {
      char c;
      cin >> c;
      if (c == '1') {
        out[i].pb(j);
        in[j].pb(i);
      }
    }
  }
  cout << solve() << endl;
  return 0;
}
