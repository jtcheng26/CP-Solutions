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
int a[200001];
ll pfx[200002];

ll solve() {
  pfx[0] = 0;
  for (int i=1;i<=n;i++) {
    pfx[i] = pfx[i-1] + a[i-1];
  }
  map<ll, vector<int> > last;
  int l = 0;
  int r = 0;
  ll res = 0;
  last[0].pb(0);
  while (r < n) {
    r++;
    while (last[pfx[r]].size() > 0) {
      last[pfx[l]].clear();
      l++;
    }
    last[pfx[r]].pb(r);
    res += r - l;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  for (int i=0;i<n;i++) {
    cin >> a[i];
  }
  cout << solve() << "\n";
  return 0;
}
