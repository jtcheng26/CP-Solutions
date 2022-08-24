// Constraints tripped me up here. Annoying that they're lower than necessary.
// Good lesson to not optimize to the constraints.
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
/*

*/

struct DSU
{
  vector<int> sz;
  vector<int> a;
  void init(int n)
  {
    a.resize(n + 1, 0);
    sz.resize(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
      make_set(i);
    }
  }
  void make_set(int i)
  {
    a[i] = i;
    sz[i] = 1;
  }
  int find_set(int i)
  {
    if (a[i] == i)
      return i;
    return a[i] = find_set(a[i]);
  }
  void union_sets(int b, int c)
  {
    // b = find_set(b);
    // c = find_set(b);
    if (b != c)
    {
      if (sz[b] < sz[c])
        swap(b, c);
      sz[b] += sz[c];
      sz[c] = 0;
      a[c] = b;
    }
  }
};

class Solution
{
public:
  vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges)
  {
    int n = edges.size();
    DSU dsu;
    dsu.init(n);
    vector<int> par(n + 1, -1);
    vector<int> mn;
    vector<int> alt;
    for (int i = 0; i < n; i++)
    {
      int l = dsu.find_set(edges[i][0]);
      int r = dsu.find_set(edges[i][1]);
      // cout << l << r << "\n";
      if (l != r)
      {
        if (par[edges[i][1]] != -1)
        {
          mn = edges[i];
          alt = {par[edges[i][1]], edges[i][1]};
          continue;
        }
        par[edges[i][1]] = edges[i][0];
        dsu.union_sets(l, r);
      }
      else
      {
        if (mn.size() == 0)
          mn = edges[i];
      }
    }

    if (dsu.sz[dsu.find_set(1)] == n)
    {
      return mn;
    }

    return alt;
  }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  Solution sol;
  vector<vector<int>> edges(n, vector<int>(2, 0));
  for (int i = 0; i < n; i++)
  {
    cin >> edges[i][0] >> edges[i][1];
  }
  vector<int> ans = sol.findRedundantDirectedConnection(edges);
  for (int i : ans)
  {
    cout << i << " ";
  }
  cout << "\n";
  return 0;
}
