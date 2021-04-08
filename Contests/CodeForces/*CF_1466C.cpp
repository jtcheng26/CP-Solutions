#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INFI 1e18+7
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define MOD 1e9+7

typedef long long ll;

using namespace std;

int n;
string s;

int solve() {
  n = s.length();
  int dp[n + 1];
  bool change[n + 1];
  for (int i=0;i<n;i++) {
    dp[i] = 0;
    change[i] = 0;
  }
  for (int i=1;i<n;i++) {
    //cout << change[i-1] << "\n";
    if (s[i] == s[i-1]) {
      dp[i] += !change[i-1];
      if (!change[i-1])
        change[i] = true;
    }
    if (i >= 2 && s[i] == s[i-2]) {
      dp[i] += !change[i-2];
      if (!change[i-2])
        change[i] = true;
    }
    dp[i] += dp[i-1];
    //cout << dp[i] << "\n";
  }
  return dp[n-1];
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> s;
    cout << solve() << "\n";
  }
  return 0;
}
