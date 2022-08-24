#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
  vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int> &colsum)
  {
    int n = colsum.size();
    vector<vector<int>> a(2, vector<int>(n, 0));
    int u = upper;
    int l = lower;
    for (int i = 0; i < n; i++)
    {
      if (colsum[i] == 2)
      {
        u -= 1;
        l -= 1;
        a[0][i] = a[1][i] = 1;
      }
    }
    for (int i = 0; i < n; i++)
    {
      if (colsum[i] == 1)
      {
        if (u > 0)
        {
          u -= 1;
          a[0][i] = 1;
        }
        else if (l > 0)
        {
          l -= 1;
          a[1][i] = 1;
        }
        else
        {
          u = l = -1;
        }
      }
    }
    if (u != 0 || l != 0)
    {
      a.clear();
    }
    return a;
  }
};

int main()
{
  int n;
  cin >> n;
  int upper, lower;
  cin >> upper >> lower;
  vector<int> colsum(n, 0);
  for (int i = 0; i < n; i++)
  {
    cin >> colsum[i];
  }
  Solution sol;
  vector<vector<int>> ans = sol.reconstructMatrix(upper, lower, colsum);
  for (int i = 0; i < ans[0].size(); i++)
  {
    cout << ans[0][i] << " ";
  }
  cout << "\n";
  for (int i = 0; i < ans[1].size(); i++)
  {
    cout << ans[1][i] << " ";
  }
}