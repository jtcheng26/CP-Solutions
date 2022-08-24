#include <iostream>
#include <vector>
#include <cmath>

#define INF 100000000

using namespace std;

class Solution
{
public:
  int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
  {
    int ans = 0;
    int n = nums1.size();
    int m = nums2.size();

    int dp[n][m];
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        dp[i][j] = 0;
      }
    }

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        dp[i][j] = nums1[i] == nums2[j];
        if (dp[i][j] == 1)
        {
          if (i >= 1 && j >= 1)
          {
            dp[i][j] += dp[i - 1][j - 1];
          }
        }
        else
        {
          if (i >= 1)
          {
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
          }
          if (j >= 1)
          {
            dp[i][j] = max(dp[i][j], dp[i][j - 1]);
          }
        }
      }
    }

    ans = dp[n - 1][m - 1];

    return ans;
  }
};

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> a;
  vector<int> b;
  for (int i = 0; i < n; i++)
  {
    int j;
    cin >> j;
    a.push_back(j);
  }
  for (int i = 0; i < m; i++)
  {
    int j;
    cin >> j;
    b.push_back(j);
  }
  Solution sol;
  cout << sol.maxUncrossedLines(a, b) << "\n";
  return 0;
}
