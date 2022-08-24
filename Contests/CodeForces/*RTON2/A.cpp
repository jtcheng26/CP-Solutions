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

int n, m;
string a, b;

bool solve()
{
  int i = n - 1;
  int j = m - 1;
  while (j > 0 && i >= 0)
  {
    if (a[i] == b[j])
    {
      i--;
      j--;
    }
    else
    {
      break;
    }
  }
  // cout << j << " " << i << "\n";
  if (j == 0)
  {
    while (i >= 0)
    {
      if (a[i] == b[0])
      {
        return true;
      }
      i--;
    }
  }
  return false;
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
    cin >> n >> m;
    cin >> a;
    cin >> b;
    cout << (solve() ? "YES" : "NO") << "\n";
  }
  return 0;
}
