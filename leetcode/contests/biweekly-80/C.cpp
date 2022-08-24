#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
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
  bool matchReplacement(string s, string sub, vector<vector<char>> &mappings)
  {
    map<pair<char, char>, bool> m;
    bool ans = false;
    for (vector<char> &c : mappings)
    {
      // cout << c[0] << " " << c[1] << "\n";
      m[make_pair(c[0], c[1])] = true;
    }

    int n = s.length();
    int l = sub.length();
    for (int i = 0; i < n - l + 1; i++)
    {
      bool good = true;
      for (int j = 0; j < l; j++)
      {
        good = good && ((sub[j] == s[i + j]) || (m[make_pair(sub[j], s[i + j])]));
      }
      ans = ans || good;
    }
    return ans;
  }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  // s = "";
  // for (int i = 0; i < 5000; i++)
  //   s += "a";
  string sub = "";
  // for (int i = 0; i < 5000; i++)
  //   sub += "b";
  cin >> sub;
  int n = 1000;
  cin >> n;
  vector<vector<char>> v(n, vector<char>(2));
  for (int i = 0; i < n; i++)
  {
    cin >> v[i][0] >> v[i][1];
    // v[i][0] = (char)('a' + (('a' + i) - 'a') % 26);
    // v[i][1] = (char)('0' + i % 26);
  }
  // v[0][0] = 'b';
  // v[0][1] = 'a';
  // v[1][0] = 'a';
  // v[1][1] = 'b';

  Solution sol;
  cout << sol.matchReplacement(s, sub, v) << "\n";
  return 0;
}
