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
int a[200001];

vector<int> solve() {
  multiset<int> s;
  for (int i=0;i<k;i++) {
    s.insert(a[i]);
  }
  auto med = next(s.begin(), (k-1)/2);
  vector<int> res(1, *med);
  int r = k;
  while (r < n) {
    auto it = s.lower_bound(a[r-k]);
    s.insert(a[r]);
    if (a[r] >= *med) {
      if (*it <= *med) {
        med++;
      }
    } else {
      if (*it > *med || it == med) {
        med--;
      }
    }
    s.erase(it);
    res.pb(*med);
    //cout << *med << "\n";
    r++;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n >> k;
  for (int i=0;i<n;i++) cin >> a[i];
  vector<int> ans = solve();
  for (int a : ans) {
    cout << a << " ";
  }
  cout << "\n";
  return 0;
}
