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
int a[100006];
int pfx[1000006];

int solve()
{
  int res = 0;
  int j = 1;
  sort(a, a + n);
  for (int i = 0; i < n; i++)
  {
    if (a[i] >= j)
    {
      j++;
      res++;
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