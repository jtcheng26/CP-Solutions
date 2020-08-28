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

typedef long long ll;

using namespace std;

int n;
int a[200001];

int solve() {
  ll res = 0;
  ll dp[n+1];
  dp[0] = 1;
  for (int i=1;i<n;i++) {
    if (a[i] <= a[i-1] * 2)
      dp[i] = dp[i-1] + 1;
    else dp[i] = 1;
  }
  for (int i=0;i<n;i++) res = max(res, dp[i]);
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  for (int i=0;i<n;i++) cin >> a[i];
  cout << solve() << endl;
  return 0;
}
