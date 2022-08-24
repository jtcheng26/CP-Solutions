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
int a[100006];

int solve()
{
  int res = 0;
  priority_queue<int> pq;
  sort(a, a + m);
  for (int i = 1; i < m; i++)
  {
    pq.push(a[i] - a[i - 1] - 1);
  }

  pq.push(n - a[m - 1] + a[0] - 1);

  int k = 0;

  while (!pq.empty())
  {
    int x = pq.top();
    pq.pop();
    if (x - k <= 0)
      return n - res;
    if (x - k == 1)
    {
      k += 2;
      res++;
    }
    else
    {
      x -= k;
      x -= 1;
      k += 4;
      res += x;
    }
  }
  return n - res;
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
    for (int i = 0; i < m; i++)
    {
      cin >> a[i];
    }
    cout << solve() << "\n";
  }
  return 0;
}