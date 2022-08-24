// Pretty simple, one-pass
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
  int maxAbsoluteSum(vector<int> &nums)
  {
    int n = nums.size();
    int ans = 0;
    int mn = 0;
    int mx = 0;

    for (int i = 0; i < n; i++)
    {
      if (nums[i] < mn)
      {
        mn = nums[i];
      }

      if (nums[i] > mx)
      {
        mx = nums[i];
      }

      ans = max(ans, abs(nums[i] - mn));
      ans = max(ans, abs(nums[i] - mx));
      if (i < n - 1)
        nums[i + 1] += nums[i];
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
  cout << sol.maxAbsoluteSum(nums) << "\n";
  return 0;
}
