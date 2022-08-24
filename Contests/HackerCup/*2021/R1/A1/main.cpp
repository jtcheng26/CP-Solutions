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
string s;

int solve()
{
  int res = 0;
  char xo = 'F';
  for (int i = 0; i < n; i++)
  {
    if (s[i] != 'F')
    {
      if (xo == 'F')
        xo = s[i];
      else if (xo != s[i])
      {
        res++;
        xo = s[i];
      }
    }
  }
  return res;
}

int main()
{
  int t;
  cin >> t;
  for (int c = 1; c <= t; c++)
  {
    cin >> n;
    cin >> s;
    cout << "Case #" << c << ": " << solve() << "\n";
  }
  return 0;
}