#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

typedef long long ll;

using namespace std;

ll k, a, b, max_b;
ll arr[100001];
ll brr[100001];
ll dp[100001];

ll solve(ll b) {
  ll res = 0;
  for (int i=0;i<=b;i++) dp[i] = 0;
  dp[0] = 1;
  for (int j=1;j<=b;j++) {
    if (j >= k) {
      dp[j] = (dp[j-k] % 1000000007);
    }
    dp[j] = (dp[j] + (dp[j - 1] % 1000000007)) % 1000000007;
    //cout << dp[j] << " " << j << endl;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t; max_b = 0;
  cin >> t >> k;
  for (int i=0;i<t;i++) {
    cin >> arr[i] >> brr[i];
    max_b = max(max_b, brr[i]);
  }
  solve(max_b);
  for (int i=1;i<=max_b;i++) {
    dp[i] = dp[i] + dp[i-1];
  }
  for (int i=0;i<t;i++) {
    //cout << brr[i] << " " << arr[i] << endl;
    //cout << dp[brr[i]] << " " << dp[arr[i] - 1];
    cout << (dp[brr[i]] - dp[arr[i] - 1]) % 1000000007 << endl;
  }
  return 0;
}
