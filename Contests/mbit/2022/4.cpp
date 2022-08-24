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
int a[1006];
vector<string> b[1006];
vector<string> ans;
map<string, bool> used;

void solve()
{
  for (int i = 0; i < n; i++)
  {
    if (b[a[i]].empty())
    {
      string lol = "";
      for (int j = 0; j < a[i]; j++)
      {
        lol += 'a';
      }
      b[a[i]].pb(lol);
      used[lol] = true;
    }
    else
    {
      string last = b[a[i]][b[a[i]].size() - 1];
      string notLast = last;
      for (int j = 0; j < a[i]; j++)
      {
        if (last[j] != 'z')
        {
          notLast[j] = (char)(last[j] + 1);
        }
        else
        {
          notLast[j] = 'a';
        }
        if (!used[notLast])
        {
          used[notLast] = true;
          b[a[i]].pb(notLast);
          break;
        }
      }
    }
    cout << b[a[i]][b[a[i]].size() - 1] << "\n";
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  // n = 1000;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    // a[i] = 3;
  }
  solve();
  // for (string s : ans)
  // {
  //   cout << s << "\n";
  // }
  return 0;
}