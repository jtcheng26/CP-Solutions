#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INF 1000000001
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

int n, k;
double a[101];

ll solve() {
  ll res = 0;
  ll sum = a[0];
  for (int i=1;i<n;i++) {
    double c = (100.0 * a[i]) / sum;
    if (c > k) {
      ll p = ceil(a[i] / (0.01 * k));
      res += p - sum;
      sum = p;
    }
    sum += a[i];
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (int i=0;i<n;i++) cin >> a[i];
    cout << solve() << "\n";
  }
  return 0;
}
