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

int n, m, x;
pair<int, int> rng[101];

int solve() {
  int res = 0;
  int l = x;
  int r = x;
  for (int i=0;i<m;i++) {
    if ((rng[i].F <= r && rng[i].S >= r) || (rng[i].F <= l && rng[i].S >= l)) {
      if (rng[i].F <= l) l = rng[i].F;
      if (rng[i].S >= r) r = rng[i].S;
    }
    else if (rng[i].F >= l && rng[i].S <= r) continue;
    else {
      if (rng[i].F <= x && rng[i].S >= r) {
        l = rng[i].F;
        r = rng[i].S;
      }
    }
    if (x >= l && x <= r) res = max(res, r - l + 1);
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> x >> m;
    for (int i=0;i<m;i++) {
      cin >> rng[i].F >> rng[i].S;
    }
    cout << solve() << endl;
  }
  return 0;
}
