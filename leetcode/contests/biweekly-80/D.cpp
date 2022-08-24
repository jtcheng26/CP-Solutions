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
  long long countSubarrays(vector<int> &nums, long long k)
  {
    long long ans = 0;
    int n = nums.size();
    int l = 0;
    int r = 0;
    long long sum = nums[0];
    ans = 0;
    while (r < n - 1)
    {
      r++;
      sum += nums[r];
      // cout << sum * (r - l + 1) << "\n";
      if (sum * (r - l + 1) < k)
      {
        ans += r - l;
        continue;
      }
      else
      {
        // cout << l << " " << r << "\n";

        // ans += ((r - l + 1) * (r - l)) / 2;
        while (l < r && sum * (r - l + 1) >= k)
        {
          sum -= nums[l];
          l++;
        }
        if (l < r && sum * (r - l + 1) < k)
        {
          ans += r - l;
        }
      }
    }

    for (int j : nums)
    {
      if (j < k)
        ans++;
    }

    // ans += ((r - l + 1) * (r - l)) / 2;

    return ans;
  }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> nums(n, 0);
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }
  Solution sol;
  cout << sol.countSubarrays(nums, k) << "\n";
  return 0;
}
