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

pair<int, int> solve() {
  pair<int, int> res;
  if (n % 2 == 0) {
    res.F = 2;
    res.S = n;
  } else {
    res.F = 2;
    res.S = n - 1;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    pair<int, int> ans = solve();
    cout << ans.F << " " << ans.S << "\n";
  }
  return 0;
}