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
pair<int, int> a[200001];

bool good(int k)
{
  int rem = k;
  for (int i = 0; i < n; i++)
  {
    if (a[i].S >= rem - 1 && a[i].F >= k - rem)
    {
      rem--;
    }
  }
  return rem <= 0;
}

int solve()
{
  int res = 0;
  int l = 1;
  int r = n + 1;
  while (l < r)
  {
    int mid = (l + r) / 2;
    bool valid = good(mid);
    if (valid)
    {
      res = mid;
      l = mid + 1;
    }
    else
    {
      r = mid;
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
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      cin >> a[i].S;
      cin >> a[i].F;
    }
    cout << solve() << "\n";
  }
  return 0;
}