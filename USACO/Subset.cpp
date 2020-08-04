/*
   LANG: C++14
   PROG: subset
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

ll n, sum;
ll dp[391] = {0};

ll solve() {
  if ((n * (n+1)) % 4 != 0)
    return 0;
  sum = (n * (n + 1)) / 4;
  dp[0] = dp[1] = 1;
  for (int i=2;i<=n;i++) {
    for (int j=sum;j>=i;j--) {
      //cout << dp[j] << " ";
      dp[j] += dp[j - i];
    }
    //cout << endl;
  }
  return dp[sum]/2;
}

int main() {
  ofstream fout ("subset.out");
  ifstream fin ("subset.in");
  fin >> n;//
  fout << solve() << endl;//
  return 0;
}
