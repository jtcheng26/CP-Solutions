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

int n, k;
int a[200006];

vector<int> solve()
{
  int res = 0;
  vector<int> ans;
  int l = a[n - 1] - k;
  int r = a[n - 1] + k;
  for (int i = n - 1; i >= 0; i--)
  {
    if (l <= a[i] && a[i] <= r)
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
    ans.pb(res);
  }

  return ans;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  vector<int> ans = solve();
  for (int i = int(ans.size()) - 1; i >= 0; i--)
  {
    cout << ans[i] << (i == 0 ? "\n" : " ");
  }
  return 0;
}