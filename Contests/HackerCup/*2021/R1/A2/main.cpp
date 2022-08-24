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

int n;
string s;

int solve()
{
  ll dp[n];
  for (int i = 0; i < n; i++)
  {
    dp[i] = 0;
  }
  int x = -1;
  int o = -1;
  for (int i = 0; i < n; i++)
  {
    if (s[i] == 'F' && i > 0)
      dp[i] = dp[i - 1];
    else if (s[i] == 'X')
    {
      if (o != -1)
      {
        dp[i] = ((dp[o] + o) % MOD + 1) % MOD;
      }
      x = i;
    }
    else if (s[i] == 'O')
    {
      if (x != -1)
      {
        dp[i] = ((dp[x] + x) % MOD + 1) % MOD;
      }
      o = i;
    }
  }
  ll res = 0;
  for (int i = 0; i < n; i++)
  {
    res = (res + dp[i]) % MOD;
  }
  return res;
}

int main()
{
  int t;
  cin >> t;
  for (int c = 1; c <= t; c++)
  {
    cin >> n;
    cin >> s;
    cout << "Case #" << c << ": " << solve() << "\n";
  }
  return 0;
}