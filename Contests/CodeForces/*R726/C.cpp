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
int a[200001];

vector<int> solve() {
  vector<int> res;
  sort(a, a+n);
  int dif = INF;
  for (int i=1;i<n;i++) {
    dif = min(dif, a[i] - a[i-1]);
  }
  int l, r;
  for (int i=1;i<n;i++) {
    if (a[i] - a[i-1] == dif) {
      if (i == n-1) {
        l = n-2;
        r = n-1;
        break;
      }
      if (i == 1) {
        l = i-1;
        r = i;
        break;
      }
      l = i-1;
      r = i;
    }
  }
  res.pb(a[l]);
  for (int j=0;j<n;j++) {
    if (j != l && j != r) {
      res.pb(a[j]);
    }
  }
  res.pb(a[r]);
  if (n == 4 && res[1] < res[2] && res[1] < res[0]) {
    swap(res[1], res[2]);
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i=0;i<n;i++) {
      cin >> a[i];
    }
    vector<int> ans = solve();
    for (int j : ans) {
      cout << j << " ";
    }
    cout << "\n";
  }
  return 0;
}