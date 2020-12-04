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

struct item {
  ll weight;
  int idx;
};

int n;
ll w;
item a[200001];
vector<int> res;

bool cmp(item a, item b) {
  return a.weight < b.weight;
}

int solve() {
  ll l = (w+1) / 2;
  ll r = w;
  ll cnt = 0;
  sort(a, a+n, cmp);
  if (a[0].weight > w) return -1;
  for (int i=n-1;i>=0;i--) {
    if (a[i].weight <= r) {
      res.pb(a[i].idx);
      cnt += a[i].weight;
      if (a[i].weight >= l) {
        res.clear();
        res.pb(a[i].idx);
        return 1;
      }
      if (cnt >= l && cnt <= r) {
        return res.size();
      }
    }
  }
  return -1;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    res.clear();
    cin >> n >> w;
    for (int i=0;i<n;i++) {
      cin >> a[i].weight;
      a[i].idx = i+1;
    }
    int ans = solve();
    if (ans >= 0) {
      cout << ans << "\n";
      for (int i=0;i<ans;i++) {
        cout << res[i] << (i==ans-1 ? "\n" : " ");
      }
    } else {
      cout << "-1\n";
    }
  }
  return 0;
}
