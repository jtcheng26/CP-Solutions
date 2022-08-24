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
  bool strongPasswordCheckerII(string password)
  {
    if (password.length() < 8)
      return false;
    string specials = "!@#$%^&*()-+";
    bool lower = false;
    bool upper = false;
    bool num = false;
    bool special = false;
    bool noadj = true;
    for (int i = 0; i < password.length(); i++)
    {
      if (password[i] - 'a' < 26 && password[i] - 'a' >= 0)
        lower = true;
      if (password[i] - 'A' < 26 && password[i] - 'A' >= 0)
        upper = true;
      if (password[i] - '0' < 10 && password[i] - '0' >= 0)
        num = true;
      if (i > 0 && password[i] == password[i - 1])
        noadj = false;
      for (char c : specials)
      {
        if (password[i] == c)
          special = true;
      }
    }
    return lower && upper && num && special && noadj;
  }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  Solution sol;
  cout << sol.strongPasswordCheckerII(s) << "\n";
  return 0;
}
