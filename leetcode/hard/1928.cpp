#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <tuple>

#define INF 100000000

using namespace std;

class Solution
{
public:
  int minCost(int maxTime, vector<vector<int>> &edges, vector<int> &passingFees)
  {
    int n = passingFees.size();

    int dp[n][maxTime + 1];
    int v[n][maxTime + 1];
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j <= maxTime; j++)
      {
        dp[i][j] = -1;
        v[i][j] = false;
      }
    }

    vector<vector<pair<int, int>>> adj;
    for (int i = 0; i < n; i++)
    {
      adj.push_back(vector<pair<int, int>>());
    }

    for (vector<int> &edge : edges)
    {
      adj[edge[0]].push_back(make_pair(edge[1], edge[2]));
      adj[edge[1]].push_back(make_pair(edge[0], edge[2]));
    }

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;
    q.push(make_tuple(passingFees[0], 0, 0));
    dp[0][0] = passingFees[0];

    while (!q.empty())
    {
      tuple<int, int, int> top = q.top();
      int c = get<0>(top);
      int t = get<1>(top);
      int i = get<2>(top);
      q.pop();
      if (v[i][t])
        continue;
      v[i][t] = true;
      if (i == n - 1)
      {
        return c;
      }
      for (pair<int, int> &edge : adj[i])
      {
        if (t + edge.second <= maxTime)
        {
          int nxt = edge.first;
          int nxtTime = t + edge.second;
          int nxtCost = c + passingFees[nxt];
          if (!v[nxt][nxtTime] && (dp[nxt][nxtTime] == -1 || nxtCost < dp[nxt][nxtTime]))
          {
            dp[nxt][nxtTime] = nxtCost;
            q.push(make_tuple(nxtCost, nxtTime, nxt));
          }
        }
      }
    }

    return -1;
  }
};

int main()
{
  int t;
  cin >> t;
  vector<vector<int>> edges;
  vector<int> passingFees;
  int e;
  cin >> e;
  for (int i = 0; i < e; i++)
  {
    vector<int> edge;
    int x, y, t;
    cin >> x >> y >> t;
    edge.push_back(x);
    edge.push_back(y);
    edge.push_back(t);
    edges.push_back(edge);
  }
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int j;
    cin >> j;
    passingFees.push_back(j);
  }
  Solution sol;
  cout << sol.minCost(t, edges, passingFees) << "\n";
  return 0;
}
