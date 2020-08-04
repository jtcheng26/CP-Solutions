#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

typedef long long ll;

using namespace std;

ll t, n, a, b;
string bin;

ll solve(ll* dp) {
  ll res = 0;
  res += n * a + (n+1) * b;
  // dp[i] = min cost for first
  // each 1
  string prev = "0";
  for (ll i=1;i<n;i++) {
    if (bin.substr(i, 1) != prev) {
      if (prev == "0") {
        res += a + b; prev = "1";
      }
      else {
        ll count = 1; ll j;
        //count 0 streak
        for (j=i+1;bin.substr(j, 1) == "0"&&j<n;j++)
          count++;
        // at end
        if (j==n) {
          res += a + b; break;
        }
        // better to go down
        else if (count > 1 && (count - 1) * b > 2 * a) {
          res += a + b; i = j-1; prev = "0";
        } else
          res += b;
      }
    } else if (prev == "1") {
      res += b;
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> t;
  for (int i=0;i<t;i++) {
    cin >> n >> a >> b;
    cin >> bin;
    ll dp[n];
    cout << solve(dp) << endl;
  }
  return 0;
}
