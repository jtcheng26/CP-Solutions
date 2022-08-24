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

ll facts[42];

void precomp()
{
  facts[0] = 1;
  for (int i = 1; i <= 40; i++)
  {
    facts[i] = (facts[i - 1] * i) % MOD;
  }
}

struct pt
{
  int x, y;
};

struct tri
{
  int a, b, c;
};

ll sign(pt p1, pt p2, pt p3) // via https://stackoverflow.com/questions/2049582/how-to-determine-if-a-point-is-in-a-2d-triangle
{
  return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
}

bool isInside(pt p, pt v1, pt v2, pt v3) // via https://stackoverflow.com/questions/2049582/how-to-determine-if-a-point-is-in-a-2d-triangle
{
  float d1, d2, d3;
  bool has_neg, has_pos;

  d1 = sign(p, v1, v2);
  d2 = sign(p, v2, v3);
  d3 = sign(p, v3, v1);

  has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
  has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

  return !(has_neg && has_pos);
}

int n;
pt pts[42];
int outside[42][42][42];

// C function for extended Euclidean Algorithm
ll gcdExtended(ll a, ll b, ll *x, ll *y)
{
  if (a == 0)
  {
    *x = 0, *y = 1;
    return b;
  }
  ll x1, y1;
  ll gcd = gcdExtended(b % a, a, &x1, &y1);
  *x = y1 - (b / a) * x1;
  *y = x1;
  return gcd;
}

ll modInverse(ll a, ll m)
{
  ll x, y;
  ll g = gcdExtended(a, m, &x, &y);
  if (g != 1)
    return -1;
  else
  {
    // m is added to handle negative x
    ll res = (x % m + m) % m;
    return res;
  }
}

ll prob(ll a, ll b)
{
  return (facts[a] * modInverse(facts[b], MOD)) % MOD;
}

ll dp[42][42][42];

void go(int i, int j, int k)
{
  for (int l = 0; l < n; l++)
  {
    if (l == i || l == j || l == k)
      continue;
    if (isInside(pts[l], pts[i], pts[j], pts[k]))
    {
      for (int m = 0; m < 3; m++)
      {
        int tri[] = {i, j, k};
        tri[m] = l;
        sort(tri, tri + 3);
        int a = tri[0];
        int b = tri[1];
        int c = tri[2];
        dp[a][b][c] = (dp[a][b][c] + (dp[i][j][k] * prob(outside[a][b][c] - 1, outside[a][b][c] - outside[i][j][k] - 1)) % MOD) % MOD;
      }
    }
  }
  for (int l = 0; l < n; l++)
  {
    if (l == i || l == j || l == k)
      continue;

    if (isInside(pts[l], pts[i], pts[j], pts[k]))
    {
      for (int m = 0; m < 3; m++)
      {
        int tri[] = {i, j, k};
        tri[m] = l;
        sort(tri, tri + 3);
        int a = tri[0];
        int b = tri[1];
        int c = tri[2];
        go(a, b, c);
      }
    }
  }
}

bool cmp(tri a, tri b)
{
  return outside[a.a][a.b][a.c] < outside[b.a][b.b][b.c];
}

ll solve()
{
  ll res = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      for (int k = 0; k < n; k++)
      {
        dp[i][j][k] = 0;
        outside[i][j][k] = -1;
      }
    }
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      for (int k = j + 1; k < n; k++)
      {
        outside[i][j][k] = 0;
        for (int l = 0; l < n; l++)
        {
          if (l == i || l == j || l == k)
            continue;
          if (isInside(pts[l], pts[i], pts[j], pts[k]))
          {
            outside[i][j][k]++;
          }
          outside[i][j][k] = n - 3 - outside[i][j][k];
        }
      }
    }
  }
  bool good = false;
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      for (int k = j + 1; k < n; k++)
      {
        if (outside[i][j][k] == 0)
        {
          good = true;
          dp[i][j][k] = 1;
        }
      }
    }
  }
  if (!good)
    return 0;
  vector<tri> triangles;
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      for (int k = j + 1; k < n; k++)
      {
        triangles.push_back(tri{i, j, k});
      }
    }
  }
  sort(triangles.begin(), triangles.end(), cmp);
  go(triangles[0].a, triangles[0].b, triangles[0].c);
  for (tri t : triangles)
  {
    int i = t.a;
    int j = t.b;
    int k = t.c;
    res = (res + (prob(n - 3, n - 3 - outside[i][j][k]) * dp[i][j][k]) % MOD) % MOD;
  }

  return (6 * res) % MOD;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  precomp();
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int x, y;
    cin >> x >> y;
    pts[i].x = x;
    pts[i].y = y;
  }
  cout << solve() << endl;
  return 0;
}
