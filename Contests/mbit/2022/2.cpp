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

int n, q;
int a[5006];

int solve()
{
  bool up[n];
  for (int i = 1; i <= n; i++)
  {
    up[i] = true;
  }
  for (int i = 0; i < q; i++)
  {
    up[a[i]] = !up[a[i]];
    bool good = true;
    for (int j = 1; j <= n; j++)
    {
      if (up[j])
      {
        good = false;
        break;
      }
    }
    if (good)
      return i + 1;
  }
  return -1;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> q;
  for (int i = 0; i < q; i++)
  {
    cin >> a[i];
  }
  cout << solve() << "\n";
  return 0;
}