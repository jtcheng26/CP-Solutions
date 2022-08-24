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
  int maxDotProduct(vector<int> &nums1, vector<int> &nums2)
  {
    int n = nums1.size();
    int m = nums2.size();

    int ans = nums1[0] * nums2[0];

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= m; j++)
      {
        dp[i][j] = nums1[i - 1] * nums2[j - 1];
        dp[i][j] = max(dp[i][j], dp[i][j] + dp[i - 1][j - 1]);
        if (i > 1)
          dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        if (j > 1)
          dp[i][j] = max(dp[i][j], dp[i][j - 1]);
        // ans = max(ans, dp[i][j]);
        // cout << i << " " << j << " " << dp[i][j] << "\n";
      }
    }

    return dp[n][m];
  }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n, 0);
  vector<int> b(m, 0);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  for (int i = 0; i < m; i++)
  {
    cin >> b[i];
  }
  Solution sol;
  cout << sol.maxDotProduct(a, b) << "\n";
  return 0;
}
