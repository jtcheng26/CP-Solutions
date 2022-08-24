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
#define EPSILON 0.00000000001

typedef long long ll;

using namespace std;

int n;
char a[500001];

int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}


vector<int> solve() {
  vector<int> pfx;
  pfx.pb(0);
  for (int i=0;i<n;i++) {
    pfx.pb((a[i] == 'K')+pfx[i]);
  }
  vector<int> dp;
  dp.pb(0);
  dp.pb(1);
  for (int i=2;i<=n;i++) {
    dp.pb(1);
    for (int j=1;j<=sqrt(i);j++) {
      int l = i-j+1;
      int r = i;
      if (i % j == 0) {
        double k = (double)((pfx[r] - pfx[l-1])) / ((double)(r-l+1));
        //cout << r << "\n";
        if (fabs(k - ((double)pfx[l-1]) / (l-1)) < EPSILON) {
          dp[r] = max(dp[r], dp[l-1] + 1);
        }
        l = i-(i/j)+1;
        k = (double)((pfx[r] - pfx[l-1])) / ((double)(r-l+1));
        //cout << r << "\n";
        if (fabs(k - ((double)pfx[l-1]) / (l-1)) < EPSILON) {
          dp[r] = max(dp[r], dp[l-1] + 1);
        }
      }
    }
  }
  return dp;
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
    for (int i : ans) {
      if (i != 0)
        cout << i << " ";
    }
    cout << "\n";
  }
  return 0;
}