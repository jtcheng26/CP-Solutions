// Didn't like this one. Tedious and unfun. Too tired to write good code.
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

class Solution
{
public:
  int good(vector<int> &uh, int startAt, int moveCost, int pushCost, int targetSeconds)
  {
    int start = -1;
    for (int i = 0; i < 4; i++)
    {
      if (uh[i] != 0)
      {
        start = i;
        break;
      }
    }

    if (start == -1)
      return INF;
    if ((uh[0] * 10 + uh[1]) * 60 + uh[2] * 10 + uh[3] != targetSeconds)
      return INF;

    int res = 0;

    if (uh[start] == startAt)
      res += pushCost;
    else
      res += moveCost + pushCost;
    int curr = uh[start];
    for (int i = start + 1; i < 4; i++)
    {
      if (uh[i] != curr)
        res += moveCost + pushCost;
      else
        res += pushCost;
      curr = uh[i];
    }

    // cout << uh[0] << " " << uh[1] << " " << uh[2] << " " << uh[3] << "\n";

    return res;
  }
  int solve(int j, vector<int> &uh, int startAt, int moveCost, int pushCost, int targetSeconds)
  {
    int best = INF;
    if (j == 4)
    {
      best = good(uh, startAt, moveCost, pushCost, targetSeconds);
    }
    else
    {
      for (int i = 0; i <= 9; i++)
      {
        uh[j] = i;
        best = min(best, solve(j + 1, uh, startAt, moveCost, pushCost, targetSeconds));
      }
    }

    return best;
  }
  int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds)
  {
    vector<int> n(4, 0);

    return solve(0, n, startAt, moveCost, pushCost, targetSeconds);
  }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int start, move, push, target;
  cin >> start >> move >> push >> target;
  Solution sol;
  cout << sol.minCostSetTime(start, move, push, target) << "\n";
  return 0;
}
