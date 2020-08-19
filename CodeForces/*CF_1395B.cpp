#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INFI 100000007

typedef long long ll;

using namespace std;

int n, m; // l/r - n, u/d - m
int sx, sy;
vector<pair<int, int> > cells;

void solve() {
  int cx = sx; int cy = sy;
  for (int i=cy;i>=0;i--) {
    cy = i;
    int ix = cx;
    for (int j=cx;j>=0;j--) {
      cx = j;
      pair<int, int> p(cx, cy);
      cells.push_back(p);
    }
    for (int j=ix + 1;j<n;j++) {
      cx = j;
      pair<int, int> p(cx, cy);
      cells.push_back(p);
    }
  }
  for (int i=sy + 1;i<m;i++) {
    cy = i;
    int ix = cx;
    for (int j=cx;j>=0;j--) {
      cx = j;
      pair<int, int> p(cx, cy);
      cells.push_back(p);
    }
    for (int j=ix + 1;j<n;j++) {
      cx = j;
      pair<int, int> p(cx, cy);
      cells.push_back(p);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n >> m >> sx >> sy;
  sx -= 1; sy -= 1;
  solve();
  for (int i=0;i<cells.size();i++) {
    cout << cells[i].first + 1 << " " << cells[i].second + 1 << endl;
  }
  return 0;
}
