#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INFI 1e18+7
#define pb push_back
#define F first
#define S second

typedef long long ll;

using namespace std;

struct point {
  ll x, y, z;
};

int n;
point pts[2001];
bool deleted[2001];
vector<pair<int, int> > res;

int solve() {
  for (int i=0;i<n;i++) deleted[i] = false;
  for (int i=0;i<n;i++) {
    if (deleted[i]) continue;
    deleted[i] = true;
    int minIdx = -1;
    for (int j=0;j<n;j++) {
      if (!deleted[j]) {
        if (minIdx == -1) {
          minIdx = j;
          continue;
        } else {
          if (min(pts[i].x, pts[minIdx].x) <= pts[j].x
            && pts[j].x <= max(pts[i].x, pts[minIdx].x)
            && min(pts[i].y, pts[minIdx].y) <= pts[j].y
            && pts[j].y <= max(pts[i].y, pts[minIdx].y)
            && min(pts[i].z, pts[minIdx].z) <= pts[j].z
            && pts[j].z <= max(pts[i].z, pts[minIdx].z)
          )
            minIdx = j;
        }
      }
    }
    deleted[minIdx] = true;
    res.pb(make_pair(i, minIdx));
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  for (int i=0;i<n;i++) {
    point p;
    cin >> p.x >> p.y >> p.z;
    pts[i] = p;
  }
  solve();
  for (int i=0;i<n / 2;i++) {
    cout << (res[i].F + 1) <<  " " << (res[i].S + 1) << endl;
  }
  return 0;
}
