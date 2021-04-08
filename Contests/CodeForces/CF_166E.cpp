#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INFI 1e18+7
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long ll;

using namespace std;

ll n;

ll solve() {
  ll dpd = 1;
  ll dpabc = 0;
  ll dpprev = 0;
  for (int i=1;i<=n;i++) {
    dpabc = (dpd + 2 * dpabc) % MOD;
    if (i == n-1) dpd = 0;
    else dpd = (3 * dpprev) % MOD;
    dpprev = dpabc;
  }
  return dpd % MOD;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  cout << solve() << endl;
  return 0;
}
