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
int parent[200006];
int perm[200006];
int depth[200006];

vector<int> no()
{
  return vector<int>(1, -1);
}

vector<int> solve()
{
  vector<int> ans(n, 0);

  int maxh = 0;
  if (parent[perm[1]] != perm[1])
    return no();
  depth[perm[1]] = 0;
  for (int i = 2; i <= n; i++)
  {
    if (depth[parent[perm[i]]] == -1)
      return no();
    else
    {
      depth[perm[i]] = maxh + 1;
      ans[perm[i] - 1] = (maxh + 1) - depth[parent[perm[i]]];
      maxh++;
    }
  }

  return ans;
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
    for (int i = 1; i <= n; i++)
    {
      depth[i] = -1;
    }
    for (int i = 1; i <= n; i++)
    {
      int j;
      cin >> j;
      parent[i] = j;
    }
    for (int i = 1; i <= n; i++)
    {
      cin >> perm[i];
    }
    vector<int> ans = solve();
    for (int i = 0; i < ans.size(); i++)
    {
      cout << ans[i] << (i == ans.size() - 1 ? "\n" : " ");
    }
  }
  return 0;
}