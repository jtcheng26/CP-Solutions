#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INFI 1e18+7
#define pb push_back
#define F first
#define S second

typedef long long ll;

using namespace std;

int n;
ll a[3];
ll b[3];

ll solve() {
  ll res = 0;
  res = 2 * min(a[2], b[1]);
  a[2] -= (res / 2);
  b[1] -= (res / 2);
  ll rem2 = min(a[2], b[2]);
  b[2] -= rem2;
  a[2] -= rem2;
  ll rem1 = min(a[1], b[1]);
  a[1] -= rem1;
  b[1] -= rem1;
  ll remz = min(a[0], b[2]);
  a[0] -= remz;
  b[2] -= remz;
  remz = min(a[0], b[1]);
  a[0] -= remz;
  b[1] -= remz;
  remz = min(b[0], a[1]);
  a[1] -= remz;
  b[0] -= remz;
  remz = min(b[0], a[2]);
  a[2] -= remz;
  b[0] -= remz;
  res -= 2 * min(a[1], b[2]);
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> a[0] >> a[1] >> a[2];
    cin >> b[0] >> b[1] >> b[2];
    cout << solve() << endl;
  }
  return 0;
}
