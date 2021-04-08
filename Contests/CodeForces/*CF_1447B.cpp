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

int n, m;
int a[11][11];

int solve() {
  int res = 0;
  int mn = 101;
  int neg = 0;
  bool flag = false;
  for (int i=0;i<n;i++) {
    for (int j=0;j<m;j++) {
      res += abs(a[i][j]);
      mn = min(mn, abs(a[i][j]));
      if (a[i][j] == 0)
        flag = true;
      neg += a[i][j] < 0;
    }
  }
  if (flag)
    return res;
  if (neg % 2 == 1) res -= 2 * mn;
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i=0;i<n;i++) {
      for (int j=0;j<m;j++) {
        cin >> a[i][j];
      }
    }
    cout << solve() << "\n";
  }
  return 0;
}
