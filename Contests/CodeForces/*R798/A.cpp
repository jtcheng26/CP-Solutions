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

int n, m, k;
char a[110];
char b[110];

string solve()
{
  string res = "";
  int ia = 0;
  int ib = 0;
  int streak = 0;
  int s = -1;
  sort(a, a + n);
  sort(b, b + m);
  while (ia < n && ib < m)
  {
    if (streak == k && s == 0)
    {
      res += b[ib];
      streak = 1;
      ib++;
      s = 1;
    }
    else if (streak == k && s == 1)
    {
      res += a[ia];
      streak = 1;
      ia++;
      s = 0;
    }
    else if (a[ia] < b[ib])
    {
      res += a[ia];
      ia++;
      if (s == 1)
      {
        streak = 1;
      }
      else
      {
        streak += 1;
      }
      s = 0;
    }
    else
    {
      res += b[ib];
      ib++;
      if (s == 0)
      {
        streak = 1;
      }
      else
      {
        streak += 1;
      }
      s = 1;
    }
  }
  return res;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--)
  {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    for (int j = 0; j < m; j++)
    {
      cin >> b[j];
    }
    cout << solve() << "\n";
  }
  return 0;
}
