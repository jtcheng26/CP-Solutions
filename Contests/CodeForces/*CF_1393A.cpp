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
  ll res = 2 * (n - n / 2) - ((n - n / 2) - 1);
  if (n % 2 == 1) res -= 1;
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    cout << solve() << endl;
  }
  //cout << solve() << endl;
  return 0;
}
