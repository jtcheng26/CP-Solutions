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
ll a[1001];

struct action {
  int t, i, j;
};

vector<action> solve() {
  vector<action> ans;
  for (int i=0;i<n;i+=2) {
    for (int k=0;k<2;k++) {
      for (int j=0;j<2;j++) {
        action ac;
        ac.t = 2;
        ac.i = i + 1;
        ac.j = i + 2;
        ans.pb(ac);
      }
      action ac;
      ac.t = 1;
      ac.i = i + 1;
      ac.j = i + 2;
      ans.pb(ac);
    }
  }
  return ans;
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
    vector<action> ans = solve();
    cout << int(ans.size()) << "\n";
    for (action a : ans) {
      cout << a.t << " " << a.i << " " << a.j << "\n";
    }
  }
  return 0;
}