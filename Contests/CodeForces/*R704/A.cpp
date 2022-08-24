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
int a[1000];

vector<int> solve() {
  vector<int> b;
  map<int, int> exists;
  for (int i=0;i<n;i++) {
    b.pb(a[i]);
    exists[a[i]] = 1;
  }
  bool good = false;
  while (b.size() < 300 && !good) {
    good = true;
    for (int i=0;i<b.size();i++) {
      for (int j=i+1;j<b.size();j++) {
        if (!exists[abs(b[i] - b[j])]) {
          good = false;
          b.pb(abs(b[i] - b[j]));
          exists[abs(b[i] - b[j])] = true;
          if (b.size() > 300) {
            return vector<int>(0);
          }
        }
      }
    }
  }
  if (b.size() > 300) {
    b.clear();
  }
  return b;
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
    if (ans.empty()) {
      cout << "NO" << "\n";
    } else {
      cout << "YES" << "\n";
      cout << ans.size() << "\n";
      for (int j : ans) {
        cout << j << " ";
      }
      cout << "\n";
    }
  }
  return 0;
}