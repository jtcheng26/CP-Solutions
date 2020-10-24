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

ll x, y, k;

ll solve() {
  ll turns = (y * k + x - 2) / (x - 1);
  ll have = 1 + turns * (x - 1) - (y * k);
  return turns + max((ll)0, (k - have + x - 2) / (x-1)) + k;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> x >> y >> k;
    cout << solve() << endl;
  }
  return 0;
}
