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
int a[101];

vector<int> solve() {
  vector<int> ans;
  int m = 1000 * n + 1;
  bool dp[m];
  for (int i=0;i<m;i++) {
    dp[i] = false;
  }
  dp[0] = true;
  for (int i=0;i<n;i++) {
    for (int j=m - 1;j>=a[i];j--) {
      dp[j] = dp[j] || dp[j - a[i]];
    }
  }
  for (int i=1;i<m;i++) {
    if (dp[i]) ans.pb(i);
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  for (int i=0;i<n;i++) cin >> a[i];
  vector<int> ans = solve();
  cout << int(ans.size()) << "\n";
  for (int i=0;i<int(ans.size());i++) {
    cout << ans[i] << (i == int(ans.size()) - 1 ? "\n" : " ");
  }
  return 0;
}
