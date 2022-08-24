/*

dp1[i] = sum of k-1 greatest dp1[j] of k children
dp2[i] = dp2[j] for smallest dp1[j] + dp2[j] of children
ans[i] = dp1[i] + dp2[i]

 5
3 4

dp1[left] = 0
dp2[left] = 3

dp1[right] = 0
dp2[right] = 4

dp1[root] = 4
dp2[root] = 5

ans[root] = 4 + 5 = 9

  60
20  40
50

 3
2 1 4

5

*/

#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int n;
vector<int> children[100006];
int parent[100006];
ll w[100006];

ll dp1[100006]; // sum
ll dp2[100006];

void dfs(int node)
{
  if (children[node].empty())
  {
    dp2[node] = w[node];
    dp1[node] = 0;
  }
  else
  {
    int mn = -1;
    for (int child : children[node])
    {
      dfs(child);
      if (mn == -1 || dp2[child] < dp2[mn])
      {
        mn = child;
      }
    }
    dp2[node] = max(dp2[mn], w[node]);
    for (int child : children[node])
    {
      dp1[node] += dp1[child];
      if (child != mn)
      {
        dp1[node] += dp2[child];
      }
    }
  }
}

ll solve()
{
  ll ans = 0;
  for (int i = 1; i <= n; i++)
  {
    if (parent[i] == 0)
    {
      dfs(i);
      ans += dp1[i] + dp2[i];
    }
  }
  return ans;
}

int main()
{
  int t;
  cin >> t;
  for (int c = 1; c <= t; c++)
  {
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
      children[i].clear();
      dp1[i] = dp2[i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
      cin >> w[i];
    }
    for (int i = 1; i <= n; i++)
    {
      int p;
      cin >> p;
      parent[i] = p;
      children[p].push_back(i);
    }
    cout << "Case #" << c << ": " << solve() << "\n";
  }
}