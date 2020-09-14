#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INFI 1e18+7
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long ll;

using namespace std;

int n;
char path[200001];
pair<int, int> ans;
map<pair<int, int>, int> seen; // first index of coordinate

int solve() {
  int res = 0;
  int x = 0;
  int y = 0;
  vector<pair<int, int> > poss;
  for (int i=0;i<n;i++) {
    if (path[i] == 'L') x--;
    else if (path[i] == 'R') x++;
    else if (path[i] == 'U') y++;
    else y--;
    seen[mp(x, y)] = -1;
    //cout << x << " " << y << endl;
  }
  x = 0;
  y = 0;
  seen[mp(0, 0)] = 0;
  for (int i=0;i<n;i++) {
    if (path[i] == 'L') x--;
    else if (path[i] == 'R') x++;
    else if (path[i] == 'U') y++;
    else y--;
    pair<int, int> p = mp(x, y);
    //cout << seen[p] << " " << i << endl;
    if (seen[p] == -1)
      seen[p] = i + 1;
    else {
      poss.pb(mp(seen[p] + 1, i + 1));
      seen[p] = i + 1;
    }
  }
  if (poss.size() == 0) return -1;
  int minSize = poss[0].S - poss[0].F;
  ans.F = poss[0].F;
  ans.S = poss[0].S;
  for (int i=1;i<poss.size();i++) {
    if (poss[i].S - poss[i].F < minSize) {
      minSize = poss[i].S - poss[i].F;
      ans.F = poss[i].F;
      ans.S = poss[i].S;
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    seen.clear();
    cin >> n;
    for (int i=0;i<n;i++) cin >> path[i];
    int res = solve();
    if (res == -1) cout << "-1" << endl;
    else {
      cout << ans.F << " " << ans.S << endl;
    }
  }
  return 0;
}
