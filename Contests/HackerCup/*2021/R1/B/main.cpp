#include <iostream>
#include <fstream>
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

int n, m, a, b;

vector<vector<int>> solve()
{
  vector<vector<int>> ans;
  if (a < n + m - 1 || b < n + m - 1)
    return ans;
  for (int i = 0; i < n; i++)
  {
    vector<int> g;
    for (int j = 0; j < m; j++)
    {
      g.pb(1);
    }
    ans.pb(g);
  }
  ans[n - 1][0] = b - (n + m - 2);
  ans[n - 1][m - 1] = a - (n + m - 2);
  return ans;
}

int main()
{
  //ifstream cin (".in");
  //ofstream cout (".out");
  int t;
  cin >> t;
  for (int c = 1; c <= t; c++)
  {
    cin >> n >> m >> a >> b;
    vector<vector<int>> ans = solve();
    cout << "Case #" << c << ": " << (ans.size() == 0 ? "Impossible" : "Possible") << "\n";
    for (int i = 0; i < ans.size(); i++)
    {
      for (int j = 0; j < ans[i].size(); j++)
      {
        cout << ans[i][j] << " ";
      }
      cout << "\n";
    }
  }
  return 0;
}