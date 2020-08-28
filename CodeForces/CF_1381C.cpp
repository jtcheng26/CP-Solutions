#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INFI 1e18+7
#define pb push_back
#define F first
#define S second

typedef long long ll;

using namespace std;

int n;
int m[4001];
vector<int> subs;

bool solve() {
  if (n == 1) return m[0] < m[1];
  int prev = 2*n;
  int mx = 0;
  while (prev > 0) {
    for (int i=0;i<prev;i++) {
      if (m[i] > m[mx]) mx = i;
    }
    subs.pb(prev - mx);
    //cout << prev - mx << " ";
    prev = mx;
    m[mx] = 0;
  }
  //cout << endl;
  bool dp[2*n+1][2*n+1];
  for (int i=0;i<=subs.size();i++) {
    dp[i][0] = true;
    for (int j=1;j<=2*n;j++) dp[i][j] = false;
  }
  for (int i=1;i<=subs.size();i++) {
    //cout << subs[i] << endl;
    for (int j=0;j<2*n;j++) {
      if (j >= subs[i-1]) {
        dp[i][j] = dp[i-1][j] || dp[i-1][j-subs[i-1]];
      } else dp[i][j] = dp[i-1][j];
    }
    if (dp[i][n]) return true;
  }

  return false;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    subs.clear();
    cin >> n;
    for (int i=0;i<2*n;i++) cin >> m[i];
    cout << (solve() ? "YES" : "NO") << endl;
  }
  return 0;
}
