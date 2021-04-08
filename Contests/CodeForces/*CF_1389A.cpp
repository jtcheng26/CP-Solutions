#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

typedef long long ll;

using namespace std;

ll n, l, r;

ll solve() {
  ll res = 0;
  if (2 * l <= r) {
    cout << l << " " << 2 * l << endl;
  } else {
    cout << -1 << " " << -1 << endl;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  for (int i=0;i<n;i++) {
    cin >> l >> r;
    solve();
  }
  return 0;
}
