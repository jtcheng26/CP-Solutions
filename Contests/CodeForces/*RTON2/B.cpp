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

ll n, k;
ll a[200006];

int solve()
{
  int res = 0;
  ll l = a[0] - k;
  ll r = a[0] + k;
  for (int i = 0; i < n; i++)
  {
    if (l - k <= a[i] && a[i] <= r + k)
    {
      l = max(l, a[i] - k);
      r = min(r, a[i] + k);
    }
    else
    {
      res++;
      l = a[i] - k;
      r = a[i] + k;
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
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    cout << solve() << "\n";
  }
  return 0;
}