#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

typedef long long ll;

using namespace std;

ll n, m;

bool cmp(int a, int b) {
  return a > b;
}

ll solve(ll* s, ll* dp) {
  ll sum[n+1]; sum[0] = 0;
  for (int i=0;i<n;i++) {
    dp[i+1] = sum[i] + s[i];
    sum[i+1] = dp[i+1];
    if (i > m-1) dp[i+1] += dp[i+1-m];
    //cout << dp[i+1] << endl;
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n >> m;
  ll s[n]; ll dp[n+1];
  for (int i=0;i<n;i++) {
    cin >> s[i];
  }
  sort(s, s+n);
  dp[0] = 0;
  solve(s, dp);
  for (int i=1;i<=n;i++) {
    cout << dp[i] << endl;
  }
  return 0;
}
