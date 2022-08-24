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
int a[1006];

vector<int> solve()
{
  vector<int> res(n, 0);
  vector<int> used(n + 1, 0);
  priority_queue<int, vector<int>, greater<int>> pq;
  for (int i = 1; i <= n; i++)
  {
    pq.push(i);
  }
  for (int i = 0; i < n; i++)
  {
    if (i == n - 2 && !used[a[i + 1]])
    {
      used[a[i + 1]] = true;
      res[i] = a[i + 1];
    }
    while (res[i] == 0)
    {
      if (pq.empty())
      {
        res.clear();
        return res;
      }
      int top = pq.top();
      if (!used[top] && top != a[i])
      {
        res[i] = top;
        used[top] = 1;
        pq.pop();
      }
      else
      {
        pq.pop();
        if (pq.empty())
        {
          res.clear();
          return res;
        }
        res[i] = pq.top();
        used[pq.top()] = 1;
        pq.pop();
        pq.push(top);
      }
    }
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
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    vector<int> ans = solve();
    if (ans.empty())
    {
      cout << "-1"
           << "\n";
    }
    else
    {
      for (int i = 0; i < int(ans.size()); i++)
      {
        cout << ans[i] << (i == int(ans.size() - 1) ? "\n" : " ");
      }
    }
  }
  return 0;
}