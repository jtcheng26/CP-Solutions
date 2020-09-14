/*
   LANG: C++14
   PROG: nocows
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

typedef long long ll;

using namespace std;

int N, K;
ll dp[101][202];
ll sdp[101][202];

ll solve() {
  if (N % 2 == 0 || K == 1)
    return 0;
  else if (K == 2)
    return 1;
  dp[1][1] = 1;
  for (int i=2;i<=K;i++) {
    for (int j=1;j<=N;j+=2) {
      for (int k=1;k<=j-1-k;k+=2) {
        ll r = sdp[i-2][k] * dp[i-1][j-1-k] + dp[i-1][k] * sdp[i-2][j-1-k] + dp[i-1][k] * dp[i-1][j-1-k];
        if (k != j-1-k)
          r *= 2;
        dp[i][j] += r;
        dp[i][j] %= 9901;
      }
    }
    for (int k=0;k<=N;k++) {
      sdp[i-1][k] += dp[i-1][k] + sdp[i-2][k];
      sdp[i-1][k] %= 9901;
    }
  }
  /*
  for (int i=1;i<=K;i++) {
    for (int j=1;j<=N;j++)
      cout << dp[i][j] << endl;
  }
  */
  return dp[K][N];
}

int main() {
  ofstream fout ("nocows.out");
  ifstream fin ("nocows.in");
  fin >> N >> K;
  fout << solve() << endl;
  return 0;
}
