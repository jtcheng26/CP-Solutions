#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>

#define INF 1000000001
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

int n, k;
ll a[200001];

vector<ll> solve() {
  if (k == 1) {
    vector<ll> res;
    for (int i=0;i<n;i++) res.pb(0);
    return res;
  }
  multiset<ll> s1;
  multiset<ll> s2;
  ll sum1 = 0;
  ll sum2 = 0;
  multiset<ll> s;
  for (int i=0;i<k;i++) {
    s.insert(a[i]);
  }
  auto it = s.begin();
  for (int i=0;i<k/2;i++) {
    s1.insert(*it);
    sum1 += *it;
    it++;
  }
  it = prev(s.end());
  for (int i=k/2;i<k;i++) {
    s2.insert(*it);
    sum2 += *it;
    it--;
  }
  //cout << sum2 - (s1.size() != s2.size() ? *s2.begin() : 0) - sum1 << "\n";
  vector<ll> res(1, sum2 - (s1.size() < s2.size() ? *s2.begin() : 0) - sum1);
  int r = k;
  while (r < n) {
    //cout << sum1 << " " << sum2 << "\n";
    if (s1.count(a[r-k])) {
      s1.erase(s1.find(a[r-k]));
      sum1 -= a[r-k];
    } else {
      s2.erase(s2.find(a[r-k]));
      sum2 -= a[r-k];
    }
    if (s2.size() > 0 && a[r] >= *s2.begin()) {
      s2.insert(a[r]);
      sum2 += a[r];
    } else {
      s1.insert(a[r]);
      sum1 += a[r];
    }
    if (int(s2.size()) - int(s1.size()) > 1) {
      s1.insert(*s2.begin());
      sum1 += *s2.begin();
      sum2 -= *s2.begin();
      s2.erase(s2.begin());
    } else if (int(s1.size()) - int(s2.size()) > 1) {
      s2.insert(*prev(s1.end()));
      sum2 += *prev(s1.end());
      sum1 -= *prev(s1.end());
      s1.erase(prev(s1.end()));
    }
    ll val = sum2 - sum1;
    if (s1.size() > s2.size())
      val += *prev(s1.end());
    else if (s2.size() > s1.size())
      val -= *s2.begin();
    res.pb(val);
    r++;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n >> k;
  for (int i=0;i<n;i++) cin >> a[i];
  vector<ll> ans = solve();
  for (ll a : ans) {
    cout << a << " ";
  }
  cout << "\n";
  return 0;
}
