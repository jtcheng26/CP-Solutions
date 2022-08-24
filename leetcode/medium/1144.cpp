#include <iostream>
#include <vector>
#include <cmath>

#define INF 100000000

using namespace std;

class Solution
{
public:
  int movesToMakeZigzag(vector<int> &nums)
  {
    int n = nums.size();
    int ans = INF;
    for (int k = 0; k < 2; k++)
    {
      int res = 0;
      for (int i = k; i < n; i += 2)
      {
        int moves = 0;
        if (i < n - 1)
        {
          moves = max(moves, max(0, 1 + nums[i] - nums[i + 1]));
        }
        if (i > 0)
        {
          moves = max(moves, max(0, 1 + nums[i] - nums[i - 1]));
        }
        res += moves;
      }

      ans = min(ans, res);
    }

    return ans;
  }
};

int main()
{
  int n;
  cin >> n;
  vector<int> a;
  for (int i = 0; i < n; i++)
  {
    int j;
    cin >> j;
    a.push_back(j);
  }
  Solution sol;
  cout << sol.movesToMakeZigzag(a) << "\n";
  return 0;
}
