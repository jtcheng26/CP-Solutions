#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INF 1000000001
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

int n;
ll c[100001];
ll a[100001];
ll b[100001];

ll solve() {
  ll res = 0;
  ll dp[n];
  for (int i=0;i<n;i++) {
    dp[i] = 0;
  }
  dp[1] = 2 + abs(a[1] - b[1]);
  res = max(res, dp[1] + c[1] - 1);
  for (int i=2;i<n;i++) {
    if (a[i] != b[i]) {
      dp[i] = max(dp[i-1] + (min(a[i], b[i]) - 1) + (c[i-1] - max(a[i], b[i])), abs(a[i] - b[i])) + 2;
    } else {
      dp[i] = 2;
    }
    res = max(res, dp[i] + c[i] - 1);
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i=0;i<n;i++) {
      cin >> c[i];
    }
    for (int i=0;i<n;i++) {
      cin >> a[i];
    }
    for (int i=0;i<n;i++) {
      cin >> b[i];
    }
    cout << solve() << "\n";
  }
  return 0;
}
