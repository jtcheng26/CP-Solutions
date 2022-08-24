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

struct DSU
{
  vector<int> sz;
  vector<int> parent;

  void build(int size)
  {
    sz.resize(size + 1);
    parent.resize(size + 1);
  }

  int find_set(int v)
  {
    if (v == parent[v])
      return v;
    return parent[v] = find_set(parent[v]);
  }

  void make_set(int v)
  {
    parent[v] = v;
    sz[v] = 1;
  }

  void union_sets(int a, int b)
  {
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
      if (sz[a] < sz[b])
        swap(a, b);
      parent[b] = a;
      sz[a] += sz[b];
    }
  }
};

int n, d;
pair<int, int> req[1006];

vector<int> solve()
{
  vector<int> res;
  for (int i = 1; i <= d; i++)
  {
    res.pb(-1);
    DSU dsu;
    dsu.build(n + 1);
    bool counted[n + 1];
    vector<int> sets;
    for (int j = 1; j <= n; j++)
    {
      dsu.make_set(j);
      counted[j] = false;
    }
    int extra = 0;
    for (int j = 0; j < i; j++)
    {
      // cout << req[j].F << " " << req[j].S << "\n";
      if (dsu.find_set(req[j].F) != dsu.find_set(req[j].S))
      {
        dsu.union_sets(req[j].F, req[j].S);
      }
      else
      {
        extra++;
      }
    }
    for (int j = 1; j <= n; j++)
    {
      int s = dsu.find_set(j);
      if (!counted[s])
      {
        counted[s] = true;
        sets.pb(dsu.sz[s]);
      }
    }
    sort(sets.rbegin(), sets.rend());
    for (int j = 0; j < extra + 1; j++)
    {
      if (j < sets.size())
        res[i - 1] += sets[j];
    }
  }
  return res;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> d;
  for (int i = 0; i < d; i++)
  {
    cin >> req[i].F >> req[i].S;
  }
  vector<int> ans = solve();
  for (int j : ans)
  {
    cout << j << "\n";
  }
  return 0;
}