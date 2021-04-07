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

int n, k;

vector<int> solve() {
  vector<int> res;
  if (n % 2 == 0) {
    if ((n - 2) % 4 == 0 || n == 4) {
      res.pb(2);
      res.pb((n-2)/2);
      res.pb((n-2)/2);
    } else {
      res.pb(n/2);
      res.pb(n/4);
      res.pb(n/4);
    }
  } else {
    res.pb(1);
    res.pb((n-1)/2);
    res.pb((n-1)/2);
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    vector<int> ans = solve();
    for (int a : ans) {
      cout << a << " ";
    }
    cout << "\n";
  }
  return 0;
}
