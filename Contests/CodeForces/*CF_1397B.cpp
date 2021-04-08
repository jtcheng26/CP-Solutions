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
  ll res = 0;
  sort(a, a+n);
  res += a[0] - 1;
  if (n > 35) {
    for (int i=1;i<n;i++) {
      res += a[i] - 1;
    }
    return res;
  }
  ll minRes = INFI;
  //pow(a[n-1], 1 / (n-1)) + 1
  for (int k=1;k<=pow(a[n-1], (double)1 / (double)(n-1)) + 1;k++) {
    ll r = 0;
    for (int i=1;i<n;i++) {
      r += abs(a[i] - pow(k, i));
    }
    minRes = min(minRes, r);
  }
  res += minRes;
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  for (int i=0;i<n;i++) cin >> a[i];
  cout << solve() << endl;
  return 0;
}
