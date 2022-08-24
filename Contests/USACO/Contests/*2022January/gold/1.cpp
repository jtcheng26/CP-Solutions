#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>

#define INF 1000000001
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

int n, h;
int a[106];

ll solve()
{
  h = 0;
  int hm = 1000;
  for (int i=0;i<n;i++) {
    h = max(h, a[i]);
    hm = min(hm, a[i]);
  }
  ll dp[2][h+1];
  ll res = 0;

  for (int j=0;j<=hm;j++) {
    for (int i=0;i<=a[0]-j;i++) {
      dp[0][i] = i + 1;
      dp[1][i] = 0;
    }
    for (int i=a[0]+1-j;i<=h;i++) {
      dp[0][i] = a[0] - j + 1;
      dp[1][i] = 0;
    }
    for (int i=1;i<n;i++) {
      for (int k=0;k<=a[i]-j;k++) {
        dp[1][k] = dp[0][a[i] - k - j];
        if (dp[1][k] >= MOD) dp[1][k] -= MOD;
      }
      for (int k=0;k<=h;k++) {
        dp[0][k] = dp[1][k] + (k > 0 ? dp[0][k-1] : 0);
        if (dp[0][k] >= MOD) dp[0][k] -= MOD;
        dp[1][k] = 0;
      }
    }
    res += dp[0][0];
    if (res >= MOD) res -= MOD;
    if (n % 2 == 0) break;
  }
  return res;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i=0;i<n;i++) {
    cin >> a[i];
  }
  cout << solve() << "\n";
  return 0;
}
