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

int n, k;
vector<int> ans;

int solve() {
  int res = 0;
  if (k > n) return false;
  if (n % 2 == 0) {
    if (2 * k <= n) {
      for (int i=0;i<k-1;i++) {
        ans.pb(2);
        n-=2;
      }
      ans.pb(n);
    } else if (k % 2 == 0) {
      for (int i=0;i<k-1;i++) {
        ans.pb(1);
        n-=1;
      }
      ans.pb(n);
    }
  } else {
    if (k % 2 == 0) return false;
    for (int i=0;i<k-1;i++) {
      ans.pb(1);
      n-=1;
    }
    ans.pb(n);
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    ans.clear();
    solve();
    if (ans.size() == 0) cout << "NO" << "\n";
    else {
      cout << "YES" << "\n";
      for (int i=0;i<ans.size();i++) {
        cout << ans[i] << (i == ans.size() - 1 ? "\n" : " ");
      }
    }
  }
  return 0;
}
