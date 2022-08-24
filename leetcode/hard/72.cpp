#include <iostream>
#include <vector>
#include <cmath>

#define INF 100000000

using namespace std;

class Solution
{
public:
  int minDistance(string word1, string word2)
  {
    int n = word1.length();
    int m = word2.length();

    if (n == 0)
      return m;
    if (m == 0)
      return n;

    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
    {
      for (int j = 0; j <= m; j++)
      {
        dp[i][j] = max(n, m);
        if (i == 0)
          dp[i][j] = j;
        if (j == 0)
          dp[i][j] = i;
      }
    }

    int ans = INF;

    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= m; j++)
      {
        if (word1[i - 1] != word2[j - 1])
        {
          dp[i][j] = 1 + dp[i - 1][j - 1];
          dp[i][j] = min(dp[i][j], 1 + dp[i][j - 1]);
          dp[i][j] = min(dp[i][j], 1 + dp[i - 1][j]);
        }
        else
        {
          dp[i][j] = dp[i - 1][j - 1];
          dp[i][j] = min(dp[i][j], 1 + dp[i][j - 1]);
          dp[i][j] = min(dp[i][j], 1 + dp[i - 1][j]);
        }
      }
    }

    return dp[n][m];
  }
};

int main()
{
  string a;
  string b;
  cin >> a;
  cin >> b;
  Solution sol;
  cout << sol.minDistance(a, b) << "\n";
  return 0;
}
