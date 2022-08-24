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

ll n, a, b;

bool solve()
{
  if (n == 1)
    return true;
  if (a == 1)
    return (n - 1) % b == 0;
  for (ll k = 1; k <= n; k *= a)
  {
    if ((n - k) % b == 0)
      return true;
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
    cin >> n >> a >> b;
    cout << (solve() ? "Yes" : "No") << "\n";
  }
  return 0;
}