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
int pfx[200006];

vector<int> solve()
{
  vector<int> res;
  for (int i = 1; i < n; i++)
  {
    if (a[i - 1] > a[i])
    {
      pfx[a[i]]++;
      pfx[a[i - 1]]--;
    }
  }
  for (int i = 1; i <= n; i++)
  {
    pfx[i] += pfx[i - 1];
  }
  for (int i = 0; i <= n; i++)
  {
    res.pb(pfx[i]);
  }
  return res;
}

int main()
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  vector<int> ans = solve();
  for (int j : ans)
  {
    cout << j << "\n";
  }
  return 0;
}