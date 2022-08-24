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

/*

go to bottom, go to top, go to end
go to top, go to bottom, go to end


*/
int n, p;
int a[1006][106];

pair<int, int> close(int i, int k)
{
  int l = 0;
  int r = p;

  int closestL = 0;
  int closestR = 0;

  while (l < r)
  {
    int mid = (l + r) / 2;
    if (a[i][mid] < k)
    {
      closestL = mid;
      l = mid + 1;
    }
    else
    {
      r = mid;
      closestR = mid;
    }
  }

  return mp(closestL, closestR);
}

ll solve2()
{
  ll dp[n][p];
  for (int i = 0; i < n; i++)
  {
    // cout << a[i][0] << " " << a[i][p-1] << "\n";
    for (int j = 0; j < p; j++)
    {
      sort(a[i], a[i] + p);
      dp[i][j] = 0;
    }
  }
  for (int j = 0; j < p; j++)
  {
    if (a[0][j] < a[0][p - 1])
    {
      dp[0][j] = a[0][p - 1] + (a[0][p - 1] - a[0][j]);
    }
    else
    {
      dp[0][j] = a[0][j];
    }
  }
  for (int i = 1; i < n; i++)
  {
    // cout << "new"
    //  << "\n";
    for (int j = 0; j < p; j++)
    {
      // cout << a[i - 1][j] << " " << dp[i - 1][j] << "\n";
      for (int k = 0; k < p; k++)
      {
        ll l = a[i][0];
        ll h = a[i][p - 1];
        ll b = a[i - 1][j];
        ll e = a[i][k];

        ll lhe = abs(b - l) + h - l + abs(h - e);
        ll hle = abs(b - h) + h - l + abs(l - e);

        if (dp[i][k] == 0)
        {
          dp[i][k] = dp[i - 1][j] + min(lhe, hle);
        }
        else
        {
          dp[i][k] = min(dp[i][k], dp[i - 1][j] + min(lhe, hle));
        }
      }
    }
  }

  ll ans = dp[n - 1][0];
  for (int i = 1; i < p; i++)
  {
    ans = min(ans, dp[n - 1][i]);
  }
  return ans;
}

ll solve()
{
  ll dp[n][p];
  for (int i = 0; i < n; i++)
  {
    // cout << a[i][0] << " " << a[i][p-1] << "\n";
    for (int j = 0; j < p; j++)
    {
      sort(a[i], a[i] + p);
      dp[i][j] = 0;
    }
  }
  for (int j = 0; j < p; j++)
  {
    if (a[0][j] < a[0][p - 1])
    {
      dp[0][j] = a[0][p - 1] + (a[0][p - 1] - a[0][j]);
    }
    else
    {
      dp[0][j] = a[0][j];
    }
  }
  for (int i = 1; i < n; i++)
  {
    // cout << "new"
    //  << "\n";
    // for (int j = 0; j < p; j++)
    // {
    // cout << a[i - 1][j] << " " << dp[i - 1][j] << "\n";
    ll l = a[i][0];
    ll h = a[i][p - 1];

    pair<int, int> cl = close(i - 1, l);
    pair<int, int> cr = close(i - 1, h);
    // cout << l << " " << h << " " << a[i - 1][cl] << " " << a[i - 1][cr] << "\n";
    for (int k = 0; k < p; k++)
    {
      ll b = a[i - 1][cl.F];
      ll e = a[i][k];

      ll lhe = abs(b - l) + h - l + abs(h - e);
      ll hle = abs(b - h) + h - l + abs(l - e);
      dp[i][k] = dp[i - 1][cl.F] + min(lhe, hle);

      b = a[i - 1][cr.F];
      e = a[i][k];
      lhe = abs(b - l) + h - l + abs(h - e);
      hle = abs(b - h) + h - l + abs(l - e);
      dp[i][k] = min(dp[i][k], dp[i - 1][cr.F] + min(lhe, hle));

      b = a[i - 1][cl.S];
      e = a[i][k];
      lhe = abs(b - l) + h - l + abs(h - e);
      hle = abs(b - h) + h - l + abs(l - e);
      dp[i][k] = min(dp[i][k], dp[i - 1][cl.S] + min(lhe, hle));

      b = a[i - 1][cr.S];
      e = a[i][k];
      lhe = abs(b - l) + h - l + abs(h - e);
      hle = abs(b - h) + h - l + abs(l - e);
      dp[i][k] = min(dp[i][k], dp[i - 1][cr.S] + min(lhe, hle));
    }
    // }
  }

  ll ans = dp[n - 1][0];
  for (int i = 1; i < p; i++)
  {
    ans = min(ans, dp[n - 1][i]);
  }
  return ans;
}

// void stress()
// {

//   random_device dev;
//   mt19937 rng(dev());
//   uniform_int_distribution<std::mt19937::result_type> dist100(1, 100); // distribution in range [1, 6]

//   for (int t = 0; t < 100; t++)
//   {
//     n = 10;
//     for (int i = 0; i < n; i++)
//     {
//       p = 10;
//       for (int j = 0; j < p; j++)
//       {
//         a[i][j] = dist100(rng);
//       }
//     }
//     if (solve() != solve2())
//     {
//       cout << "Wrong" << "\n";
//     }
//     // cout << solve() << " " << solve2() << "\n";
//   }
// }

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // stress();
  int t;
  cin >> t;
  for (int z = 1; z <= t; z++)
  {
    cin >> n >> p;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < p; j++)
      {
        cin >> a[i][j];
      }
    }
    cout << "Case #" << z << ": " << solve() << "\n";
  }
  return 0;
}