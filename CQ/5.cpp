#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>

#define INF 1000000001
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

int n;
vector<pair<ll, ll> > a;
vector<pair<ll, ll> > dist;

vector<int> solve() {
  vector<int> res;
  for (int i=0;i<n;i++) {
    dist.pb(mp(a[i].F * a[i].F + a[i].S * a[i].S, i));
  }
  sort(dist.begin(), dist.end());
  for (int i=0;i<dist.size();i++) {
    res.pb(dist[i].S);
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    a.clear();
    dist.clear();
    cin >> n;
    a.resize(n);
    for (int i=0;i<n;i++) {
      cin >> a[i].F >> a[i].S;
    }
    vector<int> ans = solve();
    for (int i=0;i<ans.size();i++) {
      cout << a[ans[i]].F << " " << a[ans[i]].S << "\n";
    }
  }
  return 0;
}