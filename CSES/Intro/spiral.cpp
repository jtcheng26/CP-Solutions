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
#define MOD 1e9+7

typedef long long ll;

using namespace std;

int n;
ll x, y;

ll solve() {
  if (x == y) return x * x - (x - 1);
  if (x > y) {
    if (x % 2 == 1) return x * x - (y - 1);
    else return (x - 1) * (x - 1) + 1 + (y - 1);
  } else {
    if (y % 2 == 0) return y * y - (x - 1);
    else return (y - 1) * (y - 1) + 1 + (x - 1);
  }
  return (x / 2);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> y >> x;
    cout << solve() << "\n";
  }
  return 0;
}
