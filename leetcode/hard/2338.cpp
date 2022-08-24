// Tough problem but I liked it. Managed to do it without combinatorics.
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

class Solution
{
public:
  ll dp[16][10001];
  int idealArrays(int n, int maxValue)
  {
    int m = maxValue;
    int l = min(n, 14);
    for (int j = 1; j <= m; j++)
    {
      dp[1][j] = 1;
    }

    vector<ll> cnt(l + 1, 0);
    cnt[1] = m;
    for (int i = 2; i <= l; i++)
    {
      for (int j = 2; j <= m; j++)
      {
        int lim = sqrt(j);
        for (int k = 1; k <= lim; k++)
        {
          if (j % k == 0)
          {
            dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
            if (j / k != j && j / k != k)
            {
              dp[i][j] = (dp[i][j] + dp[i - 1][j / k]) % MOD;
            }
          }
        }
        cnt[i] = (cnt[i] + dp[i][j]) % MOD;
      }
    }

    vector<ll> part(l + 1, 0);
    part[1] = 1;
    for (int i = 0; i < n - 1; i++)
    {
      for (int j = l; j >= 1; j--)
      {
        part[j] = (part[j] + part[j - 1]) % MOD;
      }
    }

    ll ans = 0;
    for (int i = 1; i <= l; i++)
    {
      ans = (ans + (part[i] * cnt[i]) % MOD) % MOD;
    }

    return ans;
  }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  Solution sol;
  cout << sol.idealArrays(n, m) << "\n";
  return 0;
}
