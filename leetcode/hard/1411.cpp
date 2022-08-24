#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <array>

#define MOD 1000000007

typedef long long ll;

using namespace std;

class Solution
{
public:
  int numOfWays(int n)
  {
    int good[12][3] = {
        {0, 1, 0},
        {0, 1, 2},
        {0, 2, 0},
        {0, 2, 1},
        {1, 0, 1},
        {1, 0, 2},
        {1, 2, 0},
        {1, 2, 1},
        {2, 0, 1},
        {2, 0, 2},
        {2, 1, 0},
        {2, 1, 2}};

    vector<vector<ll>> dp(n, vector<ll>(12, 0));
    dp[0] = vector<ll>(12, 1);
    for (int i = 1; i < n; i++)
    {
      for (int j = 0; j < 12; j++)
      {
        for (int k = 0; k < 12; k++)
        {
          bool ok = true;
          for (int l = 0; l < 3; l++)
          {
            if (good[j][l] == good[k][l])
              ok = false;
          }
          if (ok)
          {
            dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
          }
        }
      }
    }

    ll ans = 0;

    for (int i = 0; i < 12; i++)
    {
      ans = (ans + dp[n - 1][i]) % MOD;
    }

    return ans;
  }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  Solution sol;
  cout << sol.numOfWays(n) << "\n";
  return 0;
}