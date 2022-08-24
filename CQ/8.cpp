#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <iomanip>

#define INF 1000000001
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

int n, m;
ll a[51][51];

double solve() {
  double res = 0;
  for (int i=0;i<n;i++) {
    for (int j=0;j<m;j++) {
      res += a[i][j] * a[i][j];
    }
  }
  return sqrt(res);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  cout << fixed;
  cout << setprecision(2);
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