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
int a[101];
int b[101];

int solve() {
  int pfx[2][101];
  pfx[0][0] = pfx[1][0] = 0;
  int mx[2] = {0};
  for (int i=1;i<=n;i++) {
    pfx[0][i] = a[i-1] + pfx[0][i-1];
    mx[0] = max(mx[0], pfx[0][i]);
  }
  for (int i=1;i<=m;i++) {
    pfx[1][i] = b[i-1] + pfx[1][i-1];
    mx[1] = max(mx[1], pfx[1][i]);
  }
  return mx[0] + mx[1];
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    cin >> m;
    for (int i=0;i<m;i++) cin >> b[i];
    cout << solve() << "\n";
  }
  return 0;
}
