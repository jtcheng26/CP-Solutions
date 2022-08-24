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
ll a[200006];

ll solve()
{
  ll res = 0;
  // int same = 0;
  // for (int i = 0; i < n - 1; i++)
  // {
  //   if (a[i] == a[n - 1])
  //   {
  //     same++;
  //   }
  // }
  // ll need = a[0] + n - 1;
  // ll top = max(need, a[n - 1] + same);
  // res = top - a[n - 1];
  // for (int i = n - 2; i >= 0; i--)
  // {
  //   res = max(res, top - (n - 1 - i) - a[i]);
  // }

  // for (int i = 0; i < n; i++)
  // {
  //   ll should = a[0] + n - 1 - (n - 1 - i) - a[i];
  //   if (should < 0)
  //   {
  //     a[0]++;
  //     should++;
  //   }
  //   res = max(res, should);
  // }

  for (int i = 1; i < n; i++)
  {
    ll need = a[i - 1] + 1;
    ll cost = 0;
    if (need < a[i])
    {
      res += a[i] - need;
      need = a[i];
    }
    else
    {
      cost = need - a[i];
    }
    a[i] = need;
    res = max(res, cost);
  }
  return res;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  cout << solve() << "\n";
  return 0;
}