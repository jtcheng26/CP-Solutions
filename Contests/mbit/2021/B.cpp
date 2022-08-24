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

int n, m;

vector<int> solve() {
  vector<int> res;
  if (n > 9 * m || (n == 0 && m > 1)) {
    res.clear();
    res.pb(-1);
    return res;
  }
  int k = 0;
  for (int i=0;i<m;i++) {
    if (k + 9 <= n) {
      res.pb(9);
      k += 9;
    } else {
      res.pb(n - k);
      k += (n - k);
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n >> m;
  vector<int> ans = solve();
  for (int a : ans) {
    cout << a << "";
  }
  cout << "\n";
  return 0;
}