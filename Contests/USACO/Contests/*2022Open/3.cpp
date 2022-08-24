#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <random>

#define INF 1000000001
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

int n, b;
int parent[100006];        // 1-indexed
vector<int> child[100006]; // to find leaves
int ans[100006];
pair<int, int> rng[100006];
pair<int, int> dp[100006]; // biggest range node's parent can be in

bool dfs(int node, int k)
{
  dp[node].F = 0;
  dp[node].S = INF;
  for (int c : child[node])
  {
    bool poss = dfs(c, k);
    if (!poss)
      return false;
    dp[node].F = max(dp[node].F, dp[c].F);
    dp[node].S = min(dp[node].S, dp[c].S);
  }
  if (dp[node].S < dp[node].F)
    return false;
  if (rng[node].F > dp[node].S || rng[node].S < dp[node].F)
    return false;
  int add = node == 1 ? 0 : k;
  dp[node].F = max(dp[node].F, rng[node].F - add);
  dp[node].S = min(dp[node].S, rng[node].S + add);
  if (dp[node].S < dp[node].F)
    return false;
  return true;
}

void compute(int node, int k, int l, int r)
{
  if (node == 1)
  {
    ans[node] = dp[node].F;
  }
  else
  {
    dp[node].F = max(dp[node].F, rng[node].F);
    dp[node].S = min(dp[node].S, rng[node].S);
    ans[node] = max(dp[node].F, l);
  }
  for (int c : child[node])
  {
    compute(c, k, max(l, ans[node] - k), min(r, ans[node] + k));
  }
}

int solve()
{
  int l = 0;
  int r = 1000000001;
  int best = 0;
  while (l < r)
  {
    int mid = (l + r) / 2;
    if (dfs(1, mid))
    {
      compute(1, mid, 0, 0);
      best = mid;
      r = mid;
    }
    else
    {
      l = mid + 1;
    }
  }
  return best;
}

int mx[12];
int mn[12];
int val[12];

void dfsb(int node)
{
  if (parent[node] != 0)
  {
    mx[node] = max(mx[parent[node]], val[node]);
    mn[node] = min(mn[parent[node]], val[node]);
  }
  else
  {
    mx[node] = val[node];
    mn[node] = val[node];
  }
  for (int c : child[node])
  {
    dfsb(c);
  }
}

int brute(int j)
{
  int ans = INF;
  if (j == n + 1)
  {
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
      mx[i] = 0;
      mn[i] = INF;
    }
    dfsb(1);
    // cout << "uhh"
    //      << "\n";
    for (int i = 1; i <= n; i++)
    {
      // cout << mx[i] << " " << mn[i] << "\n";
      ans = max(ans, mx[i] - mn[i]);
    }
    return ans;
  }
  else
  {
    for (int i = 0; i <= 2; i++)
    {
      val[j] = rng[j].F + i;
      ans = min(ans, brute(j + 1));
    }
  }

  return ans;
}

void stress()
{
  b = 0;
  n = 5;
  // random_device rd; // only used once to initialise (seed) engine
  default_random_engine generator(4);

  mt19937 rnum(
      generator());                         // random-number engine used (Mersenne-Twister in this case)
  uniform_int_distribution<int> uni(0, 10); // guaranteed unbiased
  // uniform_int_distribution<int> uni2();
  // parent[2] = 1;
  // parent[3] = 1;
  // parent[4] = 2;
  // parent[5] = 2;
  // parent[6] = parent[7] = 3;
  // parent[8] = parent[9] = 4;
  // parent[10] = parent[11] = 6;

  parent[2] = 1;
  parent[3] = 2;
  parent[4] = 3;
  parent[5] = 4;

  for (int i = 2; i <= n; i++)
  {
    child[parent[i]].pb(i);
  }

  for (int t = 0; t < 20; t++)
  {
    for (int i = 1; i <= n; i++)
    {
      rng[i].F = uni(rnum);
      rng[i].S = rng[i].F + 2;
      // cout << rng[i].F << " " << rng[i].S << "\n";
    }
    int expected = brute(1);
    int got = solve();
    // cout << expected << " " << got << "\n";
    if (expected != got)
    {
      cout << "Fail"
           << "\n";
      for (int i = 1; i <= n; i++)
      {
        cout << rng[i].F << " " << rng[i].S << "\n";
      }
      break;
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // stress();
  int t;
  cin >> t >> b;
  while (t--)
  {
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
      child[i].clear();
    }
    for (int i = 1; i <= n; i++)
    {
      parent[i] = -1;
    }
    for (int i = 2; i <= n; i++)
    {
      int j;
      cin >> j;
      parent[i] = j;
      child[j].pb(i);
    }
    for (int i = 1; i <= n; i++)
    {
      int l, r;
      cin >> l >> r;
      rng[i].F = l;
      rng[i].S = r;
    }
    cout << solve() << "\n";
    if (b == 1)
    {
      for (int i = 1; i <= n; i++)
      {
        cout << ans[i] << (i == n ? "\n" : " ");
      }
    }
  }
  return 0;
}