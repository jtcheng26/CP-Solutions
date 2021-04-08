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

/*
  formula: r[i] = r[i-1] + 2^i * r[i-1] + 2^i
  r[i] = the total arrays with max set bit i (r[0] = 1)
  r[i-1] = existing arrays with the max set bit i-1
  2^i * r[i-1] = the number of numbers with max set bit i multiplied by all existing arrays
  2^i = the number of new arrays of size 1 with max set bit i
*/

int d, m;
int p; // largest power of 2 less than or equal to d
ll twoPow[35]; // power of 2

void precomp() {
  twoPow[0] = 1;
  for (int i=1;i<=30;i++) {
    twoPow[i] = (twoPow[i-1] * 2);
    if (twoPow[i] > d) {
      p = i - 1;
      break;
    }
  }
  for (int i=0;i<=30;i++) {
    twoPow[i] %= m;
  }
}

ll solve() {
  ll res = 1;
  precomp();
  for (int i=1;i<p;i++) {
    res += ((twoPow[i] * res) % m + twoPow[i]) % m;
    res %= m;
  }
  if (p > 0)
    res += (((d - twoPow[p] + 1) * res) % m + d - twoPow[p] + 1) % m;
  return res % m;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> d >> m;
    cout << solve() << endl;
  }
  return 0;
}
