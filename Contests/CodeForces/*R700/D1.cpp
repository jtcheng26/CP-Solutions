#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INF 1000000001
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

int n;
int a[100001];
vector<int> occ[100001];
int curr[100001];

int solve() {
  int res = 0;
  int x = 0;
  int y = 0;
  for (int i=0;i<n;i++)
    occ[a[i]].pb(i);
  for (int i=0;i<=n;i++) curr[i] = 0;
  for (int i=0;i<n;i++) {
    curr[a[i]]++;
    if (a[i] != x && a[i] != y) {
      if (curr[x] >= occ[x].size())
        y = a[i];
      else if (curr[y] >= occ[y].size())
        x = a[i];
      else if (occ[x][curr[x]] < occ[y][curr[y]])
        x = a[i];
      else
        y = a[i];
      res++;
    } else if (a[i] != x) {
      x = a[i];
      res++;
    } else if (a[i] != y) {
      y = a[i];
      res++;
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  for (int i=0;i<n;i++) cin >> a[i];
  cout << solve() << "\n";
  return 0;
}
