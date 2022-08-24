#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>

#define INF 100000000000000001LL
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

int n, m;
ll p[1006][3];

ll solve()
{
  ll dp[m + 1];
  for (int i = 0; i <= m; i++)
  {
    dp[i] = 0;
  }
  for (int i = m; i > 0; i--)
  {
    ll mn = INF;
    for (int j = 0; j < n; j++)
    {
      // first idx after
      if (i <= p[j][1])
      {
        int idx = min(i + p[j][0], p[j][1] + 1);
        mn = min(mn, p[j][2] + ((idx > m) ? 0 : dp[idx]));
      }
    }
    dp[i] = mn;
  }
  return dp[1] >= INF ? -1 : dp[1];
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    cin >> p[i][0] >> p[i][1] >> p[i][2];
  }
  cout << solve() << "\n";
  return 0;
}