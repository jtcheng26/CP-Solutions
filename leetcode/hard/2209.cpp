#include <iostream>
#include <vector>
#include <cmath>

#define INF 100000000

using namespace std;

class Solution
{
public:
  int minimumWhiteTiles(string floor, int numCarpets, int carpetLen)
  {
    int n = floor.length();

    int dp[n][numCarpets + 1];

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j <= numCarpets; j++)
      {
        dp[i][j] = n;
        if (i == 0)
          dp[i][j] = j > 0 ? 0 : (floor[i] == '1');
        else if (j == 0)
          dp[i][j] = dp[i - 1][j] + (floor[i] == '1');
      }
    }

    int ans = dp[n - 1][numCarpets];

    for (int i = 1; i < n; i++)
    {
      for (int j = 1; j <= numCarpets; j++)
      {
        int use = i - carpetLen < 0 ? 0 : dp[i - carpetLen][j - 1];
        dp[i][j] = min(dp[i - 1][j] + (floor[i] == '1'), use);
        if (i == n - 1)
          ans = min(ans, dp[i][j]);
        // cout << i << " " << j << " " << dp[i][j] << "\n";
      }
    }

    return ans;
  }
};

int main()
{
  int m, k;
  cin >> m >> k;
  string a;
  cin >> a;
  Solution sol;
  cout << sol.minimumWhiteTiles(a, m, k) << "\n";
  return 0;
}
