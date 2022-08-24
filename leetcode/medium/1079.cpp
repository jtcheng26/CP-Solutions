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
  int fact[10];
  int solve(int j, vector<int> &a, vector<int> &cnt, int n)
  {
    if (j == n)
    {
      int ans = 0;
      for (int i = 0; i < n; i++)
      {
        ans += a[i];
      }
      ans = ans == 0 ? 0 : fact[ans];
      for (int i = 0; i < n; i++)
      {
        if (a[i] > 1)
          ans /= fact[a[i]];
      }
      return ans;
    }
    else
    {
      int ans = 0;
      for (int i = 0; i <= cnt[j]; i++)
      {
        a[j] = i;
        ans += solve(j + 1, a, cnt, n);
      }
      return ans;
    }
  }
  int numTilePossibilities(string tiles)
  {
    if (fact[0] != 1)
    {
      fact[0] = 1;
      for (int i = 1; i <= 7; i++)
      {
        fact[i] = i * fact[i - 1];
      }
    }

    int n = tiles.length();
    sort(tiles.begin(), tiles.end());

    vector<int> cnt;
    int k = 1;
    vector<int> a;
    for (int i = 1; i < n; i++)
    {
      if (tiles[i] != tiles[i - 1])
      {
        cnt.push_back(k);
        a.push_back(0);
        k = 1;
      }
      else
      {
        k++;
      }
    }
    cnt.push_back(k);
    a.push_back(0);

    return solve(0, a, cnt, a.size());
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
  cout << sol.numTilePossibilities(s) << "\n";
  return 0;
}
