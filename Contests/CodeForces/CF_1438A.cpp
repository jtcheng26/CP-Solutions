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

vector<int> solve() {
  vector<int> res;
  for (int i=0;i<n;i++) {
    res.pb(1);
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> ans = solve();
    for (int i=0;i<n;i++) {
      cout << ans[i] << (i == n-1 ? "\n" : " ");
    }
  }
  return 0;
}
