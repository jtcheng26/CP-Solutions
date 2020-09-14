/*
   LANG: C++11
   PROG: stamps
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

#define INFI 100000007

typedef long long ll;

using namespace std;

int k, n;
int cents[51];

int solve() {
  sort(cents, cents+n);
  if (cents[0] != 1) return 0;
  int sz = k * cents[n-1];
  int dp[sz + 1]; // min cents req for each value
  for (int i=0;i<sz;i++) {
    dp[i] = INFI;
  }
  dp[0] = 0;
  for (int i=0;i<n;i++) {
    for (int j=1;j<=sz;j++) {
      if (j - cents[i] < 0) continue;
      dp[j] = min(dp[j], 1 + dp[j-cents[i]]);
    }
  }
  //cout << sz << endl;
  for (int i=1;i<=sz;i++) {
    //cout << i << " " << dp[i] << endl;
    if (dp[i] > k) return i-1;
  }
  return sz;
}

int main() {
  ofstream cout ("stamps.out");
  ifstream cin ("stamps.in");
  cin >> k >> n;
  for (int i=0;i<n;i++) cin >> cents[i];
  cout << solve() << endl;
  return 0;
}
