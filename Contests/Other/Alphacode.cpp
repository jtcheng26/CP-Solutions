#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

typedef long long ll;

using namespace std;

string n = "";

ll solve() {
  ll dp[n.length()+1];
  dp[0] = 1; dp[1] = 1;
  for (ll i=2;i<=n.length();i++) {
    dp[i] = 1;
    ll num = stoi(n.substr(i-2, 2));
    if (num <= 26) {
      if (num != 10 && num != 20 && num / 10 != 0) {
        dp[i] = dp[i-1] + dp[i-2];
        if (n.substr(i, 1) == "0")
          dp[i] = dp[i-1];
      }
      else {
        dp[i] = dp[i-1];
      }
    } else {
      dp[i] = dp[i-1];
    }
  }
  return dp[n.length()];
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  while (n != "0") {
    cout << solve() << endl;
    cin >> n;
  }
  return 0;
}
