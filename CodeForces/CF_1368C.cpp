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
vector<pair<int, int> > cells;

int solve() {
  int x = 1; int y = 1;
  cells.pb(mp(0, 0));
  for (int i=0;i<=n;i++) {
    cells.pb(mp(x, y));
    cells.pb(mp(x-1, y));
    cells.pb(mp(x, y-1));
    x++;
    y++;
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  solve();
  cout << cells.size() << endl;
  for (int i=0;i<cells.size();i++) {
    cout << cells[i].F << " " << cells[i].S << endl;
  }
  return 0;
}
