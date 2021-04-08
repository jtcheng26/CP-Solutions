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
int a[200001];

bool valid(ll ans) {
  ll curr = 0;
  int cnt = 0;
  for (int i=0;i<n;i++) {
    if (a[i] > ans) return false;
  }
  for (int i=0;i<n;i++) {
    if (curr + a[i] <= ans) {
      curr += a[i];
    } else {
      cnt++;
      curr = a[i];
    }
  }
  if (cnt > k - 1) return false;
  return true;
}

ll solve() {
  ll res = 0;
  ll l = 1; ll r = ((ll)n) * ((ll)1000000001);
  while (l < r) {
    ll mid = (l + r) / 2;
    if (valid(mid)) {
      res = mid;
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n >> k;
  for (int i=0;i<n;i++) cin >> a[i];
  cout << solve() << "\n";
  return 0;
}
