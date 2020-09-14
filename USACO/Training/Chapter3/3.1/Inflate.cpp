/*
   LANG: C++11
   PROG: inflate
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

typedef long long ll;

using namespace std;

int m, n;
int pts[10001];
int times[10001];

int solve() {
  int dp[m+1];
  for (int i=0;i<=m;i++) dp[i] = 0;
  for (int i=0;i<n;i++) {
    for (int j=times[i];j<=m;j++) {
      dp[j] = max(dp[j], dp[j-times[i]] + pts[i]);
    }
  }
  return dp[m];
}

int main() {
  ofstream cout ("inflate.out");
  ifstream cin ("inflate.in");
  cin >> m >> n;
  for (int i=0;i<n;i++) {
    cin >> pts[i] >> times[i];
  }
  cout << solve() << endl;
  return 0;
}
