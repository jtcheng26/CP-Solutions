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

ll solve(ll* a) {
  ll cnt[100001]; ll dp[100001];
  for (ll i=0;i<100001;i++) {
    cnt[i] = 0; dp[i] = 0;
  }
  for (ll i=0;i<n;i++) {
    cnt[a[i]]++;
  }
  dp[0] = 0; dp[1] = cnt[1];
  for (ll i=2;i<=100001;i++) {
    dp[i] = max(dp[i-1], dp[i-2] + cnt[i]*i);
  }
  return dp[100000];
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n; ll a[n];
  for (ll i=0;i<n;i++) {
    cin >> a[i];
  }
  cout << solve(a) << endl;
  return 0;
}
