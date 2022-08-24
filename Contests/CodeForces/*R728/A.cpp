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

vector<int> solve() {
  vector<int> res;
  for (int i=2;i<=n-1;i+=2) {
    res.pb(i);
    res.pb(i-1);
  }
  if (n % 2 == 1) {
    res.pb(res[res.size()-1]);
    res[n-2] = n;
  } else {
    res.pb(n);
    res.pb(n-1);
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> ans = solve();
    for (int j : ans) {
      cout << j << " ";
    }
    cout << "\n";
  }
  return 0;
}