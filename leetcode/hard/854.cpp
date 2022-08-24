// Jesus. Took me 5 days and had to pull some shitty 5%/5% bitmask dp out of my ass to AC.
// Really simple problem statement, not a bad problem, I just couldn't wrap my head around it.
// Totally missed the braindead BFS + Skipping duplicate letters. Ugh.
// At least I got some implementation practice. Debugging wasn't a big issue which is nice.
// At least I'll be better next time.
// Still haven't come across a Leetcode I couldn't solve.

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

// class Solution
// {
// public:
//   int v[21] = {0};
//   vector<int> adj[21];
//   bool dfs(int node, int start, int d, int k, int c)
//   {
//     if (d > k)
//       return false;
//     v[node] = c;
//     for (int j : adj[node])
//     {
//       if (j == start && d == k)
//       { // cycle, right len
//         // cout << node << "-";
//         return true;
//       }
//       else if (v[j] != c && (1 & (c >> j)))
//       { // continue
//         if (dfs(j, start, d + 1, k, c))
//         {
//           // cout << node << "-";
//           return true;
//         }
//       }
//     }

//     // v[node] = 0;

//     return false;
//   }
//   int n;
//   vector<int> dp = vector<int>(1 << 20, 20);
//   vector<int> a;
//   vector<int> dp2 = vector<int>(1 << 20, -1);
//   int solve(int k)
//   {
//     if (dp2[k] == -1)
//     {
//       dp2[k] = dp[k];
//     }
//     else
//     {
//       return dp2[k];
//     }
//     for (int m : a)
//     {
//       if (m == k)
//         continue;
//       if ((m | k) == k)
//       {
//         dp2[k] = min(dp2[k], solve(m ^ k) + solve(m));
//       }
//     }
//     return dp2[k];
//   }

//   int kSimilarity(string s1, string s2)
//   {
//     n = s1.length();
//     int ans = 0;
//     string b1 = "";
//     string b2 = "";
//     for (int i = 0; i < n; i++)
//     {
//       if (s1[i] == s2[i])
//       {
//         v[i] = -1;
//         continue;
//       }
//       if (v[i] != -1)
//       {
//         b1 += s1[i];
//         b2 += s2[i];
//       }
//     }
//     n = b1.length();
//     for (int i = 0; i < n; i++)
//     {
//       // cout << i << ": ";
//       for (int j = 0; j < n; j++)
//       {
//         v[i] = v[j] = 0;
//         if (b1[j] == b2[i])
//         {
//           // cout << j << " ";
//           adj[i].push_back(j);
//         }
//       }
//     }
//     // cout << "\n";

//     vector<vector<vector<int>>> d(n + 1, vector<vector<int>>(0));

//     for (int l = 1; l < (1 << n); l++)
//     {
//       int cnt = 0;
//       int k = 0;
//       for (int j = 0; j < n; j++)
//       {
//         if (1 & (l >> j))
//         {
//           cnt++;
//           k = j;
//         }
//       }
//       if (dfs(k, k, 1, cnt, l))
//       {
//         // cout << cnt << " " << l << "\n";
//         dp[l] = cnt - 1;
//         a.push_back(l);
//       }
//     }

//     dp2[0] = 0;

//     // cout << a.size() << "\n";

//     return ans + solve((1 << n) - 1);
//   }
// };

#include <map>

class Solution
{
public:
  int kSimilarity(string s1, string s2)
  {
    int n = s1.length();

    map<string, int> dp;

    queue<string> q;
    string top = s1;
    q.push(top);
    dp[top] = 1;
    int l = 0;
    while (!q.empty())
    {
      // cout << q.size() << "\n";
      // if (q.size() > 10)
      //   break;
      int k = q.size();
      while (k--)
      {
        string top = q.front();
        q.pop();
        if (top == s2)
          return dp[top] - 1;
        int cnt = dp[top];
        int i = l;
        while (top[i] == s2[i])
        {
          i++;
        }
        for (int j = i + 1; j < n; j++)
        {
          if (top[j] == s2[i])
          {
            // cout << i << " " << j << "\n";
            // string temp = top;
            swap(top[i], top[j]);
            // cout << top << "\n";
            if (!dp[top])
            {
              dp[top] = cnt + 1;
              q.push(top);
            }
            swap(top[i], top[j]);
          }
        }
        // if (top[i] == s2[i])
        // {
        //   q.push(top);
        //   continue;
        // }
      }

      // if (top[i] == s2[i])
      //   continue;
      // int cnt = dp[top];

      l++;
    }

    return -1;
  }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string a, b;
  cin >> a;
  cin >> b;
  Solution sol;
  cout << sol.kSimilarity(a, b) << "\n";
  return 0;
}
