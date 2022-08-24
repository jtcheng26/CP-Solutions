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
  int good[12][12];
  bool in(int i, int mask)
  {
    return (1 & (mask >> i));
  }
  int without(int i, int mask)
  {
    return (1 << i) ^ mask;
  }
  void printMask(int mask)
  {
    for (int i = 0; i < 12; i++)
    {
      if (in(i, mask))
      {
        cout << "1";
      }
      else
      {
        cout << "0";
      }
    }
    cout << "\n";
  }
  int solve(int mask, int end, vector<int> &nums, vector<vector<int>> &dp, int n)
  {
    if (dp[mask][end] != -1)
      return dp[mask][end];
    int ans = 0;

    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
      if (in(i, mask))
      {
        cnt++;
        if (i != end && good[i][end])
        {
          ans += solve(without(end, mask), i, nums, dp, n);
        }
      }
    }

    if (cnt == 1)
      ans = 1;

    dp[mask][end] = ans;

    // printMask(mask);
    // cout << dp[mask][end] << "\n";

    return ans;
  }
  int numSquarefulPerms(vector<int> &nums)
  {
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        int sq = sqrt(nums[i] + nums[j]);
        if (sq * sq == nums[i] + nums[j])
        {
          good[i][j] = good[j][i] = true;
        }
        else
        {
          good[i][j] = good[j][i] = false;
        }
      }
    }

    vector<vector<int>> dp(1 << n, vector<int>(n, -1));

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
      ans += solve((1 << n) - 1, i, nums, dp, n);
    }

    map<int, int> cnt;
    for (int i = 0; i < n; i++)
    {
      cnt[nums[i]]++;
      ans /= cnt[nums[i]];
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
  vector<int> nums(n, 0);
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }
  Solution sol;
  cout << sol.numSquarefulPerms(nums) << "\n";
  return 0;
}
