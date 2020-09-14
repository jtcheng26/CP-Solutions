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
ll a[100001];
vector<vector<ll> > moves;
vector<pair<int, int> > segments;

int solve() {
  moves.resize(3);
  if (n != 1)
    segments.pb(mp(1, n-1));
  else
    segments.pb(mp(1, n));
  segments.pb(mp(n, n));
  segments.pb(mp(1, n));
  for (int i=0;i<n - 1;i++) {
    if (a[i] % n != 0) {
      ll num = (a[i] % n) * (n-1);
      moves[0].pb(num);
      a[i] += num;
    } else {
      moves[0].pb(0);
    }
  }
  if (n == 1) moves[0].pb(0);
  moves[1].pb(0 - a[n-1]);
  for (int i=0;i<n-1;i++) {
    moves[2].pb(0 - a[i]);
  }
  moves[2].pb(0);
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  for (int i=0;i<n;i++) cin >> a[i];
  solve();
  for (int i=0;i<segments.size();i++) {
    cout << segments[i].F << " " << segments[i].S << endl;
    for (int j=0;j<moves[i].size();j++) {
      cout << moves[i][j] << (j == moves[i].size() - 1 ? "\n" : " ");
    }
  }
  return 0;
}
