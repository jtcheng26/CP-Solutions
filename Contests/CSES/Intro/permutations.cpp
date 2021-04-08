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
#define MOD 1e9+7

typedef long long ll;

using namespace std;

int n;

vector<int> solve() {
  vector<int> res;
  for (int i=1;i<=n;i+=2) {
    res.pb(i);
  }
  for (int i=2;i<=n;i+=2) {
    res.pb(i);
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  if (n == 1) cout << "1\n";
  else if (n < 4) cout << "NO SOLUTION" << "\n";
  else if (n == 4) cout << "3 1 4 2\n";
  else {
    vector<int> ans = solve();
    for (int i=0;i<ans.size();i++) {
      cout << ans[i] << (i == ans.size() - 1 ? "\n" : " ");
    }
  }
  return 0;
}
