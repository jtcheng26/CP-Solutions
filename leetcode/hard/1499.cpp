#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <array>

using namespace std;

class Solution
{
public:
  int findMaxValueOfEquation(vector<vector<int>> &points, int k)
  {
    int n = points.size();
    priority_queue<array<int, 2>> pq;
    pq.push({points[0][1] - points[0][0], points[0][0]});
    int ans = -300000000;
    for (int i = 1; i < n; i++)
    {
      array<int, 2> top = pq.top();
      while (!pq.empty() && (points[i][0] - top[1] > k))
      {
        pq.pop();
        top = pq.top();
      }
      if (points[i][0] - top[1] <= k)
      {
        ans = max(ans, points[i][0] + points[i][1] + top[0]);
      }
      pq.push({points[i][1] - points[i][0], points[i][0]});
    }
    return ans;
  }
};

int main()
{
  int n, k;
  cin >> n >> k;
  vector<vector<int>> points(n, vector<int>(2, 0));
  for (int i = 0; i < n; i++)
  {
    cin >> points[i][0] >> points[i][1];
  }
  Solution sol;
  cout << sol.findMaxValueOfEquation(points, k) << "\n";
}