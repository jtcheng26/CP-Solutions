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

struct pt
{
  int a, b, i;
};

int n;
pt a[100006];
pt *b[2][100006];
int c[2][100006];

bool cmpa(pt *a, pt *b)
{
  return a->a > b->a;
}

bool cmpb(pt *a, pt *b)
{
  return a->b > b->b;
}

vector<bool> solve()
{
  vector<bool> res;
  for (int i = 0; i < n; i++)
  {
    res.pb(false);
    a[i].i = i;
    b[0][i] = &a[i];
    b[1][i] = &a[i];
    c[0][i] = INF;
    c[1][i] = INF;
  }
  sort(b[0], b[0] + n, cmpa);
  sort(b[1], b[1] + n, cmpb);
  for (int i = 0; i < n; i++)
  {
    b[0][i]->a = n - i - 1;
    b[1][i]->b = n - i - 1;
  }
  c[0][0] = b[0][0]->b;
  c[1][0] = b[1][0]->a;
  for (int i = 1; i < n; i++)
  {
    c[0][i] = min(c[0][i - 1], b[0][i]->b);
    c[1][i] = min(c[1][i - 1], b[1][i]->a);
  }
  int now[2] = {0, 0};
  int flip = 0;
  while (now[0] < n && now[1] < n)
  {
    if (c[flip][now[flip]] < n - now[!flip] - 1)
    {
      now[!flip] = n - c[flip][now[flip]] - 1;
    }
    else
      break;
    flip = !flip;
  }
  // cout << now[0] << " " << now[1] << "\n";
  for (int i = 0; i < n; i++)
  {
    if (b[0][i]->a >= n - now[0] - 1)
      res[b[0][i]->i] = true;
    if (b[1][i]->b >= n - now[1] - 1)
      res[b[1][i]->i] = true;
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
    for (int j = 0; j < n; j++)
    {
      cin >> a[j].a;
    }
    for (int j = 0; j < n; j++)
    {
      cin >> a[j].b;
    }
    vector<bool> ans = solve();
    for (bool j : ans)
    {
      cout << j << "";
    }
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
      b[0][i] = b[1][i] = NULL;
    }
  }
  return 0;
}