#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INF 1000000001
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

int n;

vector<int> solve() {
  vector<int> ans;
  vector<int> wins(n+1, 0);
  vector<int> ties(n+1, 0);
  int w = (n - 1) / 2;
  int t = (n - 1) % 2 == 1;
  for (int i=1;i<=n;i++) {
    for (int j=i+1;j<=n;j++) {
      if (wins[i] < w) {
        wins[i]++;
        ans.pb(1);
      } else if (ties[i] < t && ties[j] < t) {
        ties[i]++;
        ties[j]++;
        ans.pb(0);
      } else {
        ans.pb(-1);
      }
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
    vector<int> ans = solve();
    for (int i=0;i<int(ans.size());i++) {
      cout << ans[i] << (i == int(ans.size()) - 1 ? "\n" : " ");
    }
  }
  return 0;
}
