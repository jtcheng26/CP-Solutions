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
#define LIM 1000001

typedef long long ll;

using namespace std;

int n, e;
int a[200006];
bool p[1000006];
ll dp1[200006];
ll dp2[200006];

// ans = sum for all primes of max(0, dp1[i] * dp2[i] - 1)
// p[bool] - find all primes
// dp1[int], dp2[int] - find all consecutive e-distant 1s before and after each

void precomp()
{
  for (int i = 0; i <= LIM; i++)
    p[i] = true;
  p[0] = p[1] = false;
  for (int i = 2; i * i <= LIM; i++)
  {
    if (p[i])
    {
      for (int k = LIM / i, j = i * k; k >= i; k--, j -= i)
      {
        if (p[k])
          p[j] = false;
      }
    }
  }
}

ll solve()
{
  ll ans = 0;
  for (int i = 0; i < n; i++)
  {
    dp1[i] = dp2[i] = 0;
  }

  for (int i = e; i < n; i++)
  {
    if (a[i - e] == 1)
      dp1[i] = dp1[i - e] + 1;
  }
  for (int i = n - e - 1; i >= 0; i--)
  {
    if (a[i + e] == 1)
      dp2[i] = dp2[i + e] + 1;
  }

  for (int i = 0; i < n; i++)
  {
    if (p[a[i]])
    {
      ans += (dp1[i] + 1) * (dp2[i] + 1) - 1;
    }
  }

  return ans;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  precomp();
  int t;
  cin >> t;
  while (t--)
  {
    cin >> n >> e;
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    cout << solve() << "\n";
  }
  return 0;
}