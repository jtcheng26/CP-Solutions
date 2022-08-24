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
  vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
  {
    int n = spells.size();
    int m = potions.size();
    sort(potions.begin(), potions.end());

    vector<int> ans(n, 0);

    for (int i = 0; i < n; i++)
    {
      if (spells[i] == 0 && success != 0)
      {
        ans[i] = 0;
        continue;
      }
      int l = 0;
      int r = m;
      int k = m;
      while (l < r)
      {
        int mid = (l + r) / 2;
        if (((long long)potions[mid]) * spells[i] < success)
        {
          l = mid + 1;
        }
        else
        {
          r = mid;
          k = mid;
        }
      }
      // cout << i << " " << k << "\n";
      ans[i] = m - k;
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
  ll k;
  cin >> n >> m >> k;
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
  vector<int> ans = sol.successfulPairs(a, b, k);
  for (int j : ans)
  {
    cout << j << " ";
  }
  cout << "\n";
  return 0;
}
