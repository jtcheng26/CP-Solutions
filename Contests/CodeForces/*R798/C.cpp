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
vector<int> a[300006];

int dfs(int root, int parent)
{
  if (root != 1 && a[root].size() < 3)
    return a[root].size() - 1;
  if (root == 1 && a[root].size() < 2)
    return a[root].size();
  int minInfected = n;
  for (int child : a[root])
  {
    if (child != parent)
      minInfected = min(minInfected, 2 + dfs(child, root));
  }
  // cout << root << " " << minInfected << "\n";
  return minInfected;
}

int solve()
{
  int ans = 1 + dfs(1, 0);
  return n - ans;
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
      a[i].clear();
    }
    for (int i = 0; i < n - 1; i++)
    {
      int u, v;
      cin >> u >> v;
      a[u].pb(v);
      a[v].pb(u);
    }
    cout << solve() << "\n";
  }
  return 0;
}