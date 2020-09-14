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

int n;
ll a[100001];

ll solve() {
  sort(a, a+n);
  ll res = 0;
  if (a[n-1] * a[n-2] * a[n-3] > a[n-1] * a[0] * a[1]) {
    res = a[n-1] * a[n-2] * a[n-3];
    res = max(res * a[n-4] * a[n-5], res * a[0] * a[1]);
  } else {
    res = a[n-1] * a[0] * a[1];
    res = max(res * a[n-2] * a[n-3], res * a[2] * a[3]);
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    cout << solve() << endl;
  }
  return 0;
}
