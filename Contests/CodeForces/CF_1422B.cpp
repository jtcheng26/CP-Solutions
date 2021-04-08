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
ll a[101][101];

ll solve() {
  ll res = 0;
  for (int i=0;i<n/2;i++) {
    for (int j=0;j<m/2;j++) {
      ll sum[4] = {a[i][j], a[i][m-j-1], a[n-i-1][j], a[n-i-1][m-j-1]};
      sort(sum, sum+4);
      res += sum[3] - sum[0] + sum[2] - sum[1];
    }
  }
  if (n % 2 == 1) {
    for (int j=0;j<m/2;j++)
      res += abs(a[n/2][j] - a[n/2][m-j-1]);
  }
  if (m % 2 == 1) {
    for (int i=0;i<n/2;i++) {
      res += abs(a[i][m/2] - a[n-i-1][m/2]);
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i=0;i<n;i++)
    for (int j=0;j<m;j++)
      cin >> a[i][j];
    cout << solve() << endl;
  }
  return 0;
}
