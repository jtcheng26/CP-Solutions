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
int a[201];

bool solve()
{
  int cnt[2] = {0};
  for (int i = 0; i < 2 * n; i++)
  {
    cnt[a[i] % 2]++;
  }
  return cnt[0] == cnt[1];
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--)
  {
    cin >> n;
    for (int i = 0; i < 2 * n; i++)
    {
      cin >> a[i];
    }
    cout << (solve() ? "Yes" : "No") << "\n";
  }
  return 0;
}