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
int a[3][4];
int b[4];

int min3(int a, int b, int c)
{
  return min(min(a, b), c);
}

bool solve()
{
  int sum = 0;
  for (int i = 0; i < 4; i++)
  {
    b[i] = min(1000000 - sum, min3(a[0][i], a[1][i], a[2][i]));
    sum += b[i];
  }
  return sum == 1000000;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for (int z = 1; z <= t; z++)
  {
    for (int i = 0; i < 3; i++)
    {
      for (int j = 0; j < 4; j++)
      {
        cin >> a[i][j];
      }
    }
    bool ans = solve();
    cout << "Case #" << z << ": ";
    if (!ans)
    {
      cout << "IMPOSSIBLE"
           << "\n";
    }
    else
    {
      for (int i = 0; i < 4; i++)
      {
        cout << b[i] << (i == 3 ? "\n" : " ");
      }
    }
  }
  return 0;
}