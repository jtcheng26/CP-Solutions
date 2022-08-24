// Misread the problem at first, thought it just asked the best sum of all elements.
// A lot simpler just wanting the binary sum. Observation + greedy.
// Good medium level problem.
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
  int col[21] = {0};
  int n, m;
  int matrixScore(vector<vector<int>> &grid)
  {
    n = grid.size();
    m = grid[0].size();

    int ans = n * (1 << (m - 1));

    for (int i = 0; i < n; i++)
    {
      for (int j = 1; j < m; j++)
      {
        if (grid[i][0] == 0)
        {
          grid[i][j] = !grid[i][j];
        }
        col[j] += grid[i][j];
      }
    }

    for (int j = 1; j < m; j++)
    {
      ans += (1 << (m - j - 1)) * max(col[j], n - col[j]);
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
  vector<vector<int>> grid(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> grid[i][j];
    }
  }
  cout << sol.matrixScore(grid) << "\n";
  return 0;
}
