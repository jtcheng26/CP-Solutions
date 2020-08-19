#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

typedef long long ll;

using namespace std;

ll n;

ll solve() {
  ll ans = pow(2, n);
  ll s = 0;
  for (int i=1;i<(n / 2);i++) {
    ans += pow(2, i);
  }
  for (int j=n / 2;j<n;j++) {
    s += pow(2, j);
  }
  return ans - s;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    cout << solve() << endl;
  }
  return 0;
}
