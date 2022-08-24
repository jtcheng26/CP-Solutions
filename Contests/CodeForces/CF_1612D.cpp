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

typedef unsigned long long ll;

using namespace std;

ll a, b, x;

bool solve()
{
  if (a < b)
    swap(a, b);
  while ((a > x || b > x) && a > 0 && b > 0)
  {
    if (b < x)
    {
      if (a % b == x % b)
        return true;
      else
        return false;
    }
    a = a % b;
    if (a < b)
      swap(a, b);
  }
  return (a == x || b == x);
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
    cin >> a >> b >> x;
    cout << (solve() ? "YES" : "NO") << "\n";
  }
  return 0;
}