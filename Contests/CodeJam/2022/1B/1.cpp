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
int a[200006];

int solve()
{
  int res = 0;
  int l = 0;
  int r = n - 1;
  int most = 0;
  while (l <= r)
  {
    int take = 0;
    if (a[l] < a[r])
    {
      take = a[l];
      l++;
    }
    else
    {
      take = a[r];
      r--;
    }
    if (take >= most)
    {
      res++;
      most = take;
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
  for (int z = 1; z <= t; z++)
  {
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    cout << "Case #" << z << ": " << solve() << "\n";
  }
  return 0;
}