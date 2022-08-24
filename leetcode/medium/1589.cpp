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
  int maxSumRangeQuery(vector<int> &nums, vector<vector<int>> &requests)
  {
    int n = nums.size();
    int m = requests.size();
    vector<ll> cnt(n + 1, 0);
    for (const auto r : requests)
    {
      cnt[r[0]]++;
      cnt[r[1] + 1]--;
    }

    for (int i = 1; i < n; i++)
    {
      cnt[i] = (cnt[i] + cnt[i - 1]) % MOD;
    }

    sort(cnt.rbegin(), cnt.rend());
    sort(nums.rbegin(), nums.rend());

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
      ans = (ans + (cnt[i] * nums[i]) % MOD) % MOD;
    }

    return ans;
  }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  vector<int> nums;
  vector<vector<int>> reqs;
  int n, m;
  cin >> n >> m;
  nums = vector<int>(n, 0);
  reqs = vector<vector<int>>(m, vector<int>(2, 0));
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }
  for (int i = 0; i < m; i++)
  {
    cin >> reqs[i][0] >> reqs[i][1];
  }
  Solution sol;
  cout << sol.maxSumRangeQuery(nums, reqs) << "\n";
  return 0;
}
