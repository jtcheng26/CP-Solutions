// Time: 23:10

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
  int go(int l, int r, int n, const string &s, vector<vector<int>> &dp)
  {
    if (l >= r)
      return 0;
    else if (dp[l][r] <= n)
    {
      return dp[l][r];
    }

    if (s[l] == s[r])
    {
      dp[l][r] = go(l + 1, r - 1, n, s, dp);
    }
    else
    {
      dp[l][r] = 1 + min(go(l + 1, r, n, s, dp), go(l, r - 1, n, s, dp));
    }

    return dp[l][r];
  }
  int minInsertions(string s)
  {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, INF));

    return go(0, n - 1, n, s, dp);
  }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  Solution sol;
  cout << sol.minInsertions(s) << "\n";
  return 0;
}
