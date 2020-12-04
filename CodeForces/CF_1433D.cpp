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
int a[5001];
vector<pair<int, int> > res;

bool solve() {
  int i;
  for (i=1;i<n;i++) {
    if (a[i] != a[i-1]) break;
  }
  if (i == n) return false;
  vector<int> used;
  used.pb(0);
  for (i=1;i<n;i++) {
    if (a[i] != a[used[0]]) {
      res.pb(mp(1, i+1));
      used.pb(i);
    }
  }
  for (i=1;i<n;i++) {
    if (a[i] == a[used[0]]) {
      for (int j=1;j<used.size();j++) {
        if (a[i] != a[used[j]]) {
          res.pb(mp(i+1, used[j]+1));
          break;
        }
      }
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    res.clear();
    cin >> n;
    for (int i=0;i<n;i++) {
      cin >> a[i];
    }
    bool ans = solve();
    if (ans) {
      cout << "YES\n";
      for (int i=0;i<n-1;i++) {
        cout << res[i].F << " " << res[i].S << "\n";
      }
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
