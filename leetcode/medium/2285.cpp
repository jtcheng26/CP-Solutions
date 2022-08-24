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
  long long maximumImportance(int n, vector<vector<int>> &roads)
  {
    vector<int> in(n, 0);
    int m = roads.size();
    for (int i = 0; i < m; i++)
    {
      in[roads[i][0]]++;
      in[roads[i][1]]++;
    }

    sort(in.begin(), in.end());

    long long ans = 0;
    for (long long i = 1; i <= n; i++)
    {
      ans += i * in[i - 1];
    }

    return ans;
  }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> roads(m, vector<int>(2, 0));
  for (int i = 0; i < m; i++)
  {
    cin >> roads[i][0] >> roads[i][1];
  }
  Solution sol;
  cout << sol.maximumImportance(n, roads) << "\n";
  return 0;
}
