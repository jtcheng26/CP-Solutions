#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

typedef long long ll;

using namespace std;

ll n;

ll solve() {
  ll res = 0;
  ll dp[n+1];
  dp[0] = 0; dp[1] = 1;
  for (ll i=2;i<=n;i++) {
    dp[i] = max(i, dp[i / 2] + dp[i / 3] + dp[i / 4]);
  }
  return dp[n];
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  string l;
  while(getline(cin, l)) {
    n = stoi(l);
    cout << solve() << endl;
  }
  return 0;
}
