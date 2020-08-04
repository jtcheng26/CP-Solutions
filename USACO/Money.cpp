/*
   LANG: C++14
   PROG: money
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

int v, n; int c[25];
ll dp[10001];

ll solve() {
  ll res = 0;
  dp[0] = 1;
  for (int i=0;i<v;i++) {
    for (int j=c[i];j<=n;j++) {
      dp[j] = dp[j] + dp[j - c[i]];
    }
  }
  return dp[n];
}

int main() {
  ofstream fout ("money.out");
  ifstream fin ("money.in");
  fin >> v >> n;
  for (int i=0;i<v;i++) {
    fin >> c[i];
  }
  fout << solve() << endl;
  return 0;
}
