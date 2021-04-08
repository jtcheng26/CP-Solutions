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

ll n, m;

ll lb[101];
ll ub[101];
ll tm[101];

bool solve() {
  ll ltemp = m;
  ll utemp = m;
  ll time = 0;
  bool res = true;
  for (int i=0;i<n;i++) {
    ll dist = abs(tm[i] - time);
    if (ltemp > ub[i]) {
      if (ltemp - ub[i] > dist) return false;
      else {
        utemp = ub[i];
        ltemp = max(lb[i], ub[i] - (dist - (ltemp - ub[i])));
        time = tm[i];
      }
    } else if (utemp < lb[i]) {
      if (lb[i] - utemp > dist) return false;
      else {
        ltemp = lb[i];
        utemp = min(ub[i], lb[i] + (dist - (lb[i] - utemp)));
        time = tm[i];
      }
    } else {
      utemp = min(ub[i], utemp + dist);
      ltemp = max(lb[i], ltemp - dist);
      time = tm[i];
    }
    //cout << ltemp << " " << utemp << endl;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i=0;i<n;i++) {
      cin >> tm[i] >> lb[i] >> ub[i];
    }
    cout << (solve() ? "YES" : "NO") << endl;
  }
  return 0;
}
