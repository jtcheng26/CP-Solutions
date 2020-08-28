#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INFI 10000007
#define pb push_back
#define F first
#define S second

typedef long long ll;

using namespace std;

int n, m, k;
int a[101];

int solve() {
  int res = 0;
  int r, l;
  for (r=m - 1;r<n;r++) {
    if (a[r] > 0 && a[r] <= k) break;
  }
  for (l=m - 1;l>=0;l--) {
    if (a[l] > 0 && a[l] <= k) break;
  }
  if (l < 0) l = INFI;
  if (r == n) r = INFI;
  //cout << l << " " << r << endl;
  return 10 * min(abs(r - (m-1)), abs(l - (m-1)));
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> n >> m >> k;
  for (int i=0;i<n;i++) {
    cin >> a[i];
  }
  cout << solve() << endl;
  return 0;
}
