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
  int sum[101][101];
  int maxSumSubmatrix(vector<vector<int>> &matrix, int k)
  {
    int n = matrix.size();
    int m = matrix[0].size();

    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= m; j++)
      {
        sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + matrix[i - 1][j - 1];
      }
    }

    int ans = -100000000;
    int s;

    for (int u = 0; u <= n; u++)
    {
      for (int d = u + 1; d <= n; d++)
      {
        for (int l = 0; l <= m; l++)
        {
          for (int r = l + 1; r <= m; r++)
          {
            s = sum[d][r] - sum[u][r] - sum[d][l] + sum[u][l];
            if (s <= k)
              ans = max(ans, s);
          }
        }
      }
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
  cin >> m >> n;
  vector<vector<int>> matrix(m, vector<int>(n, 0));
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> matrix[i][j];
    }
  }
  int k;
  cin >> k;
  Solution sol;
  cout << sol.maxSumSubmatrix(matrix, k);
  return 0;
}